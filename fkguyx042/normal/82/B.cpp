#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,x,sum[205][205],vis[205],a[205],l,r,ans[205];
void Find(int x)
{
	  vis[x]=0;
	  ans[ans[0]=1]=x;
	  int l,i;
	  for (l=1;l<=ans[0];++l)
	  {
	  	  p=ans[l];
	  	  for (i=1;i<=200;++i)
	  	     if (vis[i]&&sum[p][i]==n-1)
	  	     {
	  	     	 ans[++ans[0]]=i;
	  	     	 vis[i]=0;
	  	     }
	  	}
}	  	     
int main()
{
	 scanf("%d",&n);
	 if (n==2)
	 {
	 	  scanf("%d",&k);
	 	  for (i=1;i<=k;++i)
	 	  {
	 	  	 scanf("%d",&x);
	 	  	  if (i==1)
	 	  	  {
	 	  	  	 printf("1 %d\n",x);
	 	  	  }
	 	  	  if (i==2) printf("%d",k-1);
	 	  	  if (i!=1) printf(" %d",x);
	 	  }
	 }
	 else 
	 {
	 	  for (i=1;i<=n*(n-1)/2;++i)
	 	  {
	 	  	 scanf("%d",&k);
	 	  	 for (j=1;j<=k;++j) scanf("%d",&a[j]),vis[a[j]]=1;
	 	  	 for (l=1;l<k;++l)
	 	  	      for (r=l+1;r<=k;++r)
	 	  	        sum[a[l]][a[r]]++,sum[a[r]][a[l]]++;
	 	  }
	 	  for (i=1;i<=200;++i) if (vis[i])
	 	  {
	 	  	   Find(i);
	 	  	   printf("%d",ans[0]);
	 	  	   for (j=1;j<=ans[0];++j) printf(" %d",ans[j]);
	 	  	   puts("");
	 	  }
	 }
}