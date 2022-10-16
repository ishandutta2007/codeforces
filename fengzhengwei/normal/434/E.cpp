#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int read() {
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
ll n,mod,K,X;
struct node
{
	int next,to;
}e[1000005];
int cnt;
int h[1000005];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int vis[1000005];
int mp[1000005];//max_part
int core;
int size[1000005];
int c[1000005];
int dep[1000005];
int Km[1000005];
int Kn[1000005];
int ksm(int x,int y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans*=x,ans%=mod;
		x*=x;x%=mod;
		y>>=1;
	}
	return ans;
}
void getc(int x,int all,int d,int y)
{
	size[x]=1;
	dep[x]=d;
	mp[x]=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		if(vis[e[i].to])continue;
		getc(e[i].to,all,d+1,x);
		size[x]+=size[e[i].to];
		mp[x]=max(size[e[i].to],mp[x]);
	}
	mp[x]=max(mp[x],all-size[x]);
	if(!core||mp[x]<mp[core])core=x;
}
map<int,int> m1,m2;// 
int rt;
vector<int>f,g1,g2;//want 
int in[1000005];
int out[1000005];
void dfs(int x,int v1,int v2,int y)
{
//	if(x!=rt)
//	{
		f.push_back(x);
		v1*=K;v1+=c[x];v1%=mod;
		v2+=Km[dep[x]]*c[x];v2%=mod;
		if(dep[x]==0)v2=0;
		m2[v2]++;
//		cout<<"v1="<<v1<<endl;
		int o=(X-v1+mod)*Kn[dep[x]]%mod;
//		cout<<rt<<" "<<x<<"  "<<o<<"  "<<v2<<endl;
		g1.push_back(o);// 
		m1[o]++;
		g2.push_back(v2);// 
//		m1[v1]++;
//		v1+Km[dep[x]+1]*g1 X (mod y); 
//		g2.push_back((X-v1)*kn[dep[x]+1]%mod);
//	}
	for(int i=h[x];i;i=e[i].next)
	{
		if(!vis[e[i].to]&&e[i].to!=y)
		dfs(e[i].to,v1,v2,x);
	}
}
void ad(int op)
{
	for(int i=0;i<f.size();i++)
	{
//		cout<<f[i]<<" sss "<<g2[i]<<" "<<m1[3]<<endl;
		out[f[i]]+=op*m2[g1[i]];
		in[f[i]]+=op*m1[g2[i]];
//	cout<<i<<endl;
	}
}
void solve(int x,int all)
{
	core=0;getc(x,all,0,0);rt=core;getc(rt,all,0,0);
//	cout<<x<<endl;
//	cout<<rt<<endl;
	if(all==1){	
//		cout<<rt<<" qqq "<<c[rt]<<endl;
		if(c[rt]%mod==X)in[rt]++,out[rt]++;
		return;
	}
	m1.clear();m2.clear();
	vis[rt]=1;f.clear();g1.clear();g2.clear();dfs(rt,0,0,0);ad(1);
	for(int i=h[rt];i;i=e[i].next)
	{
		if(!vis[e[i].to])
		{
			f.clear();g1.clear();g2.clear();m1.clear();m2.clear();
			dfs(e[i].to,c[rt],0,0);ad(-1);
		}
	}
//	cout<<"qweqeqe"<<endl;
	for(int i=h[rt];i;i=e[i].next)
	{
//		cout<<e[i].to<<endl;
		if(!vis[e[i].to])solve(e[i].to,size[e[i].to]);
	}
}
int p[34500];
signed main() {
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	n=read();
	mod=read();
	K=read();
	X=read();
	int ni=ksm(K,mod-2);
	Km[0]=1;
	Kn[0]=1;
	for(int i=1;i<=n;i++)Km[i]=Km[i-1]*K%mod;
	for(int i=1;i<=n;i++)Kn[i]=Kn[i-1]*ni%mod;
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	solve(1,n);
	ll t=0;
	for(int i=1;i<=n;i++)
	{
//		cout<<in[i]<<" "<<out[i]<<endl;
		int in1=n-in[i];
		int out1=n-out[i];
		t+=2ll*(in[i]*in1)+2ll*(out[i]*out1)+in[i]*out1+in1*out[i];
	}
//	cout<<t<<endl;
	cout<<n*n*n-(t>>1)<<endl;
	return 0;
}