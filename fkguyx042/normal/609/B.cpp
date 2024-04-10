#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,b[N];
int main()
{
	  scanf("%d%d",&n,&m);
	  for (i=1;i<=n;++i) scanf("%d",&k),b[k]++;
	  long long ans=0;
	  for (i=1;i<=m;++i) ans+=1ll*b[i]*(n-b[i]);
	  printf("%I64d\n",ans/2);
}