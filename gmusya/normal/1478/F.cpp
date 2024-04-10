#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll sqr(ll x) {
  return x * x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> x(n), y(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  vector <int> p;
  vector <bool> used(n);
  p.push_back(0);
  used[0] = 1;
  for (int it = 1; it < n; it++) {
    pair <ll, int> res = {-1, -1};
    for (int j = 0; j < n; j++) {
      if (used[j])
        continue;
      res = max(res, {sqr(x[p.back()] - x[j]) + sqr(y[p.back()] - y[j]), j});
    }
    used[res.second] = true;
    p.push_back(res.second);
  }
  for (auto &now : p)
    cout << now + 1 << ' ';
  return 0;
}