/* Written by Filip Hlasek 2013 */
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

int main(int argc, char *argv[]){
  int N; 
  scanf("%d", &N);
  long long vol = 0;
  int x1, x2, y1, y2, maxx = 0, maxy = 0, minx = 1000000, miny = 1000000;
  REP(i, N) {
    scanf("%d%d%d%d", &x1, &y1, &x2 ,&y2);
    vol += (long long)(x2 - x1) * (y2 - y1);
    maxx = max(x2, maxx);
    maxy = max(y2, maxy);
    minx = min(x1, minx);
    miny = min(y1, miny);
  }
  if (maxx - minx == maxy - miny && (long long)(maxx - minx) * (maxy - miny) == vol) printf("YES\n");
  else printf("NO\n");
  return 0;
}