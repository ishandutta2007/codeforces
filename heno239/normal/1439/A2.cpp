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
    int n, m; cin >> n >> m;
    vector<string> s(n);
    rep(i, n)cin >> s[i];
    vector<vector<P>> vs;
    auto tra = [&](char c)->char {
        if (c == '0')return '1';
        else return '0';
    };
    for (int i = n - 1; i >= 2; i--)for (int j = m - 1; j >= 2; j--) {
        if (s[i][j] == '1') {
            s[i][j] = '0';
            s[i - 1][j] = tra(s[i - 1][j]);
            s[i][j - 1] = tra(s[i][j - 1]);
            vs.push_back({ {i,j},{i - 1,j},{i,j - 1} });
        }
    }
    for (int i = n - 1; i >= 2; i--) {
        vector<P> cur;
        if (s[i][0] == '1')cur.push_back({ i,0 });
        if (s[i][1] == '1')cur.push_back({ i,1 });
        if (cur.size() == 0)continue;
        else if (cur.size() == 1) {
            cur.push_back({ i - 1,0 });
            cur.push_back({ i - 1,1 });
            s[i - 1][0] = tra(s[i - 1][0]);
            s[i - 1][1] = tra(s[i - 1][1]);
        }
        else {
            cur.push_back({ i - 1,0 });
            s[i - 1][0] = tra(s[i - 1][0]);
        }
        vs.push_back(cur);
    }
    for (int j = m - 1; j >= 2; j--) {
        vector<P> cur;
        if (s[0][j] == '1')cur.push_back({ 0,j });
        if (s[1][j] == '1')cur.push_back({ 1,j });
        if (cur.size() == 0)continue;
        rep(i, 2) {
            if (cur.size() == 3)continue;
            s[i][j - 1] = tra(s[i][j-1]);
            cur.push_back({ i,j - 1 });
        }
        vs.push_back(cur);
    }
    while (true) {
        vector<P> v[2];
        rep(i, 2)rep(j, 2)v[s[i][j] - '0'].push_back({ i,j });
        if (v[1].size()==0)break;
        else if (v[1].size()==1) {
            vector<P> nex = { v[1][0],v[0][0],v[0][1] };
            vs.push_back(nex);
            for (P p : nex) {
                s[p.first][p.second] = tra(s[p.first][p.second]);
            }
        }
        else if (v[1].size() == 2) {
            vector<P> nex = { v[0][0],v[0][1],v[1][0] };
            vs.push_back(nex);
            for (P p : nex) {
                s[p.first][p.second] = tra(s[p.first][p.second]);
            }
        }
        else if (v[1].size() == 3) {
            vector<P> nex = { v[1][0],v[1][1],v[1][2] };
            vs.push_back(nex);
            for (P p : nex) {
                s[p.first][p.second] = tra(s[p.first][p.second]);
            }
        }
        else {
            vector<P> nex = { v[1][0],v[1][1],v[1][2] };
            vs.push_back(nex);
            for (P p : nex) {
                s[p.first][p.second] = tra(s[p.first][p.second]);
            }
        }
    }
    cout << vs.size() << "\n"; 
    rep(i, vs.size()) {
        rep(j, 3) {
            if (j > 0)cout << " ";
            cout << vs[i][j].first + 1 << " " << vs[i][j].second + 1;
        }
        cout << "\n";
    }
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