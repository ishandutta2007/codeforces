/* Written by Filip Hlasek 2016 */
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

#define MAXN 111111

vector<int> v;

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    v.push_back(1);
    while (v.size() >= 2 && v.back() == v[v.size() - 2]) {
      v.pop_back();
      v[v.size() - 1]++;
    }
  }
  REP(i, v.size()) {
    if (i) printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}