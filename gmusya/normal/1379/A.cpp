#include <iostream>
#include <vector>

using namespace std;

string tmp = "abacaba";

int get(string s) {
  int n = (int)s.size();
  int cnt = 0;
  for (int i = 0; i + 6 < n; i++) {
    bool flag = true;
    for (int j = 0; j < 7; j++)
      if (s[i + j] != tmp[j])
        flag = false;
    cnt += flag;
  }
  return cnt;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 0; i + 6 < n; i++) {
      string c = s;
      for (int j = 0; j < 7; j++)
        if (c[i + j] == '?')
          c[i + j] = tmp[j];
      for (int j = 0; j < n; j++)
        if (c[j] == '?')
          c[j] = 'd';
      if (get(c) == 1) {
        cout << "Yes\n";
        cout << c << '\n';
        flag = true;
        break;
      }
    }
    if (!flag)
      cout << "No\n";
  }
}