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
#define Mo 100

using namespace std;
int i,j,m,p,k;
long long n;
int power(int x,long long y)
{
	  int sum=1;
	  for (;y;y>>=1,(x*=x)%=Mo) if (y&1) (sum*=x)%=Mo;
	  return sum;
}
int main()
{
	 scanf("%I64d",&n);
	 printf("%d\n",power(5,n));
}