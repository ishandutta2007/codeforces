#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> a(n);
  vector <unordered_set <int>> arr(m);
  int sum = -1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
    arr[x - 1].insert(i);
    if (!i || a[i] != a[i - 1])
      sum++;
  }
  cout << sum << '\n';
  for (int i = 1; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    bool rev = false;
    if (arr[u].size() < arr[v].size()) {
      swap(u, v);
      rev = true;
    }
    for (int val : arr[v]) {
      arr[u].insert(val);
      if (arr[u].find(val + 1) != arr[u].end() && arr[v].find(val + 1) == arr[v].end())
        sum--;
      if (arr[u].find(val - 1) != arr[u].end() && arr[v].find(val - 1) == arr[v].end())
        sum--;
    }
    if (rev)
      swap(arr[u], arr[v]);
    cout << sum << '\n';
  }
  return 0;
}