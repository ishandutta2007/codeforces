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

const int MAXN = 555555;

vl fact(MAXN);
vl rfact(MAXN);

ll mod_pow(ll x, ll p, ll M = MOD) {
  if (p < 0) {
    x = mod_pow(x, M - 2, M);
    p = -p;
  }
  ll a = 1;
  while (p) {
    if (p % 2)
      a = a*x%M;
    x = x*x%M;
    p /= 2;
  }
  return a;
}

ll mod_inverse(ll a, ll M = MOD) {
  return mod_pow(a, M - 2, M);
}

void set_fact(ll n, ll M = MOD) {
  fact[0] = 1;
  for (ll i = 1; i <= n; i++) {
    fact[i] = i * fact[i - 1] % M;
  }
  rfact[n] = mod_inverse(fact[n], M);
  for (ll i = n - 1; i >= 0; i--) {
      rfact[i] = (i + 1) * rfact[i + 1] % M;
  }
}

//http://drken1215.hatenablog.com/entry/2018/06/08/210000
ll nCr(ll n, ll r, ll M = MOD) {
  if (r > n) return 0;
  assert(fact[2] == 2);
  ll ret = fact[n];
  if (rfact[r] == 0) {
    rfact[r] = mod_inverse(fact[r], M);
  }
  ret = (ret*rfact[r]) % M;
  if (rfact[n - r] == 0) {
    rfact[n - r] = mod_inverse(fact[n - r], M);
  }
  ret = (ret*rfact[n - r]) % M;
  return ret;
}

ll nHr(ll n, ll r) {
  return nCr(n+r-1, r);
}

ll solve0(int n, vl c) {
    return 26LL * 26 * mod_pow(25, n - 2) % MOD;
}

int dp1[401][2][2][401];
int sp1[401];

ll solve1(int n, vl c) {
    dp1[2][0][0][0] = 25 * 25;
    dp1[2][1][0][1] = 25;
    dp1[2][0][1][1] = 25;
    dp1[2][1][1][2] = 1;

    for (int i = 2; i < n; i++) {
        rep (j1, 2) rep (j2, 2) {
            rep (k, i + 1) {
                if (dp1[i][j1][j2][k] == 0) continue;

                rep (nj2, 2) {
                    if (j1 == 1 and nj2 == 1) continue;
                    ll mul = 1;
                    if (nj2 == 0) {
                        if (j1 == 0) mul = 24;
                        else mul = 25;
                    }
                    int nk = k + nj2;
                    (dp1[i + 1][j2][nj2][nk] += (ll)dp1[i][j1][j2][k] * mul % MOD) %= MOD;
                }
            }
        }
    }

    rep (i, n + 1) {
        rep (j1, 2) rep (j2, 2) {
            (sp1[i] += dp1[n][j1][j2][i]) %= MOD;
        }
    }

    ll res = 0;
    rep (i, 26) {
        int x = c[i];
        for (int j = x + 1; j <= n; j++) {
            res += sp1[j];
        }
    }
    return res % MOD;
}



int dp2[2][3][3][401][401];
int sp2[401][401];

ll solve2(int n, vl c) {
    rep (i, 3) rep (j, 3) {
        int cnt = 0;
        if (i == 0) cnt++;
        if (j == 0) cnt++;
        int c1 = 0, c2 = 0;
        if (i == 1) c1++;
        if (i == 2) c2++;
        if (j == 1) c1++;
        if (j == 2) c2++;
        ll temp = mod_pow(24, cnt);
        dp2[0][i][j][c1][c2] = temp;
    }

    int s = 0, t = 1;
    for (int i = 2; i < n; i++) {
        rep (j1, 3) rep (j2, 3) {
            rep (k1, i + 1) rep (k2, i + 1) {
                if (k1 + k2 > i + 2) break;
                dp2[t][j1][j2][k1][k2] = 0;
            }
        }

        rep (j1, 3) rep (j2, 3) {
            rep (k1, i + 1) rep (k2, i + 1) {
                if (k1 + k2 > i) break;
                if (dp2[s][j1][j2][k1][k2] == 0) continue;

                rep (nj2, 3) {
                    if (j1 == 1 and nj2 == 1) continue;
                    if (j1 == 2 and nj2 == 2) continue;
                    ll mul = 1;
                    if (nj2 == 0) {
                        if (j1 == 0) mul = 23;
                        else mul = 24;
                    }
                    int nk1 = k1, nk2 = k2;
                    if (nj2 == 1) nk1++;
                    if (nj2 == 2) nk2++;

                    (dp2[t][j2][nj2][nk1][nk2] += (ll)dp2[s][j1][j2][k1][k2] * mul % MOD) %= MOD;
                }
            }
        }
        swap(s, t);
    }

    rep (k1, n + 1) rep (k2, n + 1) {
        rep (j1, 3) rep (j2, 3) {
            (sp2[k1][k2] += dp2[s][j1][j2][k1][k2]) %= MOD;
        }
    }

    ll res = 0;
    rep (i, 26) {
        REP (j, i + 1, 26) {
            int x1 = c[i], x2 = c[j];
            for (int k1 = x1 + 1; k1 <= n; k1++) {
                for (int k2 = x2 + 1; k2 <= n; k2++) {
                    res += sp2[k1][k2];
                }
            }
        }
    }
    return res % MOD;
}


signed main() {
    int n;
    cin >> n;
    vl c(26);
    rep (i, 26) cin >> c[i];

    ll ans0 = solve0(n, c);
    DEBUG(ans0);
    // ll ans1 = solve1(n, c);
    // DEBUG(ans1);
    ll ans2 = solve2(n, c);
    DEBUG(ans2);

    ll ans1 = 0;
    rep (i, 26) {
        int x1 = c[i];
        for (int k1 = x1 + 1; k1 <= n; k1++) {
            for (int k2 = 0; k2 <= n; k2++) {
                ans1 += (ll)sp2[k1][k2];
            }
        }
    }
    ans1 %= MOD;

    ll ans = ans0 - ans1 + ans2;
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << endl;

}