#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <pair <pair <int, int>, int>> arr;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    if (l > r)
      swap(l, r);
    arr.push_back({{l, 0}, i});
    arr.push_back({{r, 1}, i});
  }
  sort(arr.begin(), arr.end());
  vector <bool> used(n);
  vector <int> ans;
  stack <int> s;
  for (int i = 0; i < (int)arr.size(); i++) {
    if (arr[i].first.second == 0) {
      s.push(arr[i].second);
      continue;
    }
    if (used[arr[i].second])
      continue;
    ans.push_back(arr[i].first.first);
    while (!s.empty()) {
      int id = s.top();
      used[id] = true;
      s.pop();
    }
  }
  cout << ans.size() << '\n';
  for (auto &now : ans)
    cout << now << ' ';
  return 0;
}