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
int i,j,m,n,p,k,a[N],b[N],ans;
char c[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",c);
	for (i=n;i;--i) c[i]=c[i-1];
	for (i=1;i<=n;++i)
	{
		  if (c[i]=='U') a[i]=a[i-1]+1,b[i]=b[i-1];
		  if (c[i]=='D') a[i]=a[i-1]-1,b[i]=b[i-1];
		  if (c[i]=='L') b[i]=b[i-1]+1,a[i]=a[i-1]; 
		  if (c[i]=='R') b[i]=b[i-1]-1,a[i]=a[i-1];
	}
	for (i=1;i<=n;++i)
	  for (j=i;j<=n;++j) 
	      if (a[j]==a[i-1]&&b[j]==b[i-1]) ++ans;
    printf("%d\n",ans);
}