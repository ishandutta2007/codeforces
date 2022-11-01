#include <iostream>
#include <vector>
#include <string>

using namespace std;

string f(string s) {
  if (s.size() % 2)
    return s;
  int len = s.size() / 2;
  string s1 = f(s.substr(0, len));
  string s2 = f(s.substr(len, 2 * len));
  if (s1 < s2)
    return s1 + s2;
  return s2 + s1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s1, s2;
  cin >> s1 >> s2;
  if (f(s1) == f(s2))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}