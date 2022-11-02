#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <vector <int>> ans(n);
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < n; j++)
        ans[j].push_back(i * n + j);
    } else {
      for (int j = 0; j < n; j++)
        ans[n - j - 1].push_back(i * n + j);
    }
  }
  for (auto &now : ans) {
    for (auto &nownow : now)
      cout << nownow + 1 << ' ';
    cout << '\n';
  }
  return 0;
}