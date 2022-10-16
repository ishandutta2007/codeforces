#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


using namespace std;


#include <tuple>


void pr(long long x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


struct state {
    int len, link;
    map<int, int> next;
    long long cst;
    int sn;
};

const int MAXLEN = 600000;
state st[MAXLEN * 2];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(int c, int cst) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].cst = cst;
    st[cur].sn = 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            st[clone].cst = 0;
            st[clone].sn = 0;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int n;
char cs[510000];
string s[110000];
int c[110000];

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", cs);
        s[i] = cs;
    }

    long long ans = 0;
    sa_init();
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);

        //ans = max(ans, (long long)s[i].size() * 1ll * c[i]);
        for (int j = 0; j < s[i].size(); j++) {
            sa_extend(s[i][j], c[i]);
        }
        sa_extend(500+i, 0);
    }

    vector<int> allst(sz-1);
    for (int i = 1; i < sz; i++) allst[i-1] = i;
    sort(allst.begin(),allst.end(), [](int a, int b) {return st[a].len > st[b].len;});

    for (int i : allst) {
        st[st[i].link].cst += st[i].cst;
        st[st[i].link].sn += st[i].sn;
    }

    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < s[i].size(); j++) cur = st[cur].next[s[i][j]];
        if (st[cur].sn == 1) ans = max(ans, (long long)s[i].size() * 1ll * st[cur].cst);
    }

    for (int i = 1; i < sz; i++) {
        if (st[i].sn > 1) ans = max(ans, st[i].len * 1ll * st[i].cst);
    }

    ps(ans);
}


int main() {


    solve();
}


void pr(long long x) { printf("%lld", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}