#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
const int POWER=1<<17;
int n,q,cnt[2*POWER];
int calc(int from,int to){
  from+=POWER;
  to+=POWER;
  int ans=cnt[from];
  if(from<to)ans+=cnt[to];
  while(from+1<to){
    if(from%2==0)ans+=cnt[from+1];
    if(to%2)ans+=cnt[to-1];
    from/=2;
    to/=2;
  }
  return ans;
}
void increase(int pos,int delta){
  pos+=POWER;
  while(pos){
    cnt[pos]+=delta;
    pos/=2;
  }
}
int main(){
  scanf("%d %d",&n,&q);
  int start=0,end=n-1;
  for(int i=start;i<=end;i++)increase(i,1);
  bool reverse=false;
  while(q--){
    int x,y,z;
    scanf("%d %d",&x,&y);
    //printf("%d %d %d\n",start,end,(int)reverse);
    if(x==1){
      if(reverse){
        y=end-y+1;
      }else{
        y=y+start;
      }
      if(end-y<y-start){
        for(int i=y;i<=end;i++)increase(2*y-i-1,cnt[POWER+i]);
        end=y-1;
        reverse=true;
      }else{
        for(int i=start;i<y;i++)increase(2*y-i-1,cnt[POWER+i]);
        start=y;
        reverse=false;
      }
    }else{
      scanf("%d",&z);
      printf("%d\n",reverse?calc(end-z+1,end-y):calc(start+y,start+z-1));
    }
  }
  return 0;
}