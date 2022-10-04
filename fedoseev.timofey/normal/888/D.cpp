#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  ll ans = 1;
  if (k >= 2) ans += (ll)n * (n - 1) / 2;
  for (int t = 3; t <= min(k, 4); ++t) {
    vector<int> p(t);
    for (int i = 0; i < t; ++i) p[i] = i;
    do {
      bool ok = true;
      for (int i = 0; i < t; ++i) {
       ok &= p[i] != i;
      } 
      if (ok) {
        if (t == 3) {
          ans += (ll)n * (n - 1) * (n - 2) / 6;
        } else {
          ans += (ll)n * (n - 1) * (n - 2) * (n - 3) / 24;
        }
      }
    } while (next_permutation(p.begin(), p.end()));
  }
  cout << ans << '\n';
}