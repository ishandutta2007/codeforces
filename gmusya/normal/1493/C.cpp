#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    if (n % m) {
      cout << -1 << '\n';
      continue;
    }
    vector <int> cnt(26);
    for (char ch : s)
      cnt[ch - 'a']++;
    {
      bool flag = true;
      for (int i = 0; i < 26; i++)
        if (cnt[i] % m)
          flag = false;
      if (flag) {
        cout << s << '\n';
        continue;
      }
    }
    bool flag = false;
    for (int i = n - 1; i >= 0; i--) {
      if (flag)
        break;
      cnt[s[i] - 'a']--;
      for (int j = s[i] - 'a' + 1; j < 26; j++) {
        int need = 0;
        for (int k = 0; k < 26; k++) {
          int val = cnt[k] + (j == k);
          need += (val % m ? m - val % m : 0);
        }
        if (need > n - i)
          continue;
        flag = true;
        for (int j = 0; j < i; j++)
          cout << s[j];
        cout << (char)(j + 'a');
        for (int it = 0; it < n - i - 1 - need; it++)
          cout << 'a';
        for (int k = 0; k < 26; k++) {
          int val = cnt[k] + (j == k);
          int need = (val % m ? m - val % m : 0);
          for (int it = 0; it < need; it++)
            cout << (char)(k + 'a');
        }
        cout << '\n';
        break;
      }
    }
  }
  return 0;
}