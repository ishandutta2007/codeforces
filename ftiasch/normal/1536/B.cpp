#include <bits/stdc++.h>

namespace {

void solve(char *result, int n, const std::string &s) {
  static bool f1[26], f2[26][26], f3[26][26][26];
  memset(f1, 0, sizeof(f1));
  for (int i = 0; i < n; ++i) {
    f1[s[i] - 'a'] = true;
  }
  for (int a = 0; a < 26; ++a) {
    if (!f1[a]) {
      result[0] = 'a' + a;
      return;
    }
  }
  memset(f2, 0, sizeof(f2));
  for (int i = 1; i < n; ++i) {
    f2[s[i - 1] - 'a'][s[i] - 'a'] = true;
  }
  for (int a = 0; a < 26; ++a) {
    for (int b = 0; b < 26; ++b) {
      if (!f2[a][b]) {
        result[0] = 'a' + a;
        result[1] = 'a' + b;
        return;
      }
    }
  }
  memset(f3, 0, sizeof(f3));
  for (int i = 2; i < n; ++i) {
    f3[s[i - 2] - 'a'][s[i - 1] - 'a'][s[i] - 'a'] = true;
  }
  for (int a = 0; a < 26; ++a) {
    for (int b = 0; b < 26; ++b) {
      for (int c = 0; c < 26; ++c) {
        if (!f3[a][b][c]) {
          result[0] = 'a' + a;
          result[1] = 'a' + b;
          result[2] = 'a' + c;
          return;
        }
      }
    }
  }
}

} // namespace

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  char result[4];
  while (T--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    memset(result, 0, sizeof(result));
    solve(result, n, s);
    std::cout << result << "\n";
  }
}