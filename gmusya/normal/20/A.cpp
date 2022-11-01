#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  while (s.size() > 1 && s.back() == '/')
    s.pop_back();
  for (int i = 0; i < (int)s.size(); i++)
    if (i == 0 || (s[i] != '/') || (s[i - 1] != '/'))
      cout << s[i];
  return 0;
}