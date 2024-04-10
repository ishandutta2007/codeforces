//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/
 
#include <bits/stdc++.h>
 
// #include <atcoder/all>
 
using namespace std;
// using namespace atcoder;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
// #define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
void YES(bool t=true) {cout<<(t?"YES":"NO")<<endl;}
void Yes(bool t=true) {cout<<(t?"Yes":"No")<<endl;}
void yes(bool t=true) {cout<<(t?"yes":"no")<<endl;}
void NO(bool t=true) {cout<<(t?"NO":"YES")<<endl;}
void No(bool t=true) {cout<<(t?"No":"Yes")<<endl;}
void no(bool t=true) {cout<<(t?"no":"yes")<<endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
int popcount(ll t) { return __builtin_popcountll(t); }
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
    }
} setup_io;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


int solve1(int n, vi a) {
    rep (i, n) {
        a[i]--;
    }

    vi c(2, n);
    rep (i, n) {
        if (c.size() >= 2) {
            if (c[c.size() - 2] == c[c.size() - 1] and c[c.size() - 1] == a[i]) continue;
        }
        c.push_back(a[i]);
    }
    rep (i, 2) c.push_back(n + 1);

    int start = 0;
    int last_two = -1;
    int ans = 0;
    vector<pii> pp;
    rep (i, (int)c.size() - 1) {
        if (c[i] == c[i + 1]) {
            pp.push_back(pii(i, c[i]));
        }
    }
    DEBUG_VEC(pp);
    rep (i, (int)pp.size() - 1) {
        if (pp[i].second != pp[i + 1].second) {
            int en = pp[i + 1].first + 2;
            int st = pp[i].first + 2;
            ans += en - st;
        }
        else {
            int st = pp[i].first + 2, en = pp[i + 1].first;
            int x = pp[i].second;
            bool out = true;
            for (int i = st; i < en - 1; i++) {
                if (c[i] != x and c[i + 1] != x) out = false;
            }
            en = pp[i + 1].first + 2;
            st = pp[i].first + 2;
            if (out) ans += en - st - 1;
            else ans += en - st;
        }
    }
    ans -= 2;
    return ans;
}

int solve2(int n, vi a) {
    vi c;
    rep (i, n) {
        if (c.size() >= 2) {
            if (c[c.size() - 2] == c[c.size() - 1] and c[c.size() - 1] == a[i]) continue;
        }
        c.push_back(a[i]);
    }
 
    int start = 0;
    int last_two = -1;
    int ans = 0;
    rep (i, (int)c.size()) {
        if (i + 1 < c.size() and c[i] == c[i + 1]) {
            if (i - start >= 2) {
                ans++;
            }
            else if (c[i] != last_two) {
                ans++;
            }
            last_two = c[i];
            start = i + 2;
        }
        else {
            ans++;
        }
    }
    return ans;
}

struct dice {
  mt19937 mt;
  dice() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  // [0, x)
  ll operator()(ll x) { return this->operator()(0, x); }
  // [x, y)
  ll operator()(ll x, ll y) {
    uniform_int_distribution<ll> dist(x, y - 1);
    return dist(mt);
  }
  vi operator()(int n, ll x, ll y) {
    vi res(n);
    for (int i = 0; i < n; i++) res[i] = this->operator()(x, y);
    return res;
  }
} rnd;

signed main() {
    while (true) {
        int n;
        cin >> n;
        vi a(n);
        rep (i, n) {
            cin >> a[i];
        }
        // int n = rnd(1, 10);
        // vi a = rnd(n, 1, n + 1);

        int ans1 = solve1(n, a);
        cout << ans1 << endl;
        return 0;
        // int ans2 = solve2(n, a);
        // if (ans1 != ans2) {
        //     DEBUG(n);
        //     DEBUG_VEC(a);
        //     DEBUG(ans1);
        //     DEBUG(ans2);
        //     return 0;
        // }
        // else {
        //     DEBUG_VEC(a);
        // }
    }
}