#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1000005;
int prim[xx],vis[xx],cnt,n;

void pre()
{
	for(int i=2;i<=1000;i++)
	{
		if(!vis[i])prim[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>1e6)break;
			vis[prim[j]*i]=1;
			if(i%prim[j]==0)break;
		}
	}
}
ll ans=1e18;
void dfs(int x,int y,ll sum,int last)
{
	if(sum>1e18)return;
//	cout<<x<<" "<<y<<" "<<sum<<" "<<last<<"\n";
	if(y==1)return ans=min(ans,sum),void();
	if(x==cnt+1)return;
	if(last==1)return;
	ll now=1;
	for(int j=1;j<=last;j++)
	{
		if(y%j==0&&1.0*sum*now<=1e18)dfs(x+1,y/j,sum*now,j);
		if(1.0*now*prim[x]>1e18)break;
		now*=prim[x];
//		if(now>)
	}
}
int main(){
	pre();
	n=read();
	dfs(1,n,1,n);
	cout<<ans<<'\n';
	return 0;
}