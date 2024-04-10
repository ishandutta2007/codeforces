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

#define MAXN 1111
vector<int> v[MAXN];
vector<int> current, tmp;

int main(int argc, char *argv[]) {
  int N, T;
  scanf("%d%d", &N, &T);
  REP(i, N) {
    int t, q;
    scanf("%d%d", &t, &q);
    v[t].push_back(q);
  }
  REP(i, T + 1) {
    tmp.clear();
    if (current.size() % 2) current.push_back(0);
    REP(i, current.size() / 2) tmp.push_back(current[2 * i] + current[2 * i + 1]);
    current = tmp;
    REP(j, v[i].size()) current.push_back(v[i][j]);
    sort(current.begin(), current.end());
    reverse(current.begin(), current.end());
  }
  printf("%d\n", current[0]);
  return 0;
}