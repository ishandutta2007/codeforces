#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define MAXN 10005

int n;
int x[MAXN];
int y[MAXN];
vector< pair< int, int > > X, Y;

void reduce(int *x, int n, vector< pair< int, int > > &ops) {
  int r = 0;
  for (int c = 0; c < 30; ++c) {
    if (((x[r] >> c) & 1) == 0) {
      int b = -1;

      for (int i = r; i < n; ++i) 
        if (((x[i] >> c) & 1) == 1)
          b = i;

      if (b == -1) continue;

      x[r] ^= x[b]; ops.push_back({r, b});
      x[b] ^= x[r]; ops.push_back({b, r});
      x[r] ^= x[b]; ops.push_back({r, b});
    }

    for (int i = 0; i < n; ++i) {
      if (i == r) continue;
      if (((x[i] >> c) & 1) == 0) continue;
      x[i] ^= x[r]; ops.push_back({i, r});
    }

    ++r;
  }
}

int lcp(int a, int b) {
  for (int i = 0; i < 30; ++i) 
    if (((a >> i) & 1) != ((b >> i) & 1))
      return i;
  return 30;
}

void make_equal(int *x, int *y, vector< pair< int, int > > &ops) {
  for (int i = 0; i < 30; ++i) {
    if (x[i] == y[i]) continue;
    for (int j = i; j < 30; ++j) {
      if (lcp(x[i] ^ x[j], y[i]) > lcp(x[i], y[i])) {
        x[i] ^= x[j]; ops.push_back({i, j});
      }
    }
  }
}

void output(int *x, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 30; ++j) {
      printf("%d", ((x[i] >> j) & 1));
    }
    puts("");
  }
}

int main(void)
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", x + i);
  REP(i, n) scanf("%d", y + i);

  reduce(x, n, X);
  reduce(y, n, Y);
  make_equal(x, y, X);

  //output(x, n);
  //output(y, n);

  REP(i, n) {
    if (x[i] != y[i]) {
      puts("-1");
      exit(0);
    }
  }

  printf("%d\n", X.size() + Y.size());
  for (auto i : X) printf("%d %d\n", i.first + 1, i.second + 1);
  reverse(Y.begin(), Y.end());
  for (auto i : Y) printf("%d %d\n", i.first + 1, i.second + 1);


  return 0;
}