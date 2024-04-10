#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <string> s(n);
    for (int i = 0; i < n; i++)
      cin >> s[i];
    vector <int> cnt(26);
    for (auto &str : s)
      for (auto &c : str)
        cnt[c - 'a']++;
    bool tf = true;
    for (auto &val : cnt)
      if (val % n)
        tf = false;
    if (tf)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}