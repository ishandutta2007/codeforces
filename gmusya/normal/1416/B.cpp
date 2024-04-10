#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n) {
      cout << -1 << '\n';
      continue;
    }
    vector <pair <pair <int, int>, int>> q;
    for (int i = 2; i <= n; i++) {
      if (a[i] % i) {
        q.push_back({{1, i}, (i - a[i] % i)});
        int x = i - a[i] % i;
        a[i] += x;
        a[1] -= x;
      }
      q.push_back({{i, 1}, a[i] / i});
      a[1] += a[i];
      a[i] = 0;
    }
    for (int i = 2; i <= n; i++)
      q.push_back({{1, i}, sum / n});
    cout << q.size() << '\n';
    for (auto &now : q)
      cout << now.first.first << ' ' << now.first.second << ' ' << now.second << '\n';
  }
  return 0;
}