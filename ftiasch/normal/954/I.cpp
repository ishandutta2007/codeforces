#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

const int M = 6;
const int BM = 203;

using Bell = std::array<int, M>;

int number_of_group(const Bell &b) {
  return *std::max_element(b.begin(), b.end()) + 1;
}

Bell merge(const Bell &b, int s, int t) {
  Bell r{b};
  for (int i = 0; i < M; ++i) {
    if (b[i] == t) {
      r[i] = s;
    } else if (b[i] > t) {
      r[i] = b[i] - 1;
    }
  }
  return r;
}

std::vector<Bell> bells;

const int N = 125000;

char s[N + 1], t[N + 1];
int result[N], sub[M][M];
std::vector<int> queue[BM];

int buffer[N + N + 1], z[N + N + 1];

int main() {
  {
    Bell b;
    std::iota(b.begin(), b.end(), 0);
    bells.push_back(b);
    for (size_t head = 0; head < bells.size(); ++head) {
      auto b = bells[head];
      int g = number_of_group(b);
      for (int s = 0; s < g; ++s) {
        for (int t = s + 1; t < g; ++t) {
          auto nb = merge(b, s, t);
          if (std::find(bells.begin(), bells.end(), nb) == bells.end()) {
            bells.push_back(nb);
          }
        }
      }
    }
  }
  scanf("%s%s", s, t);
  int n = strlen(s);
  int m = strlen(t);
  for (int i = 0; i + m <= n; ++i) {
    queue[0].push_back(i);
  }
  for (int bid = 0; bid < BM; ++bid) {
    if (!queue[bid].empty()) {
      const Bell &bell = bells[bid];
      //   std::cout << KV(bell) << std::endl;
      int groups = number_of_group(bell);
      for (int s = 0; s < groups; ++s) {
        for (int t = s + 1; t < groups; ++t) {
          sub[s][t] = sub[t][s] =
              std::find(bells.begin(), bells.end(), merge(bell, s, t)) -
              bells.begin();
        }
      }
      for (int i = 0; i < m; ++i) {
        buffer[i] = bell[t[i] - 'a'];
      }
      buffer[m] = -1;
      for (int i = 0; i < n; ++i) {
        buffer[m + 1 + i] = bell[s[i] - 'a'];
      }
      z[0] = 0;
      for (int i = 1, j = 0; i < m + 1 + n; ++i) {
        z[i] = i < j + z[j] ? std::min(z[i - j], j + z[j] - i) : 0;
        while (i + z[i] < m + 1 + n && buffer[z[i]] == buffer[i + z[i]]) {
          z[i]++;
        }
        if (i + z[i] > j + z[j]) {
          j = i;
        }
      }
      for (int i : queue[bid]) {
        int lcp = z[m + 1 + i];
        if (lcp < m) {
          int x = bell[s[i + lcp] - 'a'];
          int y = bell[t[lcp] - 'a'];
          result[i]++;
          //   std::cout << KV(i) << KV(lcp) << KV(x) << KV(y) << KV(sub[x][y])
          //             << KV(bells[sub[x][y]]) << std::endl;
          queue[sub[x][y]].push_back(i);
        } else {
          //   std::cout << KV(i) << "DONE" << std::endl;
        }
      }
      //   std::cout << "---" << std::endl;
    }
  }
  for (int i = 0; i + m <= n; ++i) {
    printf("%d%c", result[i], " \n"[i + m == n]);
  }
}