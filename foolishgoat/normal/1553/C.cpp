#include <bits/stdc++.h>

using namespace std;

char s[22];

void solve() {
  scanf("%s", s);
  int ans = 10;
  int goal[2], rem[2];
  goal[0] = goal[1] = 0;
  rem[0] = rem[1] = 5;
  for (int i = 0; i < 10; ++i) {
    int score = s[i] - '0';
    if (s[i] == '?')
      score = i & 1;
    goal[i & 1] += score;
    --rem[i & 1];
    if (goal[0] > goal[1] + rem[1] || goal[1] > goal[0] + rem[0]) {
      ans = min(ans, i + 1);
    }
  }
  goal[0] = goal[1] = 0;
  rem[0] = rem[1] = 5;
  for (int i = 0; i < 10; ++i) {
    int score = s[i] - '0';
    if (s[i] == '?')
      score = !(i & 1);
    goal[i & 1] += score;
    --rem[i & 1];
    if (goal[0] > goal[1] + rem[1] || goal[1] > goal[0] + rem[0]) {
      ans = min(ans, i + 1);
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}