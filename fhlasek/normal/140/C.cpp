/* Writen by Filip Hlasek 2011 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define MAXN 111111

int a[MAXN],N,res[MAXN][3],R=0;
set< pair<int,int> > s;

bool snowmen(){
  pair<int,int> x,y,z;
  if(s.empty()) return false;
  x=*(--(s.end()));
  s.erase(x);
  if(s.empty()) return false;
  y=*(--(s.end()));
  s.erase(y);
  if(s.empty()) return false;
  z=*(--(s.end()));
  s.erase(z);
  res[R][0]=x.second;
  res[R][1]=y.second;
  res[R][2]=z.second;
  R++;
//  printf("(%d %d),(%d %d),(%d %d) size:%d\n",x.first,x.second,y.first,y.second,z.first,z.second,(int)s.size());
  if(--x.first) s.insert(x);
  if(--y.first) s.insert(y);
  if(--z.first) s.insert(z);
  return true;
}

int main(int argc, char *argv[]){
  scanf("%d",&N);
  REP(i,N) scanf("%d",a+i);   
  sort(a,a+N);
  for(int i=0;i<N;){
    for(int j=0;;j++){
      if((i+j)==N||a[i]!=a[i+j]){
        s.insert(make_pair(j,a[i]));
        i+=j;
        break;
      }
    }
  }
  while(snowmen());
  printf("%d\n",R);
  REP(i,R){
    sort(res[i],res[i]+3,greater<int>() );
    printf("%d %d %d\n",res[i][0],res[i][1],res[i][2]);
  }
  return 0;
}