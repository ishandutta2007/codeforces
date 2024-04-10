#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    vector <int> tf(n);
    for (int i = 0; i < n; i++)
      cin >> tf[i];
    vector <int> b;
    for (int i = 0; i < n; i++)
      if (tf[i] == 0)
        b.push_back(a[i]);
    if (!b.empty())
      sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
      if (tf[i] == 0)
        a[i] = b.back(), b.pop_back();
    for (auto &now : a)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}