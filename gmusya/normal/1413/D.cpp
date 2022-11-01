#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  stack <int> st;
  vector <pair <int, int>> queries(n + n);
  vector <pair <int, int>> ans;
  bool flag = true;
  for (int i = 0; i < n + n; i++) {
    char c;
    cin >> c;
    if (c == '+') {
      queries[i].first = 0;
      st.push(i);
      continue;
    }
    if (st.empty()) {
      flag = false;
      continue;
    }
    queries[i].first = 1;
    int x;
    cin >> x;
    queries[i].second = x;
    queries[st.top()].second = x;
    ans.push_back({st.top(), x});
    st.pop();
  }
  if (!flag) {
    cout << "NO";
    return 0;
  }
  set <int> se;
  for (int i = 0; i < n + n; i++) {
    if (queries[i].first == 0)
      se.insert(queries[i].second);
    else {
      int val = *se.begin();
      if (val != queries[i].second) {
        cout << "NO";
        return 0;
      }
      se.erase(val);
    }
  }
  sort(ans.begin(), ans.end());
  cout << "YES\n";
  for (auto &now : ans)
    cout << now.second << ' ';
  return 0;
}