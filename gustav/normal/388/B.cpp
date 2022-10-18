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

#define MAX 1005

int k;
char m[MAX][MAX];
int alloc = 3;

void add_edge(int a, int b) {
  --a; --b;
  m[a][b] = m[b][a] = 'Y';
}

void attach(int n, int cnt) {
  vector< int > add;
  REP(i, cnt) {
    add.push_back(alloc);
    add_edge(n, alloc);
    ++alloc;
  }
  REP(i, cnt)
    add_edge(add[i], alloc);
  ++alloc;
}

int main(void)
{
  scanf("%d", &k);

  int base = 8;
  int top = 10;
  for (int i = top; i >= 0; --i){
    int q = ((k >> (3 * i)) % base);
    if (q == 0) continue;

    attach(1, q);
    REP(j, i) attach(alloc - 1, 8);
    REP(j, top - i) attach(alloc - 1, 1);
    add_edge(alloc - 1, 2);
  }

  int n = alloc - 1;
  printf("%d\n", n);

  REP(i, n) REP(j, n) if (!m[i][j]) m[i][j] = 'N';
  REP(i, n) puts(m[i]);

  return 0;
}