// March 29, 2020
// https://codeforces.com/contest/1332/problem/C

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


  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = s[i] - 'a';
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
      vector<int> cnt(26, 0);
      for (int j = i; j < n; j += k) {
        cnt[a[j]]++;
      }
      for (int j = k - 1 - i; j < n; j += k) {
        cnt[a[j]]++;
      }
      int best = max_element(cnt.begin(), cnt.end()) - cnt.begin();
      for (int j = i; j < n; j += k) {
        if (a[j] != best) {
          ans++;
          a[j] = best;
        }
      }
      for (int j = k - 1 - i; j < n; j += k) {
        if (a[j] != best) {
          ans++;
          a[j] = best;
        }
      }
    }
    cout << ans << '\n';
  }


  return 0;
}