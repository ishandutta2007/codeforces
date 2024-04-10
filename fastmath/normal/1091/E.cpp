#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e5 + 7;

int n;
int a[MAXN];

inline void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
}

int sum = 0;
int bal[MAXN];

const int INF = 1e18 + 7;

void msort() {
    sort(a, a + n);
    reverse(a, a + n);
}   

int tree[MAXN << 2];

void build(int v, int tl, int tr, int tree[], int a[]) {
    if (tl == tr) {
        tree[v] = a[tl];
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm, tree, a);
    build(v * 2 + 2, tm + 1, tr, tree, a);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}   

int get(int v, int tl, int tr, int l, int r, int tree[]) {
    if (tr < l || r < tl) {
        return -INF;
    }
    if (l <= tl && tr <= r) {
        return tree[v];
    }
    int tm = (tl + tr) >> 1;
    return max(get(v * 2 + 1, tl, tm, l, r, tree), get(v * 2 + 2, tm + 1, tr, l, r, tree));
}   

int pref[MAXN];
int getsum(int l, int r) {
    l = max(l, 0ll);
    r = min(r, n - 1);
    if (r < l) {
        return 0;
    }   
    else {
        return pref[r + 1] - pref[l];
    }   
}   

int getpost(int i) {
    int l = i - 1;
    int r = n;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (i < a[m]) {
            l = m;
        }   
        else {
            r = m;
        }   
    }   
    return (l - i + 1) * i + getsum(r, n - 1);
}   

int f[MAXN];
inline void addf(int i) {
    for (; i < MAXN; i |= (i + 1)) {
        f[i]++;
    }   
}   

inline int getf(int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        ans += f[i];
    }
    return ans;
}

int prefmax[MAXN], postmax[MAXN];
void calc() {
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    for (int i = 0; i <= n; ++i) {
        bal[i] = pref[i] - i * (i - 1) - getpost(i);
    }   
    prefmax[0] = bal[0];
    for (int i = 1; i <= n; ++i) {
        prefmax[i] = max(prefmax[i - 1], bal[i] - i);
    }   
    postmax[n + 1] = -INF;
    int cnt = 0;
    for (int i = n; i >= 0; --i) {
        int delt = 2 * i + 1;
        int nv = bal[i] - delt - (cnt - getf(i));
        postmax[i] = max(postmax[i + 1], nv);
        if (i) {
            addf(a[i]);
            ++cnt;
        }   
    }   
}   

inline void prec() {
    msort();
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    calc();
    build(0, 0, n, tree, bal);
}

bool checkl(int r, int x) {
    //r - n
    //(i + 1) * (i + 2) = 3i + 2
    //i * (i + 1) = i + 1
    //2i + 1
    //max: bal[i] - 2i - 1 + x - cnt([i:n-1]>i)
    int mx = postmax[r] + x;
    return mx <= 0;
}

bool checkr(int r, int x) {
    //0 - r
    //max: bal[i] - min(i, x)
    int mx = max(prefmax[x], get(0, 0, n, x + 1, r, tree) - x);
    return mx <= 0;
}   

inline bool check(int x) {
    if ((sum + x) & 1) {
        return 0;
    }   
    int l = -1;
    int r = n;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (a[m] < x) {
            r = m;
        }   
        else {
            l = m;
        }   
    }   

    return checkl(r, x) && checkr(r, x);
}   

vector <int> ans;
inline void solve() {
    prec();
    for (int i = 0; i <= n; ++i) {
        if (check(i)) {
            ans.push_back(i);
        }   
    }   
}   

inline void print() {
    if (ans.empty()) {
        cout << "-1\n";
    }   
    else {
        for (int e : ans) {
            cout << e << ' ';
        }   
        cout << '\n';
    }   
}   

signed main() {
    #ifdef HOME
        //freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    read();
    solve();
    print();
}