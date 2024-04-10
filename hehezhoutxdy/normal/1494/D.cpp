#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[2003][2003];
bool vis[2003];
int val[2003];
int X[2003],Y[2003],C=0;
int Q[2003];
int ff[2003];
signed main()
{
	memset(a,0x3f,sizeof(a));
	int n=read(),k=n;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) a[i][j]=read();
	for(int i=1; i<=n; i++) val[i]=a[i][i],a[i][i]=1000000;
	while(n>1)
	{
		int mn=1000000;
		for(int i=1; i<=k; i++) if(!vis[i]) for(int j=1; j<=k; j++) if(!vis[j])
		mn=min(mn,a[i][j]);
		int A=-1,c=0;
		for(int i=1; i<=k; i++) for(int j=1; j<=k; j++)
		if(mn==a[i][j])
		{
			if(!vis[i]) 
			{
				Q[++c]=i;
				if(A==-1) A=i;
				--n;//X[++C]=k+1,Y[C]=i;
				vis[i]=1;
			}
			if(!vis[j]) 
			{
				Q[++c]=j;
				if(A==-1) A=j;
				--n;//X[++C]=k+1,Y[C]=j;
				vis[j]=1;
			}
		}
		for(int i=1; i<=c;++i) ff[i]=0;
		for(int i=1; i<=c; ++i)
		{
			if(ff[i]) 
			{
				X[++C]=ff[i],Y[C]=Q[i];
				continue;
			}
			ff[i]=++k;++n;
			val[k]=mn;
			X[++C]=k,Y[C]=Q[i];
			for(int j=1; j<k; ++j) a[k][j]=a[j][k]=a[Q[i]][j];			
			for(int j=i+1; j<=c; ++j) 
			{
				if(a[Q[i]][Q[j]]==mn) ff[j]=ff[i];
				a[Q[i]][Q[j]]=1000000;
			}
		}
	}
	printf("%d\n",k);
	for(int i=1; i<=k; i++)printf("%d ",val[i]);
	puts("");
	for(int i=1; i<=k; i++)if(!vis[i]) printf("%d\n",i);
	for(int i=1; i<k; i++) printf("%d %d\n",Y[i],X[i]);
	return 0;
}