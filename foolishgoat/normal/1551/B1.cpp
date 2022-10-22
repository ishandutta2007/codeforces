#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N];
int cnt[26];

void solve() {
  scanf("%s", s);
  int n = strlen(s);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i]-'a'];
  }
  int tot = 0;
  for (int i = 0; i < 26; ++i) {
    cnt[i] = min(cnt[i], 2);
    tot += cnt[i];
  }
  printf("%d\n", tot / 2);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}