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
	  scanf("%d%d",&n,&m);
	  int l=0,r=10000000,mid=0;
	  while ((l+r)>>1!=mid)
	  {
	  	 mid=(l+r)>>1;
	  	 int A=mid/2,B=mid/3,C=mid/6;
	  	 A-=C,B-=C;
	  	 if (A+B+C>=n+m&&A+C>=n&&B+C>=m) r=mid; else l=mid;
	  }
	  printf("%d\n",r);
}