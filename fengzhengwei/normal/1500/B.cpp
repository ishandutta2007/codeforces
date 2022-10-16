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
int n,m;
ll k;
const int xx=5e5+5;
int a[xx];
int b[xx];
int g[xx];
int to[xx<<1];
int change(int x)
{
	if(x<=0)return x+n;
	if(x>n)x-=n;
	return x;
}
ll s[xx][41];
int f[xx][41];
signed main(){
//	freopen("a.in","r",stdin);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int j=1;j<=m;j++)b[j]=read();
	if(n<m)swap(n,m),swap(a,b);
	for(int i=1;i<=n;i++)to[a[i]]=i;
	for(int i=1;i<=m;i++)
	{
		if(to[b[i]])g[change(to[b[i]]-i+1)]--;
	}
	for(int i=1;i<=n;i++)g[i]+=m,f[i][0]=change(i+m),s[i][0]=g[i];
//	for(int i=1;i<=n;i++)cout<<g[i]<<"ss \n";
	int w=41;
	for(int j=1;j<=40;j++)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
			s[i][j]=s[i][j-1]+s[f[i][j-1]][j-1];
		}
		if(s[1][j]>k)
		{
			w=j;
			break;
		}
	}
	int now=1;
	ll sum=0;
	ll ans=0;
	for(int i=w-1;i>=0;i--)
	{
		if(sum+s[now][i]<k)sum+=s[now][i],now=f[now][i],ans+=1ll*m*(1ll<<i);
	}
//	cout<<now<<" "<<sum<<" "<<ans<<"\n";
	for(int i=1;i<=m;i++)
	{
			ans++;
		if(a[change(i+now-1)]!=b[i])
		{
			sum++;
//			cout<<i<<" qweq\n";
			if(sum==k)
			{
				cout<<ans<<"\n";
				return 0;
			}
		}
	}
	return 0;
}