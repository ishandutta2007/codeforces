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
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { -1,0, 1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// #define mp make_pair
//#define endl '\n'

#define int ll

struct SegNode
{
  pll v;

  SegNode(pll v) : v(v) {}

  SegNode operator*(const SegNode &r) const
  {
    return (v < r.v ? *this : r);
  }
} e(pll(INF, INF));

struct SegmentTree
{
  int sz;
  vector< SegNode > seg;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, e);
  }

  void update(int k, const SegNode &x)
  {
    k += sz - 1;
    seg[k] = x;
    while(k > 0) {
      k = (k - 1) >> 1;
      seg[k] = seg[2 * k + 1] * seg[2 * k + 2];
    }
  }

  SegNode query(int a, int b, int k, int l, int r)
  {
    if(a >= r || b <= l) return (e);
    if(a <= l && r <= b) return (seg[k]);
    return (query(a, b, 2 * k + 1, l, (l + r) >> 1) * query(a, b, 2 * k + 2, (l + r) >> 1, r));
  }

  SegNode query(int a, int b)
  {
    return (query(a, b, 0, 0, sz));
  }

  int find(int a, int b, int x, int k, int l, int r)
  {
    if(seg[k].v.first > x || r <= a || b <= l) return (-1);
    if(k >= sz - 1) return (k - (sz - 1));
    int lv = find(a, b, x, 2 * k + 1, l, (l + r) >> 1);
    if(lv != -1) return (lv);
    return (find(a, b, x, 2 * k + 2, (l + r) >> 1, r));
  }

  int find(int a, int b, int x)
  {
    return (find(a, b, x, 0, 0, sz));
  }
};

// pll f1(pll a, pll b) {return min(a, b)};
// ll f2(ll a, ll b) {
//   return max(a, b);
// }
// pll f3(pll a, ll b, int l, int r) {
//   if (a.first >= b) {
//     return a;
//   }
//   else {
//     pll res = a;
//     a.first = b;
//   }
// }

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

vl guchoku(ll n, ll p, vl t) {
  vi state(n);
  int time = 0;
  vl ans(n);
  int cnt = 0;
  deque<pii> qu;
  while (cnt < n) {
    if (qu.size() > 0 and qu.front().second == time) {
      pii temp = qu.front();
      qu.pop_front();
      ans[temp.first] = time;
      state[temp.first] = 2;
      cnt++;
    }
    rep (i, n) {
      if (t[i] <= time) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
          if (state[j] == 1) {
            flag = false;
            break;
          }
        }
        if (flag) {
          state[i] = 1;
          if (qu.size() == 0) {
            qu.push_back(pii(i, time + p));
          }
          else {
            qu.push_back(pii(i, qu.back().second + p));
          }
          t[i] = INF;
          break;
        }
      }
    }
    time++;
  }
  return ans;
}

signed main() {
  fio();
  ll n, p;
  cin >> n >> p;
  vl t(n);
  rep (i, n) {
    cin >> t[i];
  }
  //vl t = rnd(n, 0, 2*p);
  //DEBUG_VEC(t);

  vector<pll> temp(n);
  rep (i, n) {
    temp[i].first = t[i];
    temp[i].second = i;
  }

  SegmentTree seg(n + 1);
  rep (i, n) {
    seg.update(i, SegNode(pll(t[i], i)));
  }
  seg.update(n, SegNode(pll(INF, INF)));
  
  vl ans(n);
  int pre = n;
  ll now = 0;
  rep (_, n) {
    pll mi = seg.query(0, pre).v;
    int nex;
    if (mi.first <= now) {
      nex = mi.second;
      now = now + p;
    }
    else {
      int mi_idx = seg.find(pre + 1, n, now);
      if (mi_idx != -1) {
        nex = mi_idx;
        now = now + p;
      }
      else {
        pll mi = seg.query(0, n).v;
        nex = mi.second;
        now = mi.first + p;
      }
    }
    ans[nex] = now;
    seg.update(nex, SegNode(pll(INF, INF)));
    pre = nex;
  }


  //*
  rep (i, n) {
    cout << ans[i] << " ";
  }
  cout << endl;
  //*/
}