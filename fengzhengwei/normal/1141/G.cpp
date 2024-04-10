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
int n,m;
struct node
{
	int next,to;
}e[1000005];
int cnt;
int h[1000005];
int res[1000005];
void add(int x,int y)
{
	res[x]++;
	res[y]++;
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int vis[1000005];
int ans=0;
bool check(int x)
{
	ans=0;
	for(int i=1;i<=n;i++)if((res[i]>>1)>x)ans++;
	if(ans>m)return 0;
	return 1;
}
int oso[1000005];
void dfs(int x,int y,int c)
{
	int cnt=1;
	if(res[x]/2>ans)
	{
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y)continue;
			oso[(i+1)>>1]=1;
			dfs(e[i].to,x,1);
		}
		return;
	}
	for(int i=h[x];i;i=e[i].next)
	{
		if(cnt==c)cnt++;
		if(e[i].to==y)continue;
		oso[(i+1)>>1]=cnt;
		dfs(e[i].to,x,cnt);
		cnt++;
	}
}
int main(){
	n=read();
	m=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	int l=1;
	int r=10000000;
	int sss;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))
		{
			sss=mid,r=mid-1;
		}
		else l=mid+1;
	}
	cout<<sss<<'\n';
	ans=sss;
	dfs(1,0,0);
	for(int i=1;i<n;i++)cout<<oso[i]<<" ";
	puts("");
	return 0;
}