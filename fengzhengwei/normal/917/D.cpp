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
const int xx=105;
struct nod{int next,to;}e[xx<<1];
int n,cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
const int mod=1e9+7;
ll f[xx][xx][2];//xyx 
ll to[xx][2];
int size[xx];
ll ksm[xx];
ll res[xx];
void dfs(int x,int y)
{
	size[x]=1;f[x][0][0]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		memset(to,0,sizeof(to));
		for(int j=size[x];j>=0;j--)
		{
			for(int k=0;k<=size[e[i].to];k++)
			{
				to[j+k+1][0]+=f[x][j][0]*f[e[i].to][k][0]%mod;
				to[j+k+1][1]+=(f[x][j][0]*f[e[i].to][k][1]+f[x][j][1]*f[e[i].to][k][0])%mod;// 
				to[j+k][0]+=f[x][j][0]*f[e[i].to][k][1]%mod;
				to[j+k][1]+=f[x][j][1]*f[e[i].to][k][1]%mod;
			}
		}
		size[x]+=size[e[i].to];
		for(int j=size[x];j>=0;j--)f[x][j][0]=to[j][0]%mod,f[x][j][1]=to[j][1]%mod;
	}
	for(int j=size[x];j>=0;j--)f[x][j][1]+=f[x][j][0]%mod,f[x][j][1]%=mod;
//	cout<<f[x][2][1]<<"sss \n";
}
ll C[xx][xx];
int main(){
	n=read();
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)C[i][j]=C[i-1][j]+C[i-1][j-1],C[i][j]%=mod;
	ksm[0]=1;
	for(int i=1;i<=n;i++)ksm[i]=ksm[i-1]*n%mod;
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	res[n]=0;
	res[n-1]=1;
	for(int i=n-2;i>=0;i--)res[i]=f[1][i][1]*ksm[n-i-2]%mod;
//	cout<<res[1]<<"\n";
	for(int i=0;i<n;i++)
	{
		ll ans=0;
		for(int j=i;j<=n;j++)ans+=(C[j][i]*(((j-i)&1)?-1:1)*res[j]%mod+mod)%mod;
		cout<<ans%mod<<" ";
	}
	puts("");
	return 0;
}