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

#define N 2000005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,f[N],a[N];
int main()
{
	  scanf("%d%d",&n,&k);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]); sort(a+1,a+n+1); n=unique(a+1,a+n+1)-(a+1);
	  int Str=a[1];
	  for (i=1;i<=n;++i) a[i]-=Str;
	  memset(f,60,sizeof(f));
	  f[0]=0;
	  for (i=2;i<=n;++i) 
	    for (j=0;j<=a[i]*k;++j)
		   f[j+a[i]]=min(f[j+a[i]],f[j]+1);
	  for (i=0;i<N;++i) if (f[i]<=k) printf("%d ",i+Str*k);
}