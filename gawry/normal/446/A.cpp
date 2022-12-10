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
const int MAX=110000;
int main(){
  int n,ends[MAX],starts[MAX],t[MAX];
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&t[i]);
  for(int i=1;i<=n;i++)ends[i]=t[i]>t[i-1]?ends[i-1]+1:1;
  for(int i=n;i>=1;i--)starts[i]=t[i]<t[i+1]?starts[i+1]+1:1;
  int ans=0;
  for(int i=1;i<=n;i++)ans=max(ans,starts[i]+(i>1));
  for(int i=1;i<=n;i++)ans=max(ans,ends[i]+(i<n));
  for(int i=1;i+2<=n;i++)if(t[i]+1<t[i+2])ans=max(ans,ends[i]+1+starts[i+2]);
  printf("%d\n",ans);
  return 0;
}