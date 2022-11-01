#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = (int) s.size() - 1; i >= 0; i--) {
    if (s[i] == '0')
      cnt++;
    else if (cnt)
      cnt--;
    else
      s[i] = '0';
  }
  cout << s;
  return 0;
}