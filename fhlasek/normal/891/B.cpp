/* Written by Filip Hlasek 2017 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MAXN 111111
int A[MAXN];
int N;

void solve() {
  vector< pair<int, int> > v;
  REP(i, N) v.push_back(make_pair(A[i], i));
  sort(v.begin(), v.end());
  REP(i, N) swap(v[i].first, v[i].second);
  FORD(i, N - 2, 0) swap(v[i].second, v[i + 1].second);
  sort(v.begin(), v.end());
  REP(i, N) {
    if (i)  printf(" ");
    printf("%d", v[i].second);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  solve();
  return 0;
}