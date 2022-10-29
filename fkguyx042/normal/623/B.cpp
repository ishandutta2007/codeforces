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

#define N 1000005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,a[N],Q[N],A,B;
long long f[N][3];
void work(int x)
{
	  int i;
	  for (i=2;i*i<=x;++i) 
	     while (x%i==0) x/=i,Q[++Q[0]]=i; 
	  if (x>1) Q[++Q[0]]=x;
}
void Min(long long &a,long long b) { a=min(a,b); }
long long get(int x)
{ 
   int i,j;
   memset(f,60,sizeof(f)); f[0][0]=0;
   for (i=1;i<=n;++i) 
   {
   	    Min(f[i][1],f[i-1][1]+A);
   	    Min(f[i][1],f[i-1][0]+A);
   	    if (a[i]%x==0) 
   	    {  
   	       Min(f[i][0],f[i-1][0]);
   	       Min(f[i][2],f[i-1][1]);
   	       Min(f[i][2],f[i-1][2]);
   	   }
   	   else if ((a[i]-1)%x==0||(a[i]+1)%x==0) 
   	   {
   	   	  Min(f[i][0],f[i-1][0]+B);
   	   	  Min(f[i][2],min(f[i-1][2],f[i-1][1])+B);
   	   }
   }
   long long sum=(long long)1e18;
   for (i=0;i<3;++i) sum=min(sum,f[n][i]);
   return sum;
}
int main()
{
	  scanf("%d%d%d",&n,&A,&B);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]);
	  work(a[1]); work(a[1]-1); work(a[n]); work(a[n]+1); work(a[n]-1); work(a[1]+1);
	  sort(Q+1,Q+Q[0]+1); Q[0]=unique(Q+1,Q+Q[0]+1)-(Q+1);
	  long long ans=(long long)1e18;
	  for (i=1;i<=Q[0];++i) ans=min(ans,get(Q[i]));
	  printf("%I64d\n",ans);  
}