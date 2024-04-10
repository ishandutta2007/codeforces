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
int i,j,m,p,k,a[20];
long long n,ans;
int gcd(int x,int y) { return !y?x:gcd(y,x%y); }
int lcm(int x,int y)
{
	 return x*y/gcd(x,y);
}
int main()
{
	  scanf("%I64d",&n);
	  for (i=0;i<9;++i) a[i]=i+2;
	  int Lim=(1<<9);
	  for (i=0;i<Lim;++i)
      {
      	    int S=1,P=0;
      	    for (j=0;j<9;++j)
      	      if (i&(1<<j)) ++P,S=lcm(S,a[j]);
      	    if (P&1) ans-=n/S; else ans+=n/S;
      }
      printf("%I64d\n",ans);
}