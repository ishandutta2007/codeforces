#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int b, w;
    cin >> b >> w;
    if (4 + 3 * (w - 1) < b || 4 + 3 * (b - 1) < w) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector <pair <int, int>> ans;
    int x = 0;
    if (b > w) {
      swap(b, w);
      x++;
    }
    for (int i = 0; i < b; i++) {
      ans.push_back({2, 3 + 2 * i});
      ans.push_back({2, 4 + 2 * i}); 
    }
    w -= b;
    if (w) {
      ans.push_back({2, 2});
      w--;
    }
    for (int i = 0; i < b && w; i++, w--)
      ans.push_back({1, 3 + 2 * i});
    for (int i = 0; i < b && w; i++, w--)
      ans.push_back({3, 3 + 2 * i});
    for (auto &now : ans)
      cout << now.first + x << ' ' << now.second << '\n';
  }
  return 0;
}