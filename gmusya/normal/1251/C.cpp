#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector <int> a, b;
    for (int i = 0; i < n; i++) {
      if ((s[i] - '0') % 2)
        a.push_back(s[i] - '0');
      else
        b.push_back(s[i] - '0');
    }
    vector <int> c;
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
    for (auto &now : c)
      cout << now;
    cout << '\n';
  }
  return 0;
}