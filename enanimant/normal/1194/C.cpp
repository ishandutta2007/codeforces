// July 14, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int q;
  cin >> q;
  while (q--) {
    vector<string> s(3);
    vector< vector<int> > cnt(3, vector<int>(26, 0));
    for (int i = 0; i < 3; i++) {
      cin >> s[i];
      for (char c : s[i]) {
        cnt[i][c - 'a']++;
      }
    }
    int p = 0;
    for (char c : s[1]) {
      if (p < s[0].size() && c == s[0][p]) {
        p++;
      }
    }
    if (p != s[0].size()) {
      cout << "NO\n";
      continue;
    }
    bool works = true;
    for (int i = 0; i < 26; i++) {
      if (cnt[0][i] + cnt[2][i] < cnt[1][i]) {
        works = false;
      }
    }
    cout << (works ? "YES" : "NO") << '\n';
  }


  return 0;
}