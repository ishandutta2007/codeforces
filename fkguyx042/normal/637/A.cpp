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

#define N 1000005
#define M 200005		
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,big[N],a[N];
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]),big[a[i]]++;
	  for (i=1;i<N;++i) p=max(big[i],p);
	  memset(big,0,sizeof(big));
	  for (i=1;i<=n;++i)
	  {
	  	  big[a[i]]++;
	  	  if (big[a[i]]==p) { printf("%d\n",a[i]); return 0; }
	  }
}