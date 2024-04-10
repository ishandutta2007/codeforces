#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int const ALPHA = 26;

  auto solve = []() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> cnt_s(ALPHA), cnt_t(ALPHA);
    for (char ch : s) {
      cnt_s[ch - 'a'] += 1;
    }
    for (char ch : t) {
      cnt_t[ch - 'a'] += 1;
    }
    for (int i = 0; i < ALPHA; ++i) {
      if (cnt_s[i] != cnt_t[i]) {
        return false;
      }
    }
    for (int i = 0; i < ALPHA; ++i) {
      if (cnt_s[i] > 1 || cnt_t[i] > 1) {
        return true;
      }
    }
    fill(cnt_s.begin(), cnt_s.end(), 0);
    fill(cnt_t.begin(), cnt_t.end(), 0);
    int parity_s = 0;
    int parity_t = 0;
    for (int i = 0; i < n; ++i) {
      int cur_s = 0;
      for (int ch = s[i] - 'a'; ch < ALPHA; ++ch) {
        cur_s ^= cnt_s[ch];
      }
      int cur_t = 0;
      for (int ch = t[i] - 'a'; ch < ALPHA; ++ch) {
        cur_t ^= cnt_t[ch];
      }
      parity_s ^= cur_s;
      parity_t ^= cur_t;
      cnt_s[s[i] - 'a'] ^= 1;
      cnt_t[t[i] - 'a'] ^= 1;
    }
    return parity_s == parity_t;
  };

  int q;
  cin >> q;
  while (q--) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}