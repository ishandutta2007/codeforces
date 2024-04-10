#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <complex>

using namespace std;

char str1[200002], str2[200002];
const int K = 4096;

unsigned int aw[200002];
unsigned int bw[200002];
short bit[1<<16];

short cnt[200002 / K + 1][200002];

int main() {
  gets(str1);
  gets(str2);

  int l1 = strlen(str1), l2 = strlen(str2);
  for (int i = 0; i < l1; ++i) {
    unsigned int one = 1;
    for (int j = 0; j < 32 && i + j < l1; ++j) {
      if (str1[i + j] == '1')
        aw[i] |= one;
      one <<= 1;
    }
  }
  for (int i = 0; i < l2; ++i) {
    unsigned int one = 1;
    for (int j = 0; j < 32 && i + j < l2; ++j) {
      if (str2[i + j] == '1')
        bw[i] |= one;
      one <<= 1;
    }
  }

  bit[0] = 0;
  for (int i = 1; i < (1<<16); ++i) {
    bit[i] = (i & 1) + bit[i >> 1];
  }

  // cout << sizeof(cnt) / 1024.0 / 1024 << endl;
  int IT = K >> 5, MASK = (1<<16) - 1;
  for (int i = 0; i + K <= l1; i += K) {
    int ind = i / K;
    for (int j = 0; j + K <= l2; ++j) {
      int p1 = i, p2 = j;
      for (int t = 0; t < IT; ++t) {
        unsigned int mask = aw[p1] ^ bw[p2];
        cnt[ind][j] += bit[mask & MASK] + bit[mask >> 16];
        p1 += 32; p2 += 32;
      }
    }
  }

  int q, p1, p2, len;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d", &p1, &p2, &len);
    int ans = 0;
    int pos = (p1 / K) * K, r = p1 + len - 1;
    while (pos < p1) pos += K;
    for (int i = p1; i < pos && i <= r; ++i) {
      ans += str1[i] != str2[p2];
      ++p2;
    }
    if (pos <= r) {
      while (pos + K - 1 <= r) {
        ans += cnt[pos / K][p2];
        pos += K; p2 += K;
      }
      for (int i = pos; i <= r; ++i) {
        ans += str1[i] != str2[p2];
        ++p2;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}