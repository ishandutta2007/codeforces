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
int n,t[1000000];
const int MOD=1000000000+7;
const int POWER=1<<20;
int f[POWER],ff[POWER],p2[POWER];
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&t[i]);
    ++f[POWER-1-t[i]];
  }
  for(int i=0;i<20;i++){
    for(int j=0;j<POWER;j++){
      ff[j]=(j&1<<i)?f[j-(1<<i)]+f[j]:f[j];
    }
    memcpy(f,ff,sizeof(ff));
  }
  p2[0]=1;
  for(int i=1;i<POWER;i++)p2[i]=(long long)p2[i-1]*2%MOD;
  int ans=0;
  for(int j=0;j<POWER;j++){
    long long sign=__builtin_popcount(j)%2?MOD-1:1;
    long long tmp=sign*p2[f[POWER-1-j]];
    ans=(ans+tmp)%MOD;
  }

  printf("%d\n",ans);
  return 0;
}