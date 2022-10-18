#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 100005;

int n, k;
char s[MAXN];

int main(void) 
{
  scanf("%d%d", &n, &k);
  scanf("%s", s);

  REP(i, n) {
    int v = s[i] - 'a';

    if (v > 25 - v) {
      int take = min(v, k);
      v -= take;
      k -= take;
    } else {
      int take = min(25 - v, k);
      v += take;
      k -= take;
    }

    s[i] = v + 'a';
  }

  if (k) puts("-1");
  else puts(s);

  return 0;
}