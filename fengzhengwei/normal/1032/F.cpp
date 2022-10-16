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
const int xx=3e5+5;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
const int mod=998244353;
// 
int son[xx];
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
ll f[xx][3];//012 
// 
ll pre[xx],suf[xx];
void dfs(int x,int y)
{
	f[x][1]=1;
	vector<int>v;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		son[x]++;
		dfs(e[i].to,x);
		v.push_back(e[i].to);
		f[x][1]*=(f[e[i].to][0]+f[e[i].to][1]);// 
		f[x][1]%=mod;
	}
	for(int i=0;i<v.size();i++)
	{
		if(i)pre[v[i]]=pre[v[i-1]];
		else pre[v[i]]=1;
		pre[v[i]]=(pre[v[i]]*f[v[i]][0]+pre[v[i]]*(f[v[i]][0]+f[v[i]][1]))%mod;// 
	}
	for(int i=v.size()-1;i>=0;i--)
	{
		if(i!=v.size()-1)suf[v[i]]=suf[v[i+1]];
		else suf[v[i]]=1;
		suf[v[i]]=(suf[v[i]]*f[v[i]][0]+suf[v[i]]*(f[v[i]][0]+f[v[i]][1]))%mod;//() 
	}
//	puts("SSS");
//	cout<<x<<"\n";
	if(v.size())f[x][2]=suf[v[0]];
	else f[x][2]=1;
	for(int i=0;i<v.size();i++)
	{
		ll ot=1;
		if(i)ot*=pre[v[i-1]];
		if(i!=v.size()-1)ot*=suf[v[i+1]];
//		cout<<v[i]<<" "<<ot<<" "<<<<"\n";
		ot%=mod;
		f[x][0]+=f[v[i]][2]%mod*ot%mod;
		f[x][0]%=mod;
	}
}
int n;
int main(){
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(1,0);
//	cout<<f[1][1]<<"\n";
	cout<<(f[1][0]+f[1][1])%mod<<"\n"; 
	return 0;
}