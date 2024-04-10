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
int A[MAXN], o[MAXN];
bool done[MAXN];
int N;

bool cmp(int x, int y) {
  return A[x] < A[y];
}

vector< vector<int> > ans;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) {
    scanf("%d", A + i);
    o[i] = i;
  }
  sort(o, o + N, cmp);

  REP(i, N) if (!done[i]) {
    vector<int> tmp;
    tmp.push_back(i);
    int j = o[i];
    done[i] = true;
    while (j != i) {
      done[j] = true;
      tmp.push_back(j);
      j = o[j];
    }
    ans.push_back(tmp);
  }

  printf("%d\n", (int)ans.size());
  REP(i, ans.size()) {
    printf("%d", (int)ans[i].size());
    REP(j, ans[i].size()) printf(" %d", ans[i][j] + 1);
    printf("\n");
  }

  return 0;
}