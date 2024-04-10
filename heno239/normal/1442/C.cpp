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

using speP = pair<ll, P>;
ll dist[200000][25];
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n), rG(n);
    rep(i, m) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        rG[b].push_back(a);
    }
    rep(i, n)rep(j, 25)dist[i][j] = INF;
    dist[0][0] = 0;
    priority_queue<speP, vector<speP>, greater<speP>> q;
    q.push({ 0,{0,0} });
    while (!q.empty()) {
        speP p = q.top(); q.pop();
        int v = p.second.first;
        int id = p.second.second;
        if (p.first > dist[v][id])continue;
        for (int to : G[v]) {
            int nid = id;
            if (id%2 == 1)nid++;
            if (nid < 25) {
                if (p.first + 1 < dist[to][nid]) {
                    dist[to][nid] = p.first + 1;
                    q.push({ dist[to][nid],{to,nid} });
                }
            }
        }
        for (int to : rG[v]) {
            int nid = id;
            if (id%2 == 0)nid++;
            if (nid < 25) {
                if (p.first + 1 < dist[to][nid]) {
                    dist[to][nid] = p.first + 1;
                    q.push({ dist[to][nid],{to,nid} });
                }
            }
        }
    }
    ll ans = INF;
    rep(j, 25) {
        ll cost = dist[n - 1][j] + (1 << j) - 1;
        ans = min(ans, cost);
    }
    if (ans < INF) {
        cout << ans << "\n"; return;
    }

    rep(i, n)rep(j, 2)dist[i][j] = INF;
    dist[0][0] = 0;
    q.push({ 0,{0,0} });
    while (!q.empty()) {
        speP p = q.top(); q.pop();
        int v = p.second.first;
        int id = p.second.second;
        if (p.first > dist[v][id])continue;
        for (int to : G[v]) {
            int nid = id;
            ll nd = p.first+1;
            if (id == 1) {
                nid ^= 1; nd += 1000000;
            }
            if (nd < dist[to][nid]) {
                dist[to][nid] = nd;
                q.push({ nd,{to,nid} });
            }
        }
        for (int to : rG[v]) {
            int nid = id;
            ll nd = p.first+1;
            if (id == 0) {
                nid ^= 1; nd += 1000000;
            }
            if (nd < dist[to][nid]) {
                dist[to][nid] = nd;
                q.push({ nd,{to,nid} });
            }
        }
    }
    const int sup = 1000000;
    LP x = { dist[n - 1][0] / sup,dist[n - 1][0] % sup };
    LP y= { dist[n - 1][1] / sup,dist[n - 1][1] % sup };
    LP ansp = min(x, y);
    //cout << ansp.first << " " << ansp.second << "\n";
    modint res = mod_pow(2, ansp.first) - 1 + ansp.second;
    cout << res << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << fixed << setprecision(15);
    //init_f();
    //init();
    //expr();
    //int t; cin >> t; rep(i, t)
    solve();
    return 0;
}