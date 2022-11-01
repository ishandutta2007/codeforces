#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int K = 1000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> x(n), y(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  vector <int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    if (x[i] / K != x[j] / K)
      return x[i] / K < x[j] / K;
    int z = (x[i] / K) % 2 * 2;
    return (y[i] - y[j]) * (1 - z) < 0;
  });
  for (auto &now : p)
    cout << now + 1 << ' ';
  return 0;
}