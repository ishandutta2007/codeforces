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
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

ll guchoku(int n, vl a) {
    ll ans = 0;
    rep (i, 1 << n) {
        // string s;
        vi c, p;
        rep (j, n) {
            if (i & (1 << j)) {
                c.push_back(j);
                // s += 'C';
            }
            else {
                p.push_back(j);
                // s += 'P';
            }
        }
        bool flag = true;
        int ma = -inf;
        rep (j, (int)c.size() - 1) {
            if (c[j + 1] - c[j] < ma) flag = false;
            ma = c[j + 1] - c[j];
        }
        int mi = inf;
        rep (j, (int)p.size() - 1) {
            if (p[j + 1] - p[j] > mi) flag = false;
            mi = p[j + 1] - p[j];
        }

        if (flag) {
            ll cc = 0, pp = 0;
            rep (j, n) {
                if (i & (1 << j)) cc += a[j];
                else pp += a[j];
            }
            if (cc < pp) {
                ans++;
            }
        }
    }
    return ans;
}

const int N = 211111;
ll sum1[N];
ll sum[N];

ll calc(vl& a, ll off) {
    int n = a.size();
    rep (i, n) {
        sum[i + 1] = sum[i] + a[i];
        if (i % 2 == 0) {
            sum1[i + 1] = sum1[i] + a[i];
        }
        else {
            sum1[i + 1] = sum1[i] - a[i];
        }
    }

    ll ans = 0;
    int OK;
    ll score;
    for (int i = 1; i < n; i += 2) {
        ll max_add = -sum[i] + (sum[n] - sum[i]);
        if (max_add + off <= 0) continue;
        if (i == 1) {
            int ok = 0;
            int pc = n - i - 1;
            int ma = pc / 2;
            int ng = ma + 1;
            while (ok + 1 < ng) {
                int mid = (ok + ng) / 2;
                ll add = -sum[i];
                if (i % 2 == 0) {
                    add += sum1[i + 2 * mid] - sum1[i];
                }
                else {
                    add += -(sum1[i + 2 * mid] - sum1[i]);
                }
                add += sum[n] - sum[i + 2 * mid];

                if (add + off <= 0) ng = mid;
                else ok = mid;
            }
            ans += ok + 1;
            OK = ok;
        }
        else {
            OK--;
            while (OK >= 0) {
                ll add = -sum[i];
                if (i % 2 == 0) {
                    add += sum1[i + 2 * OK] - sum1[i];
                }
                else {
                    add += -(sum1[i + 2 * OK] - sum1[i]);
                }
                add += sum[n] - sum[i + 2 * OK];

                if (add + off <= 0) OK--;
                else break;
            }
            if (OK < 0) break;
            ans += OK + 1;
        }
    }

    for (int i = 2; i < n; i += 2) {
        ll max_add = -sum[i] + (sum[n] - sum[i]);
        if (max_add + off <= 0) continue;
        if (i == 2) {
            int ok = 0;
            int pc = n - i - 1;
            int ma = pc / 2;
            int ng = ma + 1;
            while (ok + 1 < ng) {
                int mid = (ok + ng) / 2;
                ll add = -sum[i];
                if (i % 2 == 0) {
                    add += sum1[i + 2 * mid] - sum1[i];
                }
                else {
                    add += -(sum1[i + 2 * mid] - sum1[i]);
                }
                add += sum[n] - sum[i + 2 * mid];

                if (add + off <= 0) ng = mid;
                else ok = mid;
            }
            ans += ok + 1;
            OK = ok;
        }
        else {
            OK--;
            while (OK >= 0) {
                ll add = -sum[i];
                if (i % 2 == 0) {
                    add += sum1[i + 2 * OK] - sum1[i];
                }
                else {
                    add += -(sum1[i + 2 * OK] - sum1[i]);
                }
                add += sum[n] - sum[i + 2 * OK];

                if (add + off <= 0) OK--;
                else break;
            }
            if (OK < 0) break;
            ans += OK + 1;
        }
    }
    return ans % MOD;
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
  vl operator()(int n, ll x, ll y) {
    vl res(n);
    for (int i = 0; i < n; i++) res[i] = this->operator()(x, y);
    return res;
  }
} rnd;

void solve() {
    int n;
    cin >> n;
    // n = rnd(11, 15);
    vl a(n);
    rep (i, n) cin >> a[i];
    // rep (i, n) a[i] = rnd(1, 10);

    if (n <= 6) {
        ll ans = guchoku(n, a);
        cout << ans << endl;
        return;
    }

    ll ans = 0;
    rep (p, 2) {
        rep (c, 2) {
            int start;
            ll off;
            if (p == 0) {
                start = 0;
                off = 0;
            }
            else {
                start = 1;
                off = a[0];
            }

            int end;
            if (c == 0) {
                end = n;
            }
            else {
                end = n - 1;
                off -= a[n - 1];
            }

            vl b;
            REP (i, start, end) b.push_back(a[i]);
            ans += calc(b, off);
        }
    }

    vl sum(n + 1);
    rep (i, n) {
        sum[i + 1] = sum[i] + a[i];
    }
    rep (i, n + 1) {
        ll pp = sum[i], cc = sum[n] - sum[i];
        if (pp > cc) ans++;
    }

    cout << ans % MOD << endl;

    // ll ans2 = guchoku(n, a);
    // assert(ans == ans2);
}




signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}