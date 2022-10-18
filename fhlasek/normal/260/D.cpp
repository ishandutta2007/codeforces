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

#define MAXN 111111
int N, s[MAXN];
int o1[MAXN], o2[MAXN], O1 = 0, O2 = 0;

bool cmp(int a, int b){ return s[a] < s[b]; }

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N){
    int c;
    scanf("%d%d", &c, s + i);
    if(c) o1[O1++] = i;
    else  o2[O2++] = i;
  }
  sort(o1, o1+O1, cmp);
  sort(o2, o2+O2, cmp);
  int pos1 = 0, pos2 = 0;
  bool start = true;
  int rem = s[o1[0]];
  while(pos1 < O1 && pos2 < O2){
    if(start){
      while(pos2 < O2 && s[o2[pos2]] <= rem){
        printf("%d %d %d\n", o1[pos1] + 1, o2[pos2] + 1, s[o2[pos2]]);
        rem -= s[o2[pos2]];
        pos2++;
      }
      if(pos2 < O2){
        printf("%d %d %d\n", o1[pos1] + 1, o2[pos2] + 1, rem);
        rem = s[o2[pos2]] - rem;
      }
      else{ pos2 = O2-1; rem = 0; }
      pos1++;
    }
    else{
      while(pos1 < O1 && s[o1[pos1]] <= rem){
        printf("%d %d %d\n", o1[pos1] + 1, o2[pos2] + 1, s[o1[pos1]]);
        rem -= s[o1[pos1]];
        pos1++;
      }
      if(pos1 < O1){
        printf("%d %d %d\n", o1[pos1] + 1, o2[pos2] + 1, rem);
        rem = s[o1[pos1]] - rem;
      }
      else{ pos1 = O1-1; rem = 0; }
      pos2++;
    }
    start = !start;
  }
  return 0;
}