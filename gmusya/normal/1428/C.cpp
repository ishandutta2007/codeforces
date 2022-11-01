#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    stack <int> st;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == 'A')
        st.push('A');
      if (s[i] == 'B') {
        if (st.empty())
          st.push('B');
        else
          st.pop();
      }
    }
    cout << st.size() << '\n';
  }
  return 0;
}