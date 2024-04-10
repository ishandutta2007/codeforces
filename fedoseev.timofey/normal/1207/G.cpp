#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int N = 4e5 + 7;
const int K = 19;
 
struct num {
  static const int MA = 1e9 + 7, MB = 1e9 + 9;
 
  int a, b;
 
  num() { }
  num( int x ) : a(x), b(x) { }
  num( int a, int b ) : a(a), b(b) { }
 
  num operator + ( const num &x ) const { return num((a + x.a) % MA, (b + x.b) % MB); }
  num operator - ( const num &x ) const { return num((a + MA - x.a) % MA, (b + MB - x.b) % MB); }
  num operator * ( int x ) const { return num(((ll)a * x) % MA, ((ll)b * x) % MB); }
  num operator * ( const num &x ) const { return num(((ll)a * x.a) % MA, ((ll)b * x.b) % MB); }
  bool operator == ( const num &x ) const { return a == x.a && b == x.b; }
 
  explicit operator ll () const { return (ll)a * MB + b + 1; } // > 0
};
 
#ifdef LOCAL
mt19937 rnd(123);
#else
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#endif
 
num P = ((int)5e8 + rnd() % (int)5e8);
num deg[N];
 
void init() {
    deg[0] = 1;
    for (int i = 1; i < N; ++i) deg[i] = deg[i - 1] * P;
}
 
char a[N];
vector <int> g[N];
 
num h[K][N];
int go[K][N];
int d[N];
 
void dfs(int u, int p = 0) {
    if (u == 0) d[u] = 0;
    else d[u] = d[p] + 1;
    h[0][u] = a[u];
    go[0][u] = p;
    for (int i = 1; i < K; ++i) {
        go[i][u] = go[i - 1][go[i - 1][u]];
        h[i][u] = h[i - 1][u] * deg[1 << (i - 1)] + h[i - 1][go[i - 1][u]];
    }
    for (auto v : g[u]) {
        dfs(v, u);
    }
}
 
char getK(int v, int k) {
    for (int i = 0; i < K; ++i) {
        if (k & (1 << i)) v = go[i][v];
    }
    return a[v];
}
 
bool cmp(int i, int j) {
    int curI = i, curJ = j;
    int l1 = d[i], l2 = d[j];
    int len = 0;
    for (int k = K - 1; k >= 0; --k) {
        if ((1 << k) <= l1 && (1 << k) <= l2) {
            if (h[k][curI] == h[k][curJ]) {
                curI = go[k][curI];
                curJ = go[k][curJ];
                l1 -= (1 << k);
                l2 -= (1 << k);
                len += (1 << k);
            } 
        }
    }
    if (len == d[i]) {
        return len < d[j];
    }
    if (len == d[j]) {
        return false;
    }
    return getK(i, len) < getK(j, len);
}
 
int Len = 0;
num H[N];
string curS;
 
void prepare(string s) {
    H[0] = 1;
    for (int i = 0; i < (int)s.size(); ++i) {
        H[i + 1] = H[i] * P + s[i];
    }
}
 
num get(int l, int len) {
    return H[l + len] - H[l] * deg[len];
}
 
bool cmpLess(int i) {
    int curI = i;
    int uk = 0;
    int len = 0;
    while (curI && uk < Len && a[curI] == curS[uk]) {
        curI = go[0][curI];
        ++uk;
        ++len;
    }
    if (len == d[i]) {
        return len < Len;
    }
    if (len == Len) {
        return false;
    }
    return a[curI] < curS[len];
}
 
bool cmpLessOrEq(int i) {
    int curI = i;
    int uk = 0;
    int len = 0;
    while (curI && uk < Len && a[curI] == curS[uk]) {
        curI = go[0][curI];
        ++uk;
        ++len;
    }
    if (len == d[i]) {
         return true;
    }
    if (len == Len) {
         return true;
    }
    return a[curI] < curS[len];
}
 
int ql[N], qr[N];
vector <int> who[N];
 
int fen[N];
int ans[N];
 
void modify(int i, int val) {
    for (; i < N; i |= i + 1) fen[i] += val;
}
 
int getS(int r) {
    int res = 0;
    for (; r >= 0; r &= r + 1, --r) res += fen[r];
    return res;
}
 
int sum(int l, int r) {
    return getS(r) - getS(l - 1);
}
 
int ord[N];
 
void jhfs(int u) {
    if (u) modify(ord[u], 1);
    for (auto id : who[u]) {
        ans[id] = sum(ql[id], qr[id]);
    }
    for (auto v : g[u]) {
        jhfs(v);
    }
    if (u) modify(ord[u], -1);
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {  
        int t;
        cin >> t;
        if (t == 1) {
            char c;
            cin >> c;
            a[i] = c;
            g[0].push_back(i);
        } else {
            int p; char c;
            cin >> p >> c;
            a[i] = c;
            g[p].push_back(i);
        }
    }
    dfs(0);
    vector <int> p(n);
    for (int i = 1; i <= n; ++i) {
        p[i - 1] = i;
    }
    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < n; ++i) {
        ord[p[i]] = i;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int id; string s;
        cin >> id >> s;
        reverse(s.begin(), s.end());
        curS = s;
        Len = s.size();
        prepare(s);
        int l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (cmpLess(p[m])) l = m;
            else r = m;
        }
        int L = l;
        l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (cmpLessOrEq(p[m])) l = m;
            else r = m;
        }
        int R = l;
        who[id].push_back(i);
        ql[i] = L + 1, qr[i] = R;
    }
    jhfs(0);
    for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
}