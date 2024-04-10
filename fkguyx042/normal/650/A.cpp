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
int i,j,m,n,p,k,x,y;
map<int,int>mpx,mpy;
map<pair<int,int>,int>mp;
int main()
{
	  scanf("%d",&n);
	  long long ans=0;
	  for (i=1;i<=n;++i)
	  {
	  	 scanf("%d%d",&x,&y);
	  	 ans+=mpx[x]; ans+=mpy[y];
	  	 ans-=mp[mk(x,y)];
	  	 mpx[x]++; mpy[y]++;
	  	 mp[mk(x,y)]++;
	  }
	  printf("%I64d\n",ans);
}