#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> ans;

void f(int l, int r) {
  if (l >= r)
    return;
  int m = (l + r) / 2;
  f(l, m);
  f(m + 1, r);
  for (int i = l; i <= m; i++)
    ans.push_back({i, r - i + l});
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int m = 1;
  while (m * 2 <= n)
    m *= 2;
  f(1, m);
  f(n - m + 1, n);
  cout << ans.size() << '\n';
  for (auto &now : ans)
    cout << now.first << ' ' << now.second << '\n';
  return 0;
}