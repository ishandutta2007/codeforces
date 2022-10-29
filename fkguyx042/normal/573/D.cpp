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

#define N 30005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
const long long inf=(long long)1e18;
int flag;
int i,j,m,n,p,k,a[N],b[N],c[N],d[N],id[N],id2[N],q,real[N],x,y,New[5];
long long num[N][5],f[N];
inline bool cmp(int A,int B) { return a[A]>a[B]; }
inline bool Cmp(int A,int B) { return b[A]>b[B]; } 
void check(int x,int y)
{
	  int sum=1,len=y-x+1,i;
	  long long Sum=-inf;
	  for (i=1;i<=y-x+1;++i) sum*=i,New[i]=i;
	  for (;sum--;)
	  {
	  	   for (i=1;i<=len;++i)
	  	     if (id[i+x-1]==id2[New[i]+x-1]) break;
	  	    if (i>len) 
	  	    {
	  	    	  long long Ans=0;
	  	    	   for (i=1;i<=len;++i)
	  	    	      Ans+=1ll*c[x+i-1]*d[New[i]+x-1];
	  	    	  Sum=max(Sum,Ans);
	  	    }
	  	    next_permutation(New+1,New+len+1);
	  }
	  num[y][len]=Sum;
}
void rebuild(int RR)
{
	  int i;
	  for (i=RR;i<=n;++i)
	  {
	    f[i]=-inf;  
	      if (i<=3) f[i]=num[i][i];
	      else 
	        for (j=1;j<=3;++j) f[i]=max(f[i],f[i-j]+num[i][j]);
	  }
	  if (flag)
	  printf("%I64d\n",f[n]);
}
int main()
{
	  scanf("%d%d",&n,&q);
	  for (i=1;i<=n;++i) id[i]=i,scanf("%d",&a[i]);
	  for (i=1;i<=n;++i) id2[i]=i,scanf("%d",&b[i]);
	  sort(id+1,id+n+1,cmp); sort(id2+1,id2+n+1,Cmp);
	  for (i=1;i<=n;++i) c[i]=a[id[i]],d[i]=b[id2[i]];
	  for (i=1;i<=n;++i) real[id2[i]]=i;
	  for (i=1;i<=n;++i)  
	      for (j=1;j<=3;++j) if (i-j>=0) check(i-j+1,i);
	  flag=0;
	  rebuild(1);
	  flag=1;
	  for (;q--;)
	  {
	  	 scanf("%d%d",&x,&y);
	  	 id2[real[x]]=y; id2[real[y]]=x;
	  	 swap(real[x],real[y]);
	  	 for (i=real[x];i<=real[x]+2&&i<=n;++i) 
		    for (j=1;j<=3;++j) if (i-j>=0) check(i-j+1,i);
	  	 for (i=real[y];i<=real[y]+2&&i<=n;++i) 
		    for (j=1;j<=3;++j) if (i-j>=0) check(i-j+1,i);
	  	 rebuild(min(real[x],real[y]));
	  }
}