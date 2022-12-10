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
const int MOD=1000000000+7;
int n,q,t,a[310],in[310],out[310],c[1000000+1];
main(){
  scanf("%d %d %d",&n,&q,&t);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  for(int i=0;i<q;i++){
    int b,c;
    scanf("%d %d",&c,&b);
    out[b]=c;
    in[c]=b;
  }
  bool cycle=false;
  for(int i=1;i<=n;i++)if(in[i]&&!out[i]){
    int cur=i;
    while(in[cur]){
    //  printf("%d %d\n",cur,a[cur]);
      int prev=in[cur];
      t-=a[cur];
      if(t<0)cycle=true;
      a[prev]+=a[cur];
      in[cur]=0;
      cur=prev; 
    }
  }
  for(int i=1;i<=n;i++)if(in[i])cycle=true;
  if(cycle){
    puts("0");
  }else{
    c[0]=1;
    for(int i=1;i<=n;i++)for(int j=a[i];j<=t;j++){
      c[j]+=c[j-a[i]];
      if(c[j]>=MOD)c[j]-=MOD;
    }
    printf("%d\n",c[t]);
  }
}