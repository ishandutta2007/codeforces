#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;
const int C = 26;

char s[N + 1];
std::vector<int> b[C];

int main() {
  int n;
  scanf("%d%s", &n, s);
  for (int c = 0; c < C; ++c) {
    b[c].push_back(0);
  }
  for (int i = 0; i < n; ++i) {
    b[s[i] - 'a'].push_back(i + 1);
  }
  scanf("%d", &n);
  while (n--) {
    scanf("%s", s);
    int cnt[C]{};
    for (int i = 0; s[i]; ++i) {
      cnt[s[i] - 'a']++;
    }
    int result = 0;
    for (int c = 0; c < C; ++c) {
      result = std::max(result, b[c][cnt[c]]);
    }
    printf("%d\n", result);
  }
}