#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
    ll res = 1;
    while (n) {
        if (n & 1)res = res * x % m;
        x = x * x % m; n >>= 1;
    }
    return res;
}
struct modint {
    ll n;
    modint() :n(0) { ; }
    modint(ll m) :n(m) {
        if (n >= mod)n %= mod;
        else if (n < 0)n = (n % mod + mod) % mod;
    }
    operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
    if (n == 0)return modint(1);
    modint res = (a * a) ^ (n / 2);
    if (n % 2)res = res * a;
    return res;
}

ll inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 10;
modint fact[max_n], factinv[max_n];
void init_f() {
    fact[0] = modint(1);
    for (int i = 0; i < max_n - 1; i++) {
        fact[i + 1] = fact[i] * modint(i + 1);
    }
    factinv[max_n - 1] = modint(1) / fact[max_n - 1];
    for (int i = max_n - 2; i >= 0; i--) {
        factinv[i] = factinv[i + 1] * modint(i + 1);
    }
}
modint comb(int a, int b) {
    if (a < 0 || b < 0 || a < b)return 0;
    return fact[a] * factinv[b] * factinv[a - b];
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    bool exi = false;
    rep(i, n)if (a[i] > 0)exi = true;
    vector<vector<int>> G(n);
    rep(i, n - 1) {
        int x, y; cin >> x >> y; x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    if (!exi) {
        cout << 1 << "\n"; return;
    }
    vector<bool> used(n);
    vector<int> trans1(n), trans2(n);
    vector<bool> isonlyzero;
    int tmp = 0;
    int al = 0;
    //ban 2
    fill(all(used), false); tmp = 0;
    rep(i, n) {
        if (a[i]==2)continue;
        if (used[i])continue;
        used[i] = true;
        queue<int> q; q.push(i);
        bool only0 = true;
        //cout << "hello\n";
        while (!q.empty()) {
            int v = q.front(); q.pop();
            //cout << v << "\n";
            if (a[v] > 0)only0 = false;
            trans1[v] = tmp;
            for (int to : G[v])if (!used[to]&&a[to]!=2) {
                q.push(to);
                used[to] = true;
            }
        }
        tmp++;
        isonlyzero.push_back(only0);
    }
    al += tmp;
    //ban 1
    fill(all(used), false);
    rep(i, n) {
        if (a[i] == 1)continue;
        if (used[i])continue;
        bool only0 = true;
        used[i] = true;
        queue<int> q; q.push(i);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            if (a[v] > 0)only0 = false;
            trans2[v] = tmp;
            for (int to : G[v])if (!used[to] && a[to] != 1) {
                q.push(to);
                used[to] = true;
            }
        }
        tmp++;
        isonlyzero.push_back(only0);
    }
    //rep(i, 4)cout << "! "<<trans1[i] << " " << trans2[i] << "\n";
    al = tmp;
    vector<vector<int>> g(al);
    rep(i, n) {
        if (a[i] == 0) {
            int t1 = trans1[i];
            int t2 = trans2[i];
 
            if (!isonlyzero[t1] && !isonlyzero[t2]) {
                g[t1].push_back(t2);
                g[t2].push_back(t1);
            }
        }
        else {
            for (int to : G[i]) {
                if (a[to] > 0 && a[i] != a[to]) {
                    int t1, t2;
                    if (a[i] == 1) {
                        t1 = trans1[i];
                        t2 = trans2[to];
                    }
                    else {
                        t1 = trans1[to];
                        t2 = trans2[i];
                    }
                    //cout << t1 << " " << t2 << "\n";
                    g[t1].push_back(t2);
                    g[t2].push_back(t1);
                }
            }
        }
    }
    int root = -1;
    rep(i, al) {
        if (!isonlyzero[i])root = i;
        sort(all(g[i]));
        g[i].erase(unique(all(g[i])), g[i].end());
    }
    int memo = 0;
    auto mostfar = [&](int x) {
        int tmp = 0;
        vector<bool> used(al, false);
        used[x] = true; queue<int> q; q.push(x);
        int res = 0;
        while (!q.empty()) {
            int len = q.size();
            memo = tmp;
            rep(aa, len) {
                int v = q.front(); q.pop();
                res = v;
                for (int to : g[v])if (!used[to]) {
                    used[to] = true;
                    q.push(to);
                }
            }
            tmp++;
        }
        return res;
    };
    int l = mostfar(root);
    int r = mostfar(l);
    int ans = memo;
    if (ans == 0) {
        cout << 1 << "\n"; return;
    }
    else {
        cout << (ans+1) / 2 + 1 << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << fixed << setprecision(15);
    //init_f();
    //init();
    //expr();
    int t; cin >> t; rep(i, t)
    solve();
    return 0;
}