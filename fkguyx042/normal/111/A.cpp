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
int i,j,m,n,p,k,y,a[N];
long long x;
int main()
{
	 scanf("%d%I64d%d",&n,&x,&y);
	 if (y<n) puts("-1");
	 else 
	 {
	    for (i=1;i<n;++i) a[i]=1,--y;
		a[n]=y;
		for (i=1;i<=n;++i) x-=1ll*a[i]*a[i];
		if (x>0) puts("-1");
	    else for (i=1;i<=n;++i) printf("%d\n",a[i]);
	 }
}