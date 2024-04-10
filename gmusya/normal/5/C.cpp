#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector <int> cnt(n + 1);
  stack <int> st;
  st.push(-1);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      st.push(i);
    } else {
      st.pop();
      if (!st.empty())
        cnt[i - st.top()]++;
      if (st.empty())
        st.push(i);
    }
  }
  cnt[0] = 1;
  for (int i = n; i >= 0; i--)
    if (cnt[i]) {
      cout << i << ' ' << cnt[i];
      return 0;
    }
  return 0;
}