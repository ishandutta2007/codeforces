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

bool mp[256];
char s[20];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  mp['A'] = true;
  mp['E'] = true;
  mp['F'] = true;
  mp['H'] = true;
  mp['I'] = true;
  mp['K'] = true;
  mp['L'] = true;
  mp['M'] = true;
  mp['N'] = true;
  mp['T'] = true;
  mp['V'] = true;
  mp['W'] = true;
  mp['X'] = true;
  mp['Y'] = true;
  mp['Z'] = true;
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    cnt += mp[s[i]];
  if (cnt == 0 || cnt == n)
    puts("YES");
  else
    puts("NO");

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}