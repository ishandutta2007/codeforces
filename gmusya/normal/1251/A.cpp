#include <iostream>
#include <vector>
#include <string>

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
    vector <bool> hm(26);
    for (int i = 0; i < n; i++) {
      int l = i;
      while (l < n && s[i] == s[l])
        l++;
      l--;
      if ((l - i) % 2 == 0)
        hm[s[i] - 'a'] = true;
      i = l;
    }
    for (int i = 0; i < 26; i++)
      if (hm[i])
        cout << (char)(i + 'a');
    cout << '\n';
  }
  return 0;
}