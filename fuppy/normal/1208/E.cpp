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

// update
// addeval,update=+=, -2*INF0
class LazySegmentTree {
public:
  int n;
  vl node, lazy;

  LazySegmentTree(vl a) {
    int _n = a.size();
    n = 1; while (n < _n) n *= 2;
    node.resize(2 * n - 1);
    lazy.resize(2 * n - 1);
    for (int i = 0; i < _n; i++) node[i + n - 1] = a[i];
    for (int i = n - 2; i >= 0; i--) {
      node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }
  }

  // k
  inline void eval(int k, int l, int r) {
    if (lazy[k] != 0) { // Change
      node[k] += (r - l) * lazy[k]; // Change
      if (r - l > 1) {
        lazy[2 * k + 1] += lazy[k]; // Change
        lazy[2 * k + 2] += lazy[k]; //Change
      }
      lazy[k] = 0;
    }
  }

  // [a, b)x
  void add(int a, int b, ll x, int k, int l, int r) {
    // k 
    eval(k, l, r);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy[k] += x; // Change
      eval(k, l, r);
    }
    else {
      add(a, b, x, 2 * k + 1, l, (l + r) / 2);
      add(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = node[2 * k + 1] + node[2 * k + 2];
    }
  }

  ll getsum(int a, int b, int k, int l, int r) {
    eval(k, l, r);
    if (b <= l || r <= a) return 0;
    if (a <= l && r <= b) return node[k];
    ll resl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
    ll resr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
    return resl + resr;
  }
};

vector<pii> cover(vector<pii> lrl, pii zero) {
  vector<pii> res;
  rep (i, lrl.size()) {
    pii lr = lrl[i];
    if (lr.first >= zero.second) {
      res.push_back(lr);
    }
    else if (lr.second <= zero.first) {
      res.push_back(lr);
    }
    else if (zero.first <= lr.first and lr.second <= zero.second) {
      continue;
    }
    else if (lr.first <= zero.first and zero.second <= lr.second) {
      res.push_back(pii(lr.first, zero.first));
      res.push_back(pii(zero.second, lr.second));
    }
    else if (in(lr.first, zero.first, zero.second)) {
      lr.first = zero.second;
      res.push_back(lr);
    }
    if (in(lr.second, zero.first, zero.second)) {
      lr.second = zero.first;
      res.push_back(lr);
    }
  }
  return res;
}

vector<pii> merge_lr(vector<pii> lrl) {
  if (lrl.size() == 0) {
    return lrl;
  }
  sort(all(lrl));
  vector<pii> res;
  rep (i, lrl.size()) {
    pii lr = lrl[i];
    if (res.size() == 0) res.push_back(lr);
    else {
      if (res.back().second >= lr.first) {
        chmax(res[res.size() - 1].second, lr.second);
      }
      else {
        res.push_back(lr);
      }
    }
  }
  return res;
}

int main() {
  fio();
  int q, w;
  cin >> q >> w;
  vl temp(w);
  LazySegmentTree lst(temp);

  using P = pair<ll, pii>;
  priority_queue<P> pq;
  rep (i, q) {
    int n;
    cin >> n;
    rep (j, n) {
      ll x;
      cin >> x;
      pq.push(make_pair(x, pii(j, j + w - n + 1)));
    }
    
    vector<pii> zero;
    if (n <= w / 2) {
      zero.push_back(pii(0, w));
    }
    else {
      zero.push_back(pii(0, w - n));
      zero.push_back(pii(n, w));
    }
    
    set<pii> st;
    while (pq.size() > 0) {
      auto temp = pq.top();
      pq.pop();
      ll x = temp.first;
      pii lr = temp.second;
      //DEBUG(x);
      //DEBUG(lr);
      pii lr2 = lr;
      auto itr = st.lower_bound(lr);
      while (itr != st.end()) {
        int nl = itr->first;
        if (nl >= lr2.second) break;
        else lr2.second = nl;
      }
      itr = st.lower_bound(lr);
      while (itr != st.begin()) {
        itr--;
        int pr = itr->second;
        if (pr <= lr2.first) break;
        else lr2.first = pr;
      }
      //DEBUG(lr2);
      if (x < 0) {
        vector<pii> lr3(1, lr2);
        rep (i, zero.size()) {
          lr3 = cover(lr3, zero[i]);
        }
        lr3 = merge_lr(lr3);
        rep (i, lr3.size()) {
          if (lr3[i].first < lr3[i].second) {
            lst.add(lr3[i].first, lr3[i].second, x, 0, 0, lst.n);
          }
        }
      }
      else {
        if (lr2.first < lr2.second) {
          lst.add(lr2.first, lr2.second, x, 0, 0, lst.n);
        }
      }
      st.insert(lr);
    }

  }
  rep (i, w) {
    cout << lst.getsum(i, i + 1, 0, 0, lst.n) << " ";
  }
  cout << endl;

}