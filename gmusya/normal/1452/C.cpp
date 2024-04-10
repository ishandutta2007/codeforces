#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string t1 = "", t2 = "";
    for (char &c : s) {
      if (c == '(' || c == ')') {
        t1 += c;
      } else {
        if (c == '[')
          t2 += "(";
        else
          t2 += ")";
      }
    }
    int ans = 0;
    stack <char> st;
    for (char c : t1) {
      if (c == ')' && !st.empty() && st.top() == '(')
        st.pop(), ans++;
      else
        st.push(c);
    }
    while (!st.empty())
      st.pop();
    for (char c : t2) {
      if (c == ')' && !st.empty() && st.top() == '(')
        st.pop(), ans++;
      else
        st.push(c);
    }
    cout << ans << '\n';
  }
  return 0;
}