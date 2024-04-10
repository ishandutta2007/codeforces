%:include <bits/stdc++.h>
using namespace std;

//#define FILENAME sadcactus

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());



// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> frequency;
    for (int i=0; i<n; i++) {
      int v;
      cin >> v;
      frequency[v].push_back(i);
    }
    vector<int> colour(n);
    vector<int> order;
    int cid = 0;
    for (const auto& it : frequency) {
      for(auto idx : views::take(it.second, m)) {
        colour[idx] = (cid++) + 1;
        if (cid == m) cid = 0;
        order.push_back(idx);
      }
    }
    while(size(order) % m != 0) {
      colour[order.back()] = 0;
      order.pop_back();
    }
    for (int c : colour) {
      cout << c << " ";
    }
    cout << nl;
  }

  return 0;
}