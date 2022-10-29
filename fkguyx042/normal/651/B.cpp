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

#define N 1005
#define M 1000
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,a[N],x,ans;
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d",&x),a[x]++;
	  int last=0;
	  for (i=1;i<=n;++i) 
	  {
	  	  for (j=last+1;j<=M;++j) if (a[j]) break;
	  	  if (j<=M) last=j,++ans,a[j]--;
	  	  else 
	  	  {
	  	  	  for (j=1;j<=M;++j) if (a[j]) break;
	  	  	  a[j]--;
	  	  	  last=j;
	  	  }
	  }
	  printf("%d\n",ans-1);
}