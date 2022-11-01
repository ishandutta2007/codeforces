#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() % 2) {
      cout << "NO\n";
      continue;
    }
    if (s[0] == ')' || s.back() == '(')
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}