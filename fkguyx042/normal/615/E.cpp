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
int i,j,m,p,k;
long long n;
void pt(long long x,long long y)
{
	  printf("%I64d %I64d\n",x,y);
	  exit(0);
}
void work(int l,long long x,long long y)
{
	   if (n<=l)
	   {
	   	   x+=n;
	   	   y+=2*n;
	   	   pt(x,y);
	   }
	   x+=l; y+=2*l; n-=l;
//2...................
	   if (n<=l-1)
	   {
	   	   x-=n; y+=2*n;
		   pt(x,y);
	   }
	   x-=(l-1); y+=2*(l-1); n-=(l-1);
//3...................
	   if (n<=l)
	   {
	   	   x-=2*n;
	   	   pt(x,y);
	   }
	   x-=2*l; n-=l;
//4...................
	   if (n<=l) 
	   {
	   	  x-=n; y-=2*n;
	   	  pt(x,y);
	   }
	   x-=l; y-=2*l; n-=l;
//5...................
       if (n<=l)
       {
       	    x+=n; y-=2*n;
       	    pt(x,y);
       }
       x+=l; y-=2*l; n-=l;
//6...................
       x+=2*n;
       pt(x,y);
}
int main()
{
	  int l=0,r=(int)1e9,mid=0;
	  scanf("%I64d",&n); if (!n) printf("0 0\n");
	  else 
	  {
	    while ((l+r)>>1!=mid)
	    {
	  	  mid=(l+r)>>1;
	  	  if (1ll*mid*(4ll+6ll*mid)/2<n) l=mid; else r=mid;
	    }
	    n-=1ll*mid*(4ll+6ll*mid)/2;
	    work(l+1,l,-2*l);
	 }
}