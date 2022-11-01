#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  ll n;
  cin >> n;
  vector <ll> a(3), b(3);
  for (int i = 0; i < 3; i++)
    cin >> a[i];
  for (int i = 0; i < 3; i++)
    cin >> b[i];
  ll win = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
  vector <pair <ll, ll>> pairs = {{0, 0}, {0, 2}, {1, 0}, {1, 1}, {2, 1}, {2, 2}};
  ll lose = 0;
  do {
    ll sum = 0;
    vector <ll> _a = a, _b = b;
    for (auto &now : pairs) {
      int i = now.first, j = now.second;
      ll k = min(_a[i], _b[j]);
      sum += k;
      _a[i] -= k, _b[j] -= k;
    }
    lose = max(lose, sum);
  } while (next_permutation(pairs.begin(), pairs.end()));
  cout << n - lose << ' ' << win;
  return 0;
}