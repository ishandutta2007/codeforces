#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0, del = 1;
  stack <int> st;
  for (int i = 0; i < 2 * n; i++) {
    string s;
    cin >> s;
    if (s == "add") {
      int x;
      cin >> x;
      st.push(x);
    } else {
      if (!st.empty()) {
        if (st.top() == del) {
          st.pop();
        } else {
          ans++;
          while (!st.empty())
            st.pop();
        }
      }
      del++;
    }
  }
  cout << ans;
  return 0;
}