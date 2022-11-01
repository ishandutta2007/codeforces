#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <int> n(3);
  for (int i = 0; i < 3; i++)
    cin >> n[i];
  vector <vector <int>> a(3);
  for (int i = 0; i < 3; i++) {
    a[i].resize(n[i]);
    for (int j = 0; j < n[i]; j++)
      cin >> a[i][j];
  }
  for (int i = 0; i < 3; i++)
    sort(a[i].begin(), a[i].end());
  vector <ll> sum(3), mi(3, 2e9);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n[i]; j++) {
      sum[i] += a[i][j];
      mi[i] = min(mi[i], (ll)a[i][j]);
    }
  sort(sum.begin(), sum.end());
  sort(mi.begin(), mi.end());
  cout << sum[1] + sum[2] - min(sum[0], 2 * (mi[0] + mi[1]) - sum[0]);
  return 0;
}