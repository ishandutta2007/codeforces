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

#define MAXN 1024

int N, P;
char s[MAXN];
int memo[MAXN][28][28][2];

bool exists(int pos, int p, int pp, bool change) {
  if (pos == N) return change;

  int &ret = memo[pos][p][pp][change];
  if (ret >= 0) return ret;

  ret = 0;
  
  int start = change ? 0 : s[pos] - 'a';
  int finish = P;

  FOR(i, start, finish) {
    if (i == p || i == pp) continue;
    if (exists(pos + 1, i, p, change || i != s[pos] - 'a'))
      ret = 1;
  }

  return ret;
}

void construct(int pos, int p, int pp, bool change) {
  if (pos == N) return;
  
  int start = change ? 0 : s[pos] - 'a';
  int finish = P;

  FOR(i, start, finish) {
    if (i == p || i == pp) continue;
    if (exists(pos + 1, i, p, change || i != s[pos] - 'a')) {
      putchar(i + 'a');
      construct(pos + 1, i, p, change || i != s[pos] - 'a');
      return;
    }
  }
}

int main(void)
{
  memset(memo, -1, sizeof memo);

  scanf("%d%d", &N, &P);
  scanf("%s", s);

  if (!exists(0, 27, 27, 0))
    puts("NO");
  else {
    construct(0, 27, 27, 0);
    puts("");
  }

  return 0;
}