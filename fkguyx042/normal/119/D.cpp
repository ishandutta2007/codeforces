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
#define Mid ((l+r)>>1)
#define N 1000005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,sum[N],hash[N],Hash[N],a[N],b[N],pow[N],ansx,ansy,id;
char c[N],s[N],r;
bool check(int x)
{
	  int Maxl=a[x+1]+1;
	  if (b[Maxl]<n-x+1) return 0;
	  int l=1,r=Maxl,mid=0;
	  while ((l+r)>>1!=mid)
	  {
	  	 mid=(l+r)>>1;
	  	 if (b[mid]>=n-x+1) r=mid; else l=mid;
	  }
	  if (x+r<=n)
	  {
	  	  ansx=x; ansy=x+r; return 1;
	  }
	  return 0;
}
int gethash(int x,int y)
{
	  int z=hash[y]-1ll*hash[x-1]*pow[y-x+1]%Mo;
	  if (z<0) z+=Mo; return z; 
}
int get(int x,int y)
{
	  int z=sum[y]-1ll*sum[x-1]*pow[y-x+1]%Mo;
	  if (z<0) z+=Mo; return z;
}
int main()
{
	  while (r=getchar(),r!='\n') c[++n]=r; 
	  while (r=getchar(),r!='\n') s[++m]=r;
	  pow[0]=1;
	  for (i=1;i<N;++i) pow[i]=1ll*pow[i-1]*seed%Mo;
	  if (n!=m)
	  {
	  	  puts("-1 -1");
	  	  return 0;
	  }
	  for (i=1;i<=n;++i) hash[i]=(1ll*hash[i-1]*seed%Mo+c[i])%Mo;
	  for (i=n;i;--i) Hash[i]=(1ll*Hash[i+1]*seed%Mo+c[i])%Mo;
	  for (i=1;i<=n;++i) sum[i]=(1ll*sum[i-1]*seed%Mo+s[i])%Mo;
	  for (i=1;i<=n;++i)
	  {
	  	   int l=0,r=n-i+2,mid=0;
	  	   while ((l+r)>>1!=mid)
	  	   {
	  	   	mid=(l+r)>>1;
	  	   	if (gethash(i,i+mid-1)==sum[mid]) l=mid; else r=mid;
	  	   }
	  	   a[i]=l;
     }
     for (i=1;i<=n;++i)
     {
     	   int l=0,r=n-i+2,mid=0;
     	   while ((l+r)>>1!=mid)
     	   {
     	   	mid=(l+r)>>1;
     	   	if (get(i,i+mid-1)==Hash[n-mid+1]) l=mid; else r=mid;
     	   }
     	   b[i]=l;
     }

       for (i=1;i<=n;++i) b[i]=max(b[i-1],b[i]+i);
       ansx=ansy=0;
       for (j=1;j<=n;++j) if (s[n-j+1]!=c[j]) break;
	  for (i=j-1;i;--i)
	    if (check(i)) break;
	   printf("%d %d\n",ansx-1,ansy-1);
}