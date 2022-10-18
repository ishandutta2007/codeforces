#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
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

const int MAXN = 1000005;

char s[MAXN];
int sol[MAXN];

int main(void)
{
  scanf("%s", s);
  int n = strlen(s);

  int cnt = 0;
  int last = n;

  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == ')')
      ++cnt;
    else if (s[i] == '(') {
      --cnt;
      if (cnt < 0) {
        ++sol[last];
        cnt = 0;
      }
    } else {
      ++cnt;
      last = i;
      ++sol[last];
    }
  }

  bool ok = true;
  cnt = 0;

  REP(i, n) {
    if (s[i] == '(')
      ++cnt;
    else if (s[i] == ')')
      --cnt;
    else
      cnt -= sol[i];
    if (cnt < 0) ok = false;
  }

  if (cnt != 0) ok = false;

  if (!ok) {
    puts("-1");
    exit(0);
  }

  REP(i, n)
    if (s[i] == '#')
      printf("%d\n", sol[i]);

  return 0;
}