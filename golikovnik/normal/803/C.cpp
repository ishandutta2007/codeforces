#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
  i64 n, k;
  cin >> n >> k;
  vector<i64> divs;
  for (i64 d = 1; d * d <= n; ++d) {
    if (n % d) {
      continue;
    }
    divs.push_back(d);
    divs.push_back(n / d);
  }
  sort(divs.begin(), divs.end());
  reverse(divs.begin(), divs.end());
  //  k * (k + 1) / 2 > n
  if (k > n * 2 / (k + 1)) {
    cout << "-1";
    return 0;
  }
  i64 min_s = k * (k + 1) / 2;
  for (auto d : divs) {
    auto new_s = n / d;
    if (new_s < min_s) {
      continue;
    }
    vector<i64> ans(k);
    iota(ans.begin(), ans.end(), 1);
    ans.back() += new_s - min_s;
    for (auto x : ans) {
      cout << x * d << ' ';
    }
    cout << '\n';
    return 0;
  }
  cout << "-1\n";
  return 0;
}