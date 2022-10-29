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
int i,j,m,p,k,flag;
long long n,s,way=1;
int main()
{
	scanf("%I64d%I64d",&n,&s);
	if (n==s) flag=1;
	for (i=50;i>=0;--i)
	{
		   if ((1ll<<i)&s)
		   {
		  	 	n-=(1ll<<i);
		   	    way*=2;
		   }
		   else if (n>=(1ll<<(i+1))) n-=(1ll<<(i+1));
	}	  
	if (n!=0) return puts("0"),0;
	printf("%I64d\n",way-flag*2);
}