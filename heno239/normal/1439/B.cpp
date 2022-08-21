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
constexpr ll mod = 1000000007;
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
typedef double ld;
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

const int max_n = 1 << 18;
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



void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> G(n);
    rep(i, m) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b); G[b].push_back(a);
    }
    ll inf = (ll)k * (k - 1) / 2;
    if (m < inf) {
        cout << -1 << "\n"; return;
    }
    //subset
    vector<int> cnt(n);
    queue<int> q; vector<bool> used(n);
    rep(i, n) {
        cnt[i] = G[i].size();
        if (cnt[i] < k) {
            used[i] = true; q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int to : G[v]) {
            cnt[to]--;
            if (!used[to] && cnt[to] < k) {
                q.push(to); used[to] = true;
            }
        }
    }
    vector<int> vs;
    rep(i, n)if (!used[i])vs.push_back(i);
    if (vs.size()) {
        cout << 1 << " " << vs.size() << "\n";
        rep(i, vs.size()) {
            if (i > 0)cout << " ";
            cout << vs[i]+1;
        }
        cout << "\n";
        return;
    }

    fill(all(used), false);
    priority_queue<P, vector<P>, greater<P>> que;
    rep(i, n) {
        sort(all(G[i]));
        cnt[i] = G[i].size();
        que.push({ cnt[i],i });
    }
    vector<int> ids;
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (cnt[v] != p.first)continue;
        used[v] = true;
        if (cnt[v] < k - 1) {
            for (int to : G[v]) {
                if (!used[to]) {
                    cnt[to]--;
                    que.push({ cnt[to],to });
                }
            }
        }
        else if (cnt[v] == k - 1) {
            ids.clear();
            ids.push_back(v);
            for (int to : G[v])if (!used[to])ids.push_back(to);
            //
            bool valid = true;
            for (int x = 1; x < ids.size(); x++){
                for (int y = x + 1; y < ids.size(); y++) {
                    int id = lower_bound(all(G[ids[x]]), ids[y]) - G[ids[x]].begin();
                    if (id == G[ids[x]].size() || G[ids[x]][id] != ids[y]) {
                        valid = false; break;
                    }
                }
                if (!valid)break;
            }
            if (valid) {
                cout << 2 << "\n";
                rep(i, k) {
                    if (i > 0)cout << " ";
                    cout << ids[i]+1;
                }
                cout << "\n"; return;
            }
            else {
                for (int to : G[v]) {
                    if (!used[to]) {
                        cnt[to]--;
                        que.push({ cnt[to],to });
                    }
                }
            }
        }
        else break;
    }
    cout << -1 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(15);
     //init_f();
     //init();
     //expr();
     int t; cin >> t; rep(i, t)
    solve();
    return 0;
}