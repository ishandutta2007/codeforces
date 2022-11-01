// February 17, 2020
// https://codeforces.com/contest/1307/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


long long cnt[26][26];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  string s;
  cin >> s;
  int n = (int) s.size();
  vector<vector<int>> psa(n + 1, vector<int>(26, 0));
  for (int i = 1; i <= n; i++) {
    psa[i] = psa[i - 1];
    psa[i][s[i - 1] - 'a']++;
  }
  long long ans = *max_element(psa[n].begin(), psa[n].end());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      cnt[s[i] - 'a'][j] += psa[n][j] - psa[i + 1][j];
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      ans = max(ans, cnt[i][j]);
    }
  }
  cout << ans << '\n';


  return 0;
}