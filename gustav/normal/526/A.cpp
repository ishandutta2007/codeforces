#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 105;

char s[MAXN];

int main(void) 
{
  int n; scanf("%d", &n);
  scanf("%s", s);

  FOR(len, 1, n + 1) {
    REP(i, n) {
      bool ok = true;
      REP(j, 5) {
	int x = i + j * len;
	if (x >= n || s[x] != '*') ok = false;
      }
      if (ok) {
	puts("yes");
	exit(0);
      }
    }
  }
  puts("no");
  return 0;
}