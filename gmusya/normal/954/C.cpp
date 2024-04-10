#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  set <int> mod;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i + 1 < n; i++)
    if (abs(a[i] - a[i + 1]) != 1) {
      if (a[i] == a[i + 1]) {
        cout << "NO";
        return 0;
      }
      mod.insert(abs(a[i] - a[i + 1]));
    }
  if (mod.size() > 1) {
    cout << "NO\n";
    return 0;
  }
  if (mod.empty())
    mod.insert(1);
  int val = *mod.begin();
  if (val != 1) {
    int x = (a[0] - 1) % val + 1;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] == a[i + 1] + 1)
        x--;
      if (a[i] == a[i + 1] - 1)
        x++;
      if (x > val || x <= 0) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES\n";
  cout << 1000000000 << ' ' << *mod.begin();
  return 0;
}