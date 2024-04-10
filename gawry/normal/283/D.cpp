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
const int MAX=5010;
int n,t[MAX],cnt[MAX];
int64 a[MAX],r[MAX];
bool ok(int prev,int next){
  if(r[prev]%r[next])return false;
  int diff=cnt[next]-cnt[prev];
  if(diff==next-prev)return true;
  return cnt[next]<=next-prev-1;
}
main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%I64d",&a[i]);
    r[i]=a[i];
    cnt[i]=0;
    while(r[i]%2==0){
      ++cnt[i];
      r[i]/=2;
    }
  }
  for(int i=n;i>=1;i--){
    t[i]=1;
    for(int j=i+1;j<=n;j++)if(ok(i,j)){
      t[i]=max(t[i],1+t[j]);
    }
  }
  printf("%d\n",n-*max_element(t+1,t+n+1));
}