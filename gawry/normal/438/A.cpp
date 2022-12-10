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
int n,m,x[2010],y[2010],v[2010];
int main(){
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++)scanf("%d",&v[i]);
  for(int i=0;i<m;i++)scanf("%d %d",&x[i],&y[i]);
  int ans=0;
  for(int i=0;i<m;i++)ans+=min(v[x[i]],v[y[i]]);
  printf("%d\n",ans);
  return 0;
}