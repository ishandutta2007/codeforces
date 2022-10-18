/* Writen by Filip Hlasek 2012 */
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
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;
#define EPS 1e-9

int main(int argc, char *argv[]){
  int vp,vd,t,f,c,ans=0; 
  scanf("%d%d%d%d%d",&vp,&vd,&t,&f,&c);
  if(vp>=vd){ printf("0\n"); return 0; }
  double time = t;
  while(true){
    time += vp * time / (vd-vp); //catch
    double dist = time * vp;
//    printf("%lf %lf\n",time,dist);
    if(dist + EPS >= c) break;
    time += dist / vd + f;
    ans++;
  }
  printf("%d\n",ans);
  return 0;
}