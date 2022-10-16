#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int T;
int n;
int l[500005];
int r[500005];
int vis[500005];
int main(){
	T=read();
	while(T--)
	{
		n=read();
		int visl=1;
		int visr=1;
		for(int i=0;i<=n;i++)l[i]=r[i]=-1;
		for(int i=0;i<n;i++)
		{
			char c;
			while((c=getchar())!='-'&&(c!='<')&&c!='>');
			if(c=='-')
			l[i+1]=r[i]=1;
			if(c=='<')l[i+1]=1,visr=0;
			if(c=='>')r[i]=1,visl=0;
			vis[i]=1;
		}
		l[0]=l[n];
		if(visl||visr)
		{
			printf("%d\n",n);
			continue;
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(l[i]!=-1)
			{
				if(i==0)
				{
					if(r[n-1]!=-1)ans+=vis[i],vis[i]=0;
				}
				else 
				{
					if(r[i-1]!=-1)ans+=vis[i],vis[i]=0;
				}
			}
			if(r[i]!=-1)
			{
				if(i==n-1)
				{
					if(l[0]!=-1)ans+=vis[i],vis[i]=0;
				}
				else 
				{
					if(l[i+1]!=-1)ans+=vis[i],vis[i]=0;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}