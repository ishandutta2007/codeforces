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


void solve() {
    int n; cin >> n;
    vector<int> l(n); rep(i, n)cin >> l[i];
    int m; cin >> m;
    vector<int> r(m); rep(i, m)cin >> r[i];
    if (n != m) {
        cout << "No\n"; return;
    }
    int sum = 0;
    rep(i, n)sum += l[i];
    if (sum % 2) {
        cout << "No\n"; return;
    }
    sum /= 2;
    vector<int> pre(sum + 1,-1);
    pre[0] = 0;
    vector<int> memo(sum + 1, -1);
    rep(j, n)per(i, sum) {
        if (pre[i] < 0)continue;
        if (i + l[j] <= sum && pre[i + l[j]] < 0)pre[i + l[j]] = i, memo[i + l[j]] = j;

    }
    if (pre[sum] < 0) {
        cout << "No\n"; return;
    }
    vector<bool> usel(n, false);
    int cur = sum;
    while (cur > 0) {
        //cout << "nande " << cur << "\n";
        usel[memo[cur]] = true;
        cur = pre[cur];
    }

    sum = 0;
    rep(i, n)sum += r[i];
    if (sum % 2) {
        cout << "No\n"; return;
    }
    sum /= 2;
    pre.clear(); memo.clear();
    pre.resize(sum + 1, -1);
    pre[0] = 0;
    memo.resize(sum + 1, -1);
    rep(j, n)per(i, sum) {
        if (pre[i] < 0)continue; 
        if (i + r[j] <= sum && pre[i + r[j]] < 0)pre[i + r[j]] = i, memo[i + r[j]] = j;

    }
    if (pre[sum] < 0) {
        cout << "No\n"; return;
    }
    vector<bool> user(n, false);
    cur = sum;
    while (cur > 0) {
        user[memo[cur]] = true;
        cur = pre[cur];
    }
    vector<int> xpos, xneg, ypos, yneg;
    rep(i, n) {
        if (usel[i])xpos.push_back(l[i]);
        else xneg.push_back(l[i]);
        if (user[i])ypos.push_back(r[i]);
        else yneg.push_back(r[i]);
    }
    //cout << "!?!/ " << xpos.size() << " " << xneg.size() << "\n";
    if (xpos.size() > xneg.size())swap(xpos, xneg);
    if (ypos.size() < yneg.size())swap(ypos, yneg);
    sort(all(xpos),greater<int>());
    rep(i, xneg.size()) {
        xneg[i] *= -1;
    }
    sort(all(xneg));
    sort(all(ypos));
    rep(i, yneg.size()) {
        yneg[i] *= -1;
    }
    sort(all(yneg),greater<int>());
    vector<int> vx, vy;
    for (int val : xpos)vx.push_back(val);
    for (int val : xneg)vx.push_back(val);
    for (int val : ypos)vy.push_back(val);
    for (int val : yneg)vy.push_back(val);
    int cx = 0, cy = 0;
    vector<P> ans;
    rep(i, n) {
        cx += vx[i];
        ans.push_back({ cx,cy });
        cy += vy[i];
        ans.push_back({ cx,cy });
    }
    cout << "Yes\n";
    rep(i, 2*n) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << fixed << setprecision(15);
    init_f();
    //init();
    //expr();
    int t; cin >> t; rep(i, t)
    solve();
    return 0;
}