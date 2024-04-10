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
int i,j,m,n,p,k,a[N];
int main()
{
	  scanf("%d%d",&n,&m);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]);
	  sort(a+1,a+n+1);
	  for (i=n;i;--i) if (m<=a[i]) break; else m-=a[i];
	  printf("%d\n",n-i+1);
}