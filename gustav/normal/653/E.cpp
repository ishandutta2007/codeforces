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

const int MAXN = 300005;

set< int > S[MAXN];
int uf[MAXN];
int find(int i) { return i == uf[i] ? i : uf[i] = find(uf[i]); }

void fail() {
  puts("impossible");
  exit(0);
}

int main(void) 
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  int block_1 = 0;

  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    S[a].insert(b);
    S[b].insert(a);
    if (a == 1 || b == 1) ++block_1;
  }

  if (n - 1 - block_1 < k) fail();

  FOR(i, 1, n + 1) uf[i] = i;
  REP(it, 40) {
    FOR(i, 2, n + 1) {
      if (find(i) != i) continue;
      int j = 2;
      while (find(j) == i || S[i].find(j) != S[i].end()) ++j;
      if (j > n) continue;

      j = find(j);
      vector< int > bad;
      for (int x : S[i])
	if (S[j].find(x) == S[j].end())
	  bad.push_back(x);

      S[j].clear();
      for (int x : bad) S[i].erase(x);
      uf[j] = i;
    }
  }

  int com = 0;
  FOR(i, 2, n + 1) {
    if (find(i) != i) continue;
    if (S[i].find(1) != S[i].end()) fail();
    ++com;
  }


  if (com > k) fail();
  puts("possible");

  return 0;
}