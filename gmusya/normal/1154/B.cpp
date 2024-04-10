#include <iostream>
#include <vector>

using namespace std;

typedef pair <int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> cnt(101);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  vector <pii> a;
  for (int i = 1; i <= 100; i++)
    if (cnt[i])
      a.push_back({i, cnt[i]});
  if (a.size() >= 4) {
    cout << -1;
    return 0;
  }
  if (a.size() == 3) {
    if (a[1].first - a[0].first != a[2].first - a[1].first)
      cout << -1;
    else
      cout << a[1].first - a[0].first;
    return 0;
  }
  if (a.size() == 2) {
    int x = a[1].first - a[0].first;
    if (x % 2 == 0)
      x /= 2;
    cout << x;
    return 0;
  }
  cout << 0;
  return 0;
}