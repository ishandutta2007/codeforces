#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  set <int> kuchki;
  multiset <int> diff;
  for (int i = 0; i < n; i++)
    kuchki.insert(a[i]);
  for (int i = 0; i + 1 < n; i++)
    diff.insert(a[i + 1] - a[i]);
  if (kuchki.size() < 3)
    cout << "0\n";
  else
    cout << *kuchki.rbegin() - *kuchki.begin() - *diff.rbegin() << '\n';
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 0) {
      int x;
      cin >> x;
      auto nowr = kuchki.upper_bound(x);
      auto nowl = kuchki.lower_bound(x);
      if (kuchki.size() > 1) {
        if (nowr == kuchki.end())
          diff.erase(diff.find(x - *(--nowl)));
        else if (nowl == kuchki.begin())
          diff.erase(diff.find(*nowr - x));
        else {
          int l = *(--nowl);
          int r = *nowr;
          diff.erase(diff.find(x - l));
          diff.erase(diff.find(r - x));
          diff.insert(r - l);
        }
      }
      kuchki.erase(x);
    }
    if (type == 1) {
      int x;
      cin >> x;
      auto now = kuchki.upper_bound(x);
      if (!kuchki.empty()) {
        if (now == kuchki.begin())
          diff.insert(*now - x);
        else if (now == kuchki.end())
          diff.insert(x - *(--now));
        else {
          int r = *now;
          int l = *(--now);
          diff.erase(diff.find(r - l));
          diff.insert(r - x);
          diff.insert(x - l);
        }
      }
      kuchki.insert(x);
    }
    if (kuchki.size() < 3)
      cout << "0\n";
    else
      cout << *kuchki.rbegin() - *kuchki.begin() - *diff.rbegin() << '\n';
  }
  return 0;
}