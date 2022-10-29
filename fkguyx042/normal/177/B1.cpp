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
int i,j,m,n,p,k;
int main()
{
	 scanf("%d",&n);
	 long long ans=0;
	 while (n>1)
	 {
	 	  ans+=n;
		  for (i=2;i*i<=n;++i) if (n%i==0) break;
		  if (n%i==0) n=n/i;
		  else n=1;
	 }
	 ans+=n;
	 printf("%I64d\n",ans); 
}