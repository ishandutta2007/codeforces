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
const int xx=105+5;
int ans[xx],nxt[xx],pre[xx],xid,nid,a[xx];//mxid 
signed main(){
	int n=read();
	for(int i=1;i<=n;i++)
	{
		cout<<"? ";
		for(int j=1;j<=n;j++)
		{
			cout<<1+(j==i)<<" ";
		}
		puts("");
		fflush(stdout);
		int s=read();
		if(!s)xid=i;
		if(s==i)continue;
		else nxt[i]=s,pre[s]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<"? ";
		for(int j=1;j<=n;j++)
		{
			cout<<2-(j==i)<<" ";
		}
		puts("");
		fflush(stdout);
		int s=read();
		if(!s)nid=i;
		if(s==i)continue;
		else pre[i]=s,nxt[s]=i;
	}
	a[nid]=1;
	int x=nid;
	for(int i=2;i<=n;i++)
	{
		x=nxt[x];
		a[x]=i;
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	puts("");
	return 0;
}