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
long long C(int x,int y)
{
	  long long S=1;
	  for (i=x-y+1;i<=x;++i) S*=i;
	  for (i=1;i<=y;++i) S/=i;
	  return S;
}
int main()
{
	  scanf("%d",&n);
	  printf("%I64d\n",1ll*C(n,5)*C(n,5)*120);
}