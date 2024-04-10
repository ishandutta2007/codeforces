#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 2000005
int i,j,m,n,p,k,a[N],id[N],Ans[N],vis[N],x,y,f[N];
int main()
{
	  scanf("%d%d",&n,&m);
	  for (i=1;i<=m;++i)
	  {
	  	   scanf("%d%d",&x,&y);
	  	   if (a[x]<y) a[x]=y,id[x]=i;
	  	   f[x]++; f[x+y]--;
	  }
	  int Maxl=0,NextMax=0,Nextid=0;
	  for (i=1;i<=n;++i) f[i]+=f[i-1];
	  for (i=1;i<=n;++i)
	    if (f[i])
	    {
	    	  if (Maxl<i) 
			  {
			  	  if (Maxl==i-1)
			  	  {
			  	       if (i+a[i]-1>NextMax) Maxl=i+a[i]-1,vis[id[i]]=1;
						else Maxl=NextMax,vis[Nextid]=1;	    
				  }
				  else 
				  {
			  	  if (NextMax>=i) vis[Nextid]=1,Maxl=NextMax;
			  	  else vis[id[i]]=1,Maxl=i+a[i]-1;
			      }
			   } 
			   if (i+a[i]-1>NextMax)
			{
				  NextMax=i+a[i]-1;
				  Nextid=id[i];
			}
		}
	 for (i=1;i<=m;++i) if (!vis[i]) Ans[++Ans[0]]=i;
	 printf("%d\n",Ans[0]);
	 for (i=1;i<=Ans[0];++i) printf("%d ",Ans[i]);
}