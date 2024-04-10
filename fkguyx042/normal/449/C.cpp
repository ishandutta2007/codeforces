#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005
using namespace std;
int i,j,m,n,p,k,vis[N],Q[N],ansx[N],ansy[N],ans;
int main()
{
	  scanf("%d",&n);
	  for (i=n;i>1;--i)
	{
		  for (j=2;j*j<=i;++j)
		   if (i%j==0) break;
		   if (j*j>i)
		   {
		   	  if (n/i<2) continue;
		   	  Q[0]=0;
		   	  for (j=1;j<=n/i;++j)
		   	    if (!vis[i*j]) Q[++Q[0]]=i*j;
		   	  if (Q[0]&1)
		   	    for (j=1;j<=Q[0];++j)
		   	      if (Q[j]==i*2)
		   	      {
		   	      	  for (k=j;k<Q[0];++k)
		   	      	      Q[k]=Q[k+1];
		   	      	  break;
		   	      }
		   	    Q[0]--;
		   	    for (j=1;j<=Q[0];j+=2)
		   	    {
		   	    	 ++ans;
		   	    	 ansx[ans]=Q[j];
		   	    	 ansy[ans]=Q[j+1];
		   	    	 vis[Q[j]]=vis[Q[j+1]]=1;
		   	    }
		   	}
	}
	printf("%d\n",ans);
	for (i=1;i<=ans;++i) printf("%d %d\n",ansx[i],ansy[i]);
}