#include <bits/stdc++.h>

using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
#define int ll
 
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
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'



template <typename T1, typename T2>
class LazySegmentTree {
public:
  using F = function<T1(T1&, T1&)>; // query_func
  using G = function<T2(T2&, T2&)>; // update_func
  using H = function<T1(T1&, T2&, int, int)>; // lazy to node (node, lazy, left, right)
  int n;
  vector<T1> node;
  vector<T2> lazy;
  T1 e1;
  T2 e2;
  F query_func;
  G update_func;
  H eval_func;

  LazySegmentTree(vector<T1> a, F query_func, G update_func, H eval_func, T1 e1, T2 e2)
    :query_func(query_func), update_func(update_func), eval_func(eval_func), e1(e1), e2(e2)
  {
    int _n = a.size();
    n = 1; while (n < _n) n *= 2;
    node.resize(2 * n - 1, e1);
    lazy.resize(2 * n - 1, e2);
    for (int i = 0; i < _n; i++) node[i + n - 1] = a[i];
    for (int i = n - 2; i >= 0; i--) {
      node[i] = query_func(node[i * 2 + 1], node[i * 2 + 2]);
    }
  }

  // km[hx]s
  inline void eval(int k, int l, int r) {
    if (lazy[k] != e2) { // Change
      node[k] = eval_func(node[k], lazy[k], l, r);
      if (r - l > 1) {
        lazy[2 * k + 1] = update_func(lazy[2*k + 1], lazy[k]);
        lazy[2 * k + 2] = update_func(lazy[2*k + 2], lazy[k]);
      }
      lazy[k] = e2; // Change
    }
  }

  // [a, b)x
  void update(int a, int b, T2 x, int k, int l, int r) {
    // k m[hx]s
    eval(k, l, r);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy[k] = update_func(lazy[k], x);
      eval(k, l, r);
    }
    else {
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = query_func(node[2 * k + 1], node[2 * k + 2]);
    }
  }

  T1 query(int a, int b, int k, int l, int r) {
    eval(k, l, r);
    if (b <= l || r <= a) return e1;
    if (a <= l && r <= b) return node[k];
    T1 resl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    T1 resr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return query_func(resl, resr);
  }
};

int f(int a, int b) {return max(a, b);}
int g(int a, int b) {return a + b;}
int h(int a, int b, int l, int r) {return a + b;}

void solve() {
    int n;
    cin >> n;
    set<int> st;
    st.insert(0);
    vector<vector<pii>> a(2);
    rep (i, n) {
        int l, r, t;
        cin >> l >> r >> t;
        r++;
        t--;
        a[t].push_back(pii(l, r));
        st.insert(l); st.insert(r);
    }

    map<int, int> mp;
    int cnt = 0;
    for (auto itr = st.begin(); itr != st.end(); itr++) mp[*itr] = cnt++;

    rep (i, 2) {
        rep (j, a[i].size()) {
            a[i][j].first = mp[a[i][j].first];
            a[i][j].second = mp[a[i][j].second];
        }
    }

    vector<vii> r2l(2, vii(cnt));
    rep (i, 2) {
        rep (j, a[i].size()) {
            r2l[i][a[i][j].second].push_back(a[i][j].first);
        }
    }

    vector<LazySegmentTree<int, int>> dp;
    rep (i, 2) {
        dp.push_back(
            LazySegmentTree<int, int>(vi(cnt), f, g, h, -inf, 0)
        );
    }

    rep (i, cnt) {
        rep (j, 2) {
            int r = i;
            for (int l: r2l[j][r]) {
                dp[1 - j].update(0, l + 1, 1, 0, 0, dp[1 - j].n);
            }
            ll ans = dp[1 - j].query(0, i, 0, 0, dp[1 - j].n);
            if (ans > 0) {
                dp[j].update(i, i + 1, ans, 0, 0, dp[j].n);
            }
        }
    }

    ll ans = max(dp[0].query(0, cnt, 0, 0, dp[0].n), dp[1].query(0, cnt, 0, 0, dp[1].n));
    cout << ans << endl;
}

// ll inter(pii lr1, pii lr2) {
//     if (lr2 < lr1) swap(lr1, lr2);
//     if (lr1.second <= lr2.first) return 0;
//     else {
//         int l = max(lr1.first, lr2.first);
//         int r = min(lr1.second, lr2.second);
//         return r - l;
//     }
// }

// void solve() {
//     ll n, k;
//     cin >> n >> k;
//     vector<pii> lr(2);
//     rep (i, 2) {
//         cin >> lr[i].first >> lr[i].second;
//     }
//     if (lr[0] > lr[1]) swap(lr[0], lr[1]);

//     ll ans = 0, score = inter(lr[0], lr[1]) * n;
//     if (score >= k) {
//         cout << 0 << '\n';
//         return;
//     }
//     ll pre = 0;
//     if (inter(lr[0], lr[1]) == 0) {
//         ans += lr[1].first - lr[0].second;
//         pre = lr[1].first - lr[0].second;
//     }
//     ll gain = max(lr[0].second, lr[1].second) - min(lr[0].first, lr[1].first) - inter(lr[0], lr[1]);

//     if (score + gain >= k) {
//         ll rem = k - score;
//         cout << ans + rem << '\n';
//         return;
//     }
//     score += gain;
//     ans += gain;
//     rep1 (_, n - 1) {
//         if (score >= k) break;
//         ll rem = k - score;
//         ll gain2 = min(gain, rem);
//         if (gain2 <= pre) break;
//         else {
//             score += gain2;
//             ans += pre + gain2;
//         }
//     }

//     if (score < k) {
//         ll rem = k - score;
//         ans += 2 * rem;
//     }
//     cout << ans << '\n';
// }

signed main() {
    fio();
    int t = 1;

    // cin >> t;
    while (t--) solve();
}