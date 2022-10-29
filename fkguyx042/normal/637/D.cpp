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

#define N 200005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,a[N],now,s,d,Ansx[N*2],Ansy[N*2],tot;
int main()
{
	  scanf("%d%d%d%d",&n,&m,&s,&d);
          if (d==1) { puts("IMPOSSIBLE"); return 0; }
	  for (i=1;i<=n;++i) scanf("%d",&a[i]);
	  sort(a+1,a+n+1);
	  for (i=1;i<=n;)
	  {
	  	  int rest=a[i]-now-1;
	  	  Ansx[++tot]=0; Ansy[tot]=rest;
	  	  if (rest<s) { puts("IMPOSSIBLE"); return 0; }
	  	  now=a[i]-1;
	  	  for (j=i+1;j<=n&&a[j]-a[j-1]-2<s&&a[j]-a[i]+2<=d;++j);
		  Ansx[++tot]=1; Ansy[tot]=a[j-1]-a[i]+2; now=a[j-1]+1;
		  i=j;
	  }
	  if (m-a[n]-1>0)
	  {
	     Ansx[++tot]=0;Ansy[tot]=m-a[n]-1;
	  }
	  for (i=1;i<=tot;++i)
	  {
	      if (Ansx[i]) printf("JUMP ");
	      else printf("RUN ");
	      printf("%d\n",Ansy[i]);
	  }
}