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
int n,m;
const int POWER=1<<17;
int64 sum[2*POWER],maks[2*POWER];
void fix(int pos){
  if(pos<POWER){
    sum[pos]=sum[pos*2]+sum[pos*2+1];
    maks[pos]=max(maks[pos*2],maks[pos*2+1]);
  }
}
void change(int pos,int val){
  pos+=POWER;
  sum[pos]=maks[pos]=val;
  while(pos/=2){
    fix(pos);
  }
}
void descend(int pos,int mod){
  if(pos>=POWER){
    maks[pos]=sum[pos]=sum[pos]%mod;
  }else if(maks[pos]>=mod){
    descend(pos*2,mod);
    descend(pos*2+1,mod);
  }
  fix(pos);
}
void modulo(int from,int to,int mod){
  from+=POWER;
  to+=POWER;
  descend(from,mod);
  descend(to,mod);
  while(from+1<to){
    if(from%2==0)descend(from+1,mod);
    if(to%2==1)descend(to-1,mod);
    fix(from);
    fix(to);
    from/=2;
    to/=2;
  }
  while(from){
    fix(from);
    from/=2;
  }
  while(to){
    fix(to);
    to/=2;
  }
}
int64 calc(int from,int to){
  from+=POWER;
  to+=POWER;
  int64 ans=sum[from];
  if(from<to)ans+=sum[to];
  while(from+1<to){
    if(from%2==0)ans+=sum[from+1];
    if(to%2==1)ans+=sum[to-1];
    from/=2;
    to/=2;
  }
  return ans;
}
int main(){
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    change(i,x);
  }
  while(m--){
    int type,from,to,k,x;
    scanf("%d",&type);
    if(type==3){
      scanf("%d %d",&k,&x);
      change(k-1,x);
    }else if(type==2){
      scanf("%d %d %d",&from,&to,&x);
      modulo(from-1,to-1,x);
    }else if(type==1){
      scanf("%d %d",&from,&to);
      printf("%I64d\n",calc(from-1,to-1));
    }
  }
  return 0;
}