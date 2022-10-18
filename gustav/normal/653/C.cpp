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

const int MAXN = 150005;

int N;
int t[MAXN];

bool good(int i) {
  if (i < 0 || i >= N - 1) return true;
  if (i % 2 == 0)
    return t[i] < t[i + 1];
  return t[i] > t[i + 1];
}

int main(void) 
{
  scanf("%d", &N);
  REP(i, N) scanf("%d", t + i);

  int cnt = 0;
  REP(i, N) cnt += !good(i);

  if (cnt > 6) {
    puts("0");
    exit(0);
  }

  set< pair< int, int > > swaps;

  REP(i, N) {
    if (good(i) && good(i - 1)) continue;

    REP(j, N) {
      if (i == j) continue;


      int ccnt = cnt;
      
      ccnt -= !good(i);
      ccnt -= !good(i - 1);
      ccnt -= !good(j);
      ccnt -= !good(j - 1);


      if (i + 1 == j) ccnt += !good(i);
      if (j + 1 == i) ccnt += !good(j);

      swap(t[i], t[j]);

      ccnt += !good(i);
      ccnt += !good(i - 1);
      ccnt += !good(j);
      ccnt += !good(j - 1);

      if (i + 1 == j) ccnt -= !good(i);
      if (j + 1 == i) ccnt -= !good(j);

      if (ccnt == 0) swaps.insert({min(i, j), max(i, j)});

      swap(t[i], t[j]);
    }
  }

  printf("%d\n", (int)swaps.size());

  return 0;
}