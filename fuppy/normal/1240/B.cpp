#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
 
 
typedef long long ll;
 
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
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { -1,0, 1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// #define mp make_pair
//#define endl '\n'

/*
int n, k;

pll dfs(vector<vector<pii>> &G, int now, int par) {
  vector<pair<pll, ll>> childs;
  rep (i, G[now].size()) {
    int ch = G[now][i].first, w = G[now][i].second;
    if (ch == par) continue;
    childs.push_back(make_pair(dfs(G, ch, now), w));
  }

  if (childs.size() == 0) {
    return pll(0, 0);
  }

  int m = childs.size();
  vll dp(m + 1, vl(m + 1, -inf));
  dp[0][0] = 0;
  rep (i, m) {
    pll ch = childs[i].first;
    ll w = childs[i].second;
    rep (j, m + 1) {
      if (dp[i][j] == -inf) break;
      chmax(dp[i + 1][j + 1], dp[i][j] + ch.first + w);
      chmax(dp[i + 1][j], dp[i][j] + ch.second);
    }
  }

  if (k <= m) {
    return pll(dp[m][k - 1], dp[m][k]);
  }
  else {
    return pll(dp[m][m], dp[m][m]);
  }
}

int main() {
  fio();
  int q;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    vector<vector<pii>> G(n);
    rep (i, n - 1) {
      int u, v, w;
      cin >> u >> v >> w;
      u--; v--;
      G[u].push_back(pii(v, w));
      G[v].push_back(pii(u, w));
    }

    pll res = dfs(G, 0, -1);
    //DEBUG(res);
    //cout << res.second << endl;
    cout << res.second << '\n';
  }

}
//*/

//*
int main() {
  fio();
  int q;
  cin >> q;
  rep (_, q) {
    int n;
    cin >> n;
    vi a(n);
    rep (i, n) {
      cin >> a[i];
      a[i]--;
    }

    vi left(n, -1), right(n, -1);
    rep (i, n) {
      right[a[i]] = i;
    }
    rrep (i, n) {
      left[a[i]] = i;
    }

    vector<pair<int, pii>> xlr;
    rep (i, n) {
      if (left[i] != -1) {
        xlr.push_back({i, pii(left[i], right[i])});
      }
    }

    int m = xlr.size();
    int ma = 0, cnt = 0;
    pii pre = pii(-1, -1);
    rep (i, m) {
      if (pre.second < xlr[i].second.first) {
        cnt++;
        pre = xlr[i].second;
      }
      else {
        chmax(ma, cnt);
        cnt = 1;
        pre = xlr[i].second;
      }
    }
    chmax(ma, cnt);
    cout << m - ma << '\n';
    
    // //DEBUG(m);
    // vi dp(m + 1, inf);
    // dp[0] = -1;
    // rep (i, m) {
    //   int l = xlr[i].second.first, r = xlr[i].second.second;
    //   auto itr = lower_bound(all(dp), r);
    //   int j = itr - dp.begin();
    //   assert(j > 0);
    //   //DEBUG(j);
    //   if (dp[j - 1] <= l) {
    //     dp[j] = r;
    //   }
    // }
    // //DEBUG_VEC(dp);

    // rrep (i, m + 1) {
    //   if (dp[i] != inf) {
    //     cout << m - i << '\n';
    //     break;
    //   }
    // }
    
  }
}
//*/