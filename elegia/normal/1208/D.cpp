#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>
 
#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200010;

int n;
int p[N];
ll s[N], fw[1 << 18];

int lowBit(int k) { return k & -k; }

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &s[i]);
  for (int i = 1; i <= n; ++i) fw[i] = i;
  for (int i = 1; i < (1 << 18); ++i) fw[i] += fw[i - 1];
  for (int i = (1 << 18) - 1; i; --i) fw[i] -= fw[i - lowBit(i)];
  for (int i = n; i; --i) {
    int k = 0;
    for (int j = 17; j >= 0; --j)
      if (s[i] >= fw[k | (1 << j)])
        s[i] -= fw[k |= 1 << j];
    p[i] = ++k;
    for (; k < (1 << 18); k += lowBit(k)) fw[k] -= p[i];
  }
  for (int i = 1; i <= n; ++i) printf("%d ", p[i]);
  return 0;
}