#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> h(n);
  for (int i = 0; i < n; i++)
    cin >> h[i];
  multiset <int> ms;
  int l = 0;
  vector <int> ans(n);
  int ma = 0;
  for (int r = 0; r < n; r++) {
    ms.insert(h[r]);
    while (*ms.rbegin() - *ms.begin() > k)
      ms.erase(ms.find(h[l++]));
    ans[r] = ms.size();
    ma = max(ma, ans[r]);
  }
  vector <pair <int, int>> answer;
  for (int i = 0; i < n; i++)
    if (ans[i] == ma)
      answer.push_back({i - ans[i] + 1, i});
  cout << ma << ' ' << answer.size() << '\n';
  for (auto &now : answer)
    cout << now.first + 1 << ' ' << now.second + 1 << '\n';
  return 0;
}