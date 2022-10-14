#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  char buffer[11];
  while (T--) {
    scanf("%s", buffer);
    int knowns = 0;
    int unknowns = 0;
    for (int i = 0; i < 10; ++i) {
      if (buffer[i] == '?') {
        unknowns |= 1 << i;
      } else if (buffer[i] == '1') {
        knowns |= 1 << i;
      }
    }
    int result = 10;
    for (int mask = (1 << 10) - 1 & unknowns;; mask = mask - 1 & unknowns) {
      int pred = knowns | mask;
      int i = 0;
      int sum[]{0, 0};
      int pos[]{5, 5};
      while (i < 10) {
        pos[i & 1]--;
        sum[i & 1] += pred >> i & 1;
        bool can_win = sum[0] + pos[0] > sum[1];
        bool can_loss = sum[0] < sum[1] + pos[1];
        bool can_tie = pos[1] >= sum[0] - sum[1] && sum[0] - sum[1] >= -pos[0];
        i++;
        if (can_win + can_loss + can_tie == 1) {
          break;
        }
      }
      result = std::min(result, i);
      if (mask == 0) {
        break;
      }
    }
    printf("%d\n", result);
  }
}