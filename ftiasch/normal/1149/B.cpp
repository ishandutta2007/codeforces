#include <bits/stdc++.h>

const int N = 100000;
const int M = 250 + 1;
const int OFFSET[] = {1, M, M * M};

int next[N + 2][26], dp[M * M * M];
char text[N + 1];
std::vector<int> pattern[3];

void update(int& x, int a)
{
  x = std::min(x, a);
}

int main() {
  int n, q;
  while (scanf("%d%d", &n, &q) == 2) {
    scanf("%s", text);
    for (int i = 0; i < 26; ++i) {
      next[n][i] = next[n + 1][i] = n + 1;
    }
    for (int i = n - 1; i >= 0; --i) {
      memcpy(next[i], next[i + 1], sizeof(next[i]));
      next[i][text[i] - 'a'] = i + 1;
    }
    dp[0] = 0;
    while (q--) {
      char op[2], ch[2];
      int t;
      scanf("%s%d", op, &t);
      t--;
      if (*op == '+') {
        scanf("%s", ch);
        pattern[t].push_back(*ch - 'a');
        auto &a = pattern[t];
        auto &b = pattern[(t + 1) % 3];
        auto &c = pattern[(t + 2) % 3];
        int base = OFFSET[t] * pattern[t].size();
        int oa = OFFSET[t];
        int ob = OFFSET[(t + 1) % 3];
        int oc = OFFSET[(t + 2) % 3];
        for (int i = 0; i <= static_cast<int>(b.size()); ++i) {
          for (int j = 0; j <= static_cast<int>(c.size()); ++j) {
            int p = base + ob * i + oc * j;
            dp[p] = n + 1;
            if (i) {
              update(dp[p], next[dp[p - ob]][b[i - 1]]);
            }
            if (j) {
              update(dp[p], next[dp[p - oc]][c[j - 1]]);
            }
            update(dp[p], next[dp[p - oa]][a.back()]);
          }
        }
      } else {
        pattern[t].pop_back();
      }
      puts(dp[OFFSET[0] * pattern[0].size() + OFFSET[1] * pattern[1].size() + OFFSET[2] * pattern[2].size()] <= n ? "YES" : "NO");
    }
  }
}