#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> a(n);
  vector <pair <int, int>> ans;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  stack <int> st2;
  stack <int> st3;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0)
      continue;
    if (a[i] == 1) {
      ans.push_back({i, i});
      if (!st2.empty()) {
        int id = st2.top();
        st2.pop();
        ans.push_back({i, id});
        continue;
      }
      if (!st3.empty()) {
        int id = st3.top();
        st3.pop();
        ans.push_back({id, id});
        ans.push_back({id, i});
        continue;
      }
    }
    if (a[i] == 2) {
      if (!st3.empty()) {
        int id = st3.top();
        st3.pop();
        ans.push_back({id, id});
        ans.push_back({id, i});
      }
      st2.push(i);
      continue;
    }
    if (a[i] == 3) {
      if (!st3.empty()) {
        int id = st3.top();
        st3.pop();
        ans.push_back({id, id});
        ans.push_back({id, i});
      }
      st3.push(i);
      continue;
    }
  }
  if (!st2.empty() || !st3.empty()) {
    cout << -1;
    return 0;
  }
  cout << ans.size() << '\n';
  for (auto &now : ans)
    cout << now.first + 1 << ' ' << now.second + 1 << '\n';
  return 0;
}