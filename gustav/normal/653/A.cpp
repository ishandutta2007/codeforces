#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 55;

int N;
int t[MAX];

int main(void) 
{
  scanf("%d", &N);
  REP(i, N) scanf("%d", t + i);

  REP(i, N) FOR(j, i + 1, N) FOR(k, j + 1, N) {
    vector< int > v = {t[i], t[j], t[k]};
    sort(v.begin(), v.end());
    if (v[2] - v[0] > 2) continue;
    if (v[0] == v[1] || v[1] == v[2]) continue;
    puts("YES");
    exit(0);
  }

  puts("NO");

  return 0;
}