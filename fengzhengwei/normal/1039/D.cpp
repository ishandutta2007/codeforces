#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc()
{
	static char buf[1<<16],*s,*t;
	if(s==t)
	{
		t=(s=buf)+fread(buf,1,1<<16,stdin);
		if(s==t)return EOF;
	}
	return *s++;
}
#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
const int xx=1e5+5;
struct node
{
	int next,to;
}e[xx<<1];
int cnt;
int h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int dfn[xx],tot,f[xx];
void dfs(int x,int y)
{
	f[x]=y;
	dfn[++tot]=x;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
	}
}
int dp[xx];
int w[xx];
int check(int x)
{
	if(w[x]!=-1)return w[x];
	if(x==1)return n;
	int sss=0;
	for(int i=n;i>=1;i--)dp[i]=1;
	dp[0]=-2147483647;
	for(int i=n;i>=1;i--)
	{
		int now=dfn[i];
//		cout<<now<<" "<<dp[now]<<"\n";
		if(dp[now]<0)continue;
		if(dp[now]+dp[f[now]]>=x)sss++,dp[f[now]]=-1;
		if(dp[f[now]]!=-1)dp[f[now]]=max(dp[f[now]],dp[now]+1);
	}
	return (w[x]=sss);
}

signed main(){
	memset(w,-1,sizeof(w));
	n=read();
	int b=sqrt(n*log2(n));
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	for(int i=1;i<=b;i++)cout<<check(i)<<"\n";
//	return 0;
	for(int i=b+1;i<=n;i++)
	{
		int s=check(i);
		int l=i,r=n,ans=i;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid)==s)ans=mid,l=mid+1;
			else r=mid-1;
		}
		for(int j=i;j<=ans;j++)cout<<s<<'\n';
		i=ans;
	}
	return 0;
}