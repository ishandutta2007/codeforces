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
int i,j,m,n,p,k,x,y,Q[N],Min[N];
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i)
	  {
	  	   scanf("%d%d",&x,&y); Q[0]=0;
	  	   for (j=1;j*j<=x;++j)  
	  	       if (x%j==0)
	  	       {
	  	       	 Q[++Q[0]]=j;
	  	       	 if (j*j!=x) Q[++Q[0]]=x/j;
	  	       }
	  	    int sum=0;
	  	   for (j=1;j<=Q[0];++j)
	  	   {
	  	   	  if (Min[Q[j]]<i-y) ++sum;
	  	   	  Min[Q[j]]=i;
	  	   }
	  	   printf("%d\n",sum);
	  }
}