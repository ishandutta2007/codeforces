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

const int max_n = 1 << 19;
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

struct edge {
    int to, cost;
};
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> c(n);
    rep(i, n) {
        cin >> c[i]; c[i]--;
    }

    vector<vector<int>> ids(k);
    rep(i, n)ids[c[i]].push_back(i);

    vector<vector<int>> G(n);
    rep(i, m) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> valid(k);
    vector<vector<int>> col;
    vector<int> trans(n);
    vector<int> loc(n);
    vector<int> co(n);
    rep(i, k) {
        valid[i] = true;
        sort(all(ids[i]));
        rep(j, ids[i].size())trans[ids[i][j]] = j;
        vector<bool> used(ids[i].size(), false);
        vector<int> col(ids[i].size());
        int tmp = 0;
        rep(j, ids[i].size())if (!used[j]) {
            queue<int> q;
            q.push(j);
            col[j] = 0;
            used[j] = true;
            while (!q.empty()) {
                int v = q.front(); q.pop();
                int tv = ids[i][v];
                co[tv] = col[v];
                loc[tv] = tmp;
                for (int tto : G[tv])if (c[tto] == i) {
                    int to = trans[tto];
                    if (used[to]) {
                        if (col[to] != col[v] ^ 1)valid[i] = false;
                    }
                    else {
                        used[to] = true;
                        col[to] = col[v] ^ 1;
                        q.push(to);
                    }
                }
            }
            tmp++;
        }
    }
    ll ans = 0;
    vector<vector<edge>> g;
    vector<P> vl, vr;
    vector<int> vs;
    vector<int> memo;
    vector<bool> used;
    int c0 = 0;
    rep(i, k)if (!valid[i])c0++;
    rep(i, k){
        if (!valid[i]) {
            c0--; continue;
        }
        vector<pair<int, P>> es;
        rep(j, ids[i].size()) {
            for (int to : G[ids[i][j]]) {
                if (c[to] > i) {
                    es.push_back({ c[to],{ids[i][j],to} });
                }
            }
        }
        sort(all(es));
        int ccnt = 0;
        rep(j, es.size()) {
            if (!valid[es[j].first]) {
                continue;
            }
            ccnt++;
            int le = j;
            while (j + 1 < es.size() && es[j].first == es[j + 1].first)j++;
            g.clear();
            vl.clear(); vr.clear();
            for (int l = le; l <= j; l++) {
                int x = es[l].second.first;
                int y = es[l].second.second;
                vl.push_back({ loc[x],x });
                vr.push_back({ loc[y],y });
            }
            sort(all(vl)); vl.erase(unique(all(vl)),vl.end());
            sort(all(vr)); vr.erase(unique(all(vr)),vr.end());
            g.resize(vl.size() + vr.size());
            vs.resize(vl.size() + vr.size());
            int cur = 0;
            for (P p : vl)vs[cur++] = p.second;
            for (P p : vr)vs[cur++] = p.second;
            sort(all(vs));
            auto calc = [&](int v) {
                return lower_bound(all(vs), v) - vs.begin();
            };
            rep(l, vl.size()) {
                if (l > 0 && vl[l - 1].first == vl[l].first) {
                    int x =calc(vl[l - 1].second);
                    int y = calc(vl[l].second);
                    int cost = co[vl[l - 1].second] ^ co[vl[l].second];
                    g[x].push_back({ y,cost });
                    g[y].push_back({ x,cost });
                }
            }
            rep(l, vr.size()) {
                if (l > 0 && vr[l - 1].first == vr[l].first) {
                    int x = calc(vr[l - 1].second);
                    int y = calc(vr[l].second);
                    int cost = co[vr[l - 1].second] ^ co[vr[l].second];
                    g[x].push_back({ y,cost });
                    g[y].push_back({ x,cost });
                }
            }

            for (int l = le; l <= j; l++) {
                int x = calc(es[l].second.first);
                int y = calc(es[l].second.second);
                g[x].push_back({ y,1});
                g[y].push_back({ x,1 });
            }
            memo.clear(); memo.resize(g.size());
            used.clear(); used.resize(g.size());
            bool val = true;
            rep(l, g.size())if (!used[l]) {
                queue<int> q;
                q.push(l); used[l] = true; memo[l] = 0;
                while (!q.empty()) {
                    int z = q.front(); q.pop();
                    for (edge e : g[z]) {
                        if (used[e.to]) {
                            if (memo[e.to] != memo[z] ^ e.cost)val = false;
                        }
                        else {
                            memo[e.to] = memo[z] ^ e.cost;
                            used[e.to] = true;
                            q.push(e.to);
                        }
                    }
                }
            }
            if (val)ans++;
        }
        ans += k - 1 - i - ccnt-c0;
        //cout << i << " " << ans<<"\n";
        //cout << k - 1 - i - ccnt - c0 << "\n";
        //cout << ccnt << " " << c0 << "\n";
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << fixed << setprecision(15);
    init_f();
    //init();
    //expr();
    //int t; cin >> t; rep(i, t)
    solve();
    return 0;
}