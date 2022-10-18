#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

bool isPrime(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0)
      return false;
  return true;
}

int nextPrime(int x) {
  while (!isPrime(x))
    ++x;

  return x;
}

int mod = nextPrime(999000000 + rand() % 30000);
int base = 31 + rand() % 61;
int bpow[200002];

char str1[200002], str2[200002];


int calc(char str[200002], int l, int r) {
  if ((r - l + 1) & 1) {
    int h = 0;
    for (int i = l; i <= r; ++i) {
      h = (1LL * h * base + str[i] - 'a' + 1) % mod;
    }
    return h;
  }
  int m = (l + r) >> 1;
  int v1 = calc(str, l, m), v2 = calc(str, m + 1, r);
  if (v1 > v2)
    swap(v1, v2);

  return (1LL * v1 * bpow[m - l + 1] + v2) % mod;
}

int main() {
  if (base % 2 == 0) ++base;

  bpow[0] = 1;
  for (int i = 1; i <= 200000; ++i)
    bpow[i] = 1LL * bpow[i - 1] * base % mod;

  gets(str1);
  gets(str2);

  int len = strlen(str1);
  puts(calc(str1, 0, len - 1) == calc(str2, 0, len - 1) ? "YES" : "NO");

  return 0;
}