#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int q;
  cin >> q;
  vector <pair <int, int>> arr(q, {-1, -1});
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1)
      cin >> arr[i].first >> arr[i].second;
    else
      cin >> arr[i].first;
  }
  vector <int> ans(n, -1);
  int ma = -INF;
  for (int i = q - 1; i >= 0; i--) {
    if (arr[i].second == -1)
      ma = max(ma, arr[i].first);
    else if (ans[arr[i].first - 1] == -1)
      ans[arr[i].first - 1] = max(ma, arr[i].second);
  }
  for (int i = 0; i < n; i++)
    if (ans[i] == -1)
      ans[i] = max(ma, a[i]);
  for (auto &now : ans)
    cout << now << ' ';
  return 0;
}