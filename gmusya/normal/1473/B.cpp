#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(string &a, string &b) {
  int n = a.size(), m = b.size();
  if (n % m)
    return false;
  for (int i = 0; i < n; i++)
    if (a[i] != b[i % m])
      return false;
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() < s2.size())
      swap(s1, s2);
    string t = "";
    bool flag = false;
    for (int it = 0; it < 20; it++) {
      t += s1;
      flag = check(t, s2);
      if (!flag)
        continue;
      cout << t << '\n';
      break;
    }
    if (!flag)
      cout << -1 << '\n';
  }
  return 0;
}