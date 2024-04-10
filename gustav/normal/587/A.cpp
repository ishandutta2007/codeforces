#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 1000005;

int n;
int a[MAXN];

int main(void) 
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", a + i);
  sort(a, a + n);

  deque< int > dq;
  for (int i = n - 1; i >= 0; --i) {
    dq.push_front(a[i]);

    while (dq.size() >= 2 && dq[0] == dq[1]) {
      int v = dq[0];
      dq.pop_front();
      dq.pop_front();
      dq.push_front(v + 1);
    }
  }

  printf("%d\n", (int)dq.size());

  return 0;
}