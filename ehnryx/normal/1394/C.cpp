//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int n;
  cin >> n;
  vector<pair<int,int>> v;
  for(int i=0; i<n; i++) {
    string s;
    cin >> s;
    int nc = count(s.begin(), s.end(), 'N');
    int bc = count(s.begin(), s.end(), 'B');
    v.emplace_back(nc, bc);
    //cerr<<"get "<<nc<<" "<<bc<<nl;
  }

  function<pair<int,int>(int)> solve = [=](int m) {
    int mina = 0, minb = 0, minab = -INF;
    int maxa = INF, maxb = INF, maxab = INF;
    for(auto [a, b] : v) {
      maxa = min(maxa, a + m);
      maxb = min(maxb, b + m);
      maxab = min(maxab, b - a + m);
      mina = max(mina, a - m);
      minb = max(minb, b - m);
      minab = max(minab, b - a - m);
    }
    maxab = min(maxab, maxb - mina);
    minab = max(minab, minb - maxa);
    if(maxa < mina || maxb < minb || maxab < minab) {
      return make_pair(0, 0);
    }

    int x1 = min(maxa, maxb - maxab);
    int x2 = min(maxa, maxb - minab);
    pair<int,int> A(x1, x1 + maxab);
    pair<int,int> B(x2, x2 + minab);
    if(A.first == B.first || A.second == B.second) {
      pair<int,int> res = max(A, B);
      return res;
    } else {
      return make_pair(maxa, maxb);
    }
  };

  int l = 0;
  int r = 1e6;
  while(l < r) {
    int m = (l+r) / 2;
    auto [a, b] = solve(m);
    if(min(a,b) < 0 || a+b == 0) {
      l = m+1;
    } else {
      r = m;
    }
  }

  auto [a, b] = solve(r);
  assert(a >= 0);
  string s(a, 'N');
  s.resize(a+b, 'B');
  cout << r << nl;
  cout << s << nl;

#ifndef ONLINE_JUDGE
  cerr << nl;
  cerr << "ANS: " << a << " " << b << nl;
  for(auto [x, y] : v) {
    int dx = x - a;
    int dy = y - b;
    if((ll)dx*dy >= 0) {
      cerr << x << " " << y << " -> " << max(abs(dx),abs(dy)) << nl;
    } else {
      cerr << x << " " << y << " -> " << abs(dx)+abs(dy) << nl;
    }
  }
#endif

  return 0;
}