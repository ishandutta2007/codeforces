#include <iostream>
#include <vector>

using namespace std;

bool check(vector <int> a) {
  vector <int> b;
  for (auto &now : a) {
    if (b.empty() || b.back() != now)
      b.push_back(now);
    else
      b.pop_back();
  }
  for (int i = 0; i + 1 < (int) b.size(); i++)
    if (b[i] != b[i + 1])
      return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] &= 1;
  }
  if (check(a))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}