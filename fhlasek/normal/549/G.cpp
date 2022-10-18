/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

vector< pair<int, int> > v;

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    int a;
    scanf("%d", &a);
    v.push_back(make_pair(a + i, i));
  }
  sort(v.begin(), v.end());
  bool ok = true;
  REP(i, N - 1) if (v[i].first == v[i + 1].first) ok = false;
  if (!ok) printf(":(\n");
  else {
    REP(i, N) {
      if (i) printf(" ");
      printf("%d", (v[i].first - v[i].second) + (v[i].second - i));
    }
    printf("\n");
  }
  return 0;
}