#include <bits/stdc++.h>

const int N = 2000;

char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, lim;
    long long rnk;
    scanf("%d%d%lld%s", &n, &lim, &rnk, s);
    rnk--;
    std::vector<int> result;
    for (int i = n - 1; ~i;) {
      if (s[i] == 'a') {
        result.push_back(-1);
        i--;
      } else {
        int j = i;
        while (~j && s[j] == '*') {
          j--;
        }
        int cnt = (i - j) * lim + 1;
        result.push_back(rnk % cnt);
        rnk /= cnt;
        i = j;
      }
    }
    for (int i = result.size(); i--;) {
      if (~result[i]) {
        for (int j = 0; j < result[i]; ++j) {
          putchar('b');
        }
      } else {
        putchar('a');
      }
    }
    puts("");
  }
}