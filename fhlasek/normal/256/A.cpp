/* Written by Filip Hlasek 2012 */
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

#define MAXN 4444
int a[MAXN];
int N;

vector<int> v[1111111], w[MAXN];
int step = 1;

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
  REP(i, N) v[a[i]].push_back(i);
  int W = 0;
  REP(i, 1111111) if(v[i].size()) w[W++] = v[i];
  int best = 1;
  REP(i, W){
    best = max(best, (int)w[i].size());
    REP(j, i){
      int pos1 = 0, pos2 = 0, r = 0, ans = 0, last = -1;
      if(w[i][0] > w[j][0]) r = 1;
      while(true){
        if(r == 0){
          while(pos1 < w[i].size() && w[i][pos1] < last) pos1++;
          if(pos1 < w[i].size()) ans++;
          else break;
          last = w[i][pos1++];
          r = 1;
        }
        else{
          while(pos2 < w[j].size() && w[j][pos2] < last) pos2++;
          if(pos2 < w[j].size()) ans++;
          else break;
          last = w[j][pos2++];
          r = 0;
        }
      }
      best = max(best, ans);
    }
  }
  printf("%d\n", best);
  return 0;
}