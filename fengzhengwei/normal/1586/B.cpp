#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int vis[xx];
signed main(){
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		memset(vis,0,sizeof(vis[0])*(n+1));
		while(m--)
		{
			int a=read(),b=read(),c=read();
			vis[b]=1;
		}
		int id=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])id=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=id)
			{
				cout<<i<<" "<<id<<"\n";
			}
		}
	}
	return 0;
}