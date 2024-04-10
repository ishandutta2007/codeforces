#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>
#define x first
#define y second

 
using namespace std;
 

const int INF = int(1e9);
const int MAXN = 100100, L = 500100;
int k;
char buf[L];
string a[MAXN];
int c[MAXN];

 
inline bool read() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        scanf("%s", buf);
        a[i] = string(buf);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &c[i]);
    }
    return true;
}
 

struct node {
    int l, r;
    int parent, link;
    map<int, int> next;
    node(int l = 0, int r = 0, int parent = 0): l(l), r(r), parent(parent) {
        link = -1;
        next.clear();
    }
};


struct state {
    int v, pos;
    state(int v = 0, int pos = 0): v(v), pos(pos) { }
};


const int MAXM = 1000 * 1000 + 3;
int n;
int s[MAXM];
int tsz = 1;
node t[2 * MAXM];
state ptr;


inline int len(int v) { 
    return t[v].r - t[v].l; 
}


inline int split(state st) {
    if (st.pos == 0) {
        return t[st.v].parent;
    }
    if (st.pos == len(st.v)) {
        return st.v;
    }
    int cur = tsz++;
    t[cur] = node(t[st.v].l, t[st.v].l + st.pos, t[st.v].parent);
    t[cur].next[s[t[st.v].l + st.pos]] = st.v;
    t[t[st.v].parent].next[s[t[st.v].l]] = cur;
    t[st.v].parent = cur;
    t[st.v].l += st.pos;
    return cur;
}


state go(state st, int l, int r) {
    while (l < r) {
        if (st.pos == len(st.v)) {
            if (!t[st.v].next.count(s[l])) {
                return state(-1, -1);
            }
            st = state(t[st.v].next[s[l]], 0);
        }
        else {
            if (s[t[st.v].l + st.pos] != s[l]) {
                return state(-1, -1);
            }
            int d = min(len(st.v) - st.pos, r - l);
            l += d;
            st.pos += d;
        }
    }
    return st;
}


int link(int v) {
    int& ans = t[v].link;
    if (ans != -1) {
        return ans;
    }
    if (v == 0) {
        return ans = 0;
    }
    int p = t[v].parent;
    return ans = split(go(state(link(p), len(link(p))), t[v].l + (p == 0), t[v].r));
}


inline void treeExtand(int i) {
    while (true) {
        state next = go(ptr, i, i + 1);
        if (next.v != -1) {
            ptr = next;
            break;
        }
        int mid = split(ptr), cur = tsz++;
        t[cur] = node(i, n, mid);
        t[mid].next[s[i]] = cur;
        if (mid == 0) {
            break;
        }
        ptr = state(link(mid), len(link(mid)));
    }
}

 
long long ans;
set<pair<int, int>> pos;

 
long long dfs(int v, int len) {
    long long sum = 0;
    auto it = pos.lower_bound(make_pair(t[v].l, -INF));
    if (it != pos.end() && it->x < t[v].r) {
        sum += it->y;
        if (it->x > t[v].l) {
            len += it->x - t[v].l;
            ans = max(ans, len * sum);
        }
        return sum;
    }
    len += t[v].r - t[v].l;
    for (auto nt : t[v].next) {
        sum += dfs(nt.y, len);
    }
    ans = max(ans, len * sum);
    return sum;
}

 

inline void solve() {
    n = 0;
    pos.clear();
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < (int)a[i].size(); j++) {
            s[n++] = int(a[i][j]);
        }
        pos.insert(make_pair(n, c[i]));
        s[n++] = 228 + i;
    }
    for (int i = 0; i < tsz; i++) {
        t[i] = node();
    }
    ptr = state();
    tsz = 1;
    for (int i = 0; i < n; i++) {
        treeExtand(i);
    }
    ans = 0;
    dfs(0, 0);
    cout << ans << endl;
}
 

int main() {
    read();
    solve();
    return 0;
}