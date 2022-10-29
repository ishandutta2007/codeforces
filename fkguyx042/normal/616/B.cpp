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
int i,j,m,n,p,k,x;
int main()
{
	 scanf("%d%d",&n,&m); int ans=0;
	 for (i=1;i<=n;++i)
	 {
	 	 int sum=(int)1e9;
	     for (j=1;j<=m;++j) scanf("%d",&x),sum=min(sum,x);
	     ans=max(ans,sum);
	 }
	 printf("%d\n",ans);
}