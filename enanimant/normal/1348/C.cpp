// May 1, 2020
// https://codeforces.com/contest/1348/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> res(k, "");
    for (int i = 0; i < k; i++) {
      res[i] = s[i];
    }
    if (s[k - 1] != s[0]) {
      cout << s[k - 1] << '\n';
      continue;
    }
    bool same = true;
    for (int i = k; i < n; i++) {
      same &= (s[i] == s[k]);
    }
    if (same) {
      for (int i = k; i < n; i++) {
        res[i % k] += s[i];
      }
      cout << res[0] << '\n';
      continue;
    }
    res[0] += s.substr(k);
    // for (int i = k; i < n; i += k) {
    //   if (s[min(i + k - 1, n - 1)] != s[i]) {
    //     for (int j = i; j < n; j++) {
    //       res[0] += s[j];
    //     }
    //     break;
    //   }
    //   for (int j = i; j < min(i + k, n); j++) {
    //     res[j % k] += s[j];
    //   }
    // }
    cout << res[0] << '\n';
    // bool done = false;
    // for (int i = 0; i < n; i += k) {
    //   for (int j = i; j < min(i + k, n); j++) {
    //     if (s[j] != s[i]) {
    //       res[j % k] += s[j];
    //       cout << res[j % k] << '\n';
    //       done = true;
    //       break;
    //     }
    //     res[j % k] += s[j];
    //   }
    //   if (done) {
    //     break;
    //   }
    // }
    // if (!done) {
    //   cout << res[0] << '\n';
    // }
    // int x = 0; // how many are currently equal to the max
    // for (int i = 0; i < k; i++) {
    //   if (s[i] == s[k - 1]) {
    //     x++;
    //   }
    // }
    // string res = "" + s[k - 1];
    // vector<int> cnt(26, 0);
    // for (int i = k; i < n; i++) {
    //   cnt[s[i] - 'a']++;
    // }
    // for (int i = 0; i < 26; i++) {
    //   for (int j = 0; j < cnt[i] / x; j++) {
    //     res += (char) ('a' + i);
    //   }
    //   cnt[i] %= x;
    //   if (cnt[i] != 0) {
    //     x = cnt[i];
    //     res += (char) ('a' + i);
    //   }
    // }
    // cout << res << '\n';
    // vector<string> res(k, "");
    // int ptr = 0;
    // for (int i = 0; i < k; i++) {
    //   res[i] += s[i];
    //   if (s[i] == s[0]) {
    //     ptr++;
    //   }
    // }
    // vector<int> cnt(26);
    // for (int i = k; i < n; i++) {
    //   cnt[s[i] - 'a']++;
    // }
    // for (int i = 0; i < 26; i++) {
    //   for (int j = 0; j < ptr; j++) {
    //     if (j >= cnt[i]) {
    //       res[0] += (char) ('a' + i);
    //     } else {
    //       res[j] += (char) ('a' + i);
    //     }
    //   }
    //   ptr = min(ptr, cnt[i]);
    // }
    // sort(res.begin(), res.end());
    // cout << res[k - 1] << '\n';
  }


  return 0;
}