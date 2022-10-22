#include<bits/stdc++.h>
using namespace std;
char buf[1<<26],*P1=buf,*P2=buf,obuf[1<<25],*O=obuf;
#define getchar()(P1==P2&&(P2=(P1=buf)+fread(buf,1,1<<26,stdin),P1==P2)?EOF:*P1++)
inline int rd() 
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
void print(int x) 
{
	if(x>9) print(x/10);
	*O++=x%10+'0';
}
const int N=300005,mod=998244353,bs=917120411;
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int n,m,ti,u1,v1,p1,g1,l1,fl1,z1,fz1,u2,v2,p2,g2,l2,fl2,z2,fz2;
int pw[N],iv[N],f[N],g[N],fa[N],id[N],sz[N],d[N],mx[N],sq[N],tp[N];
char s[N];
vector<int>e[N];
inline int md(int x){return x>=mod?x-mod:x;}
void dfs(int u)
{
	sz[u]=1;
	f[u]=md(f[fa[u]]+1ll*(s[u]-'a'+1)*pw[d[u]]%mod);
	g[u]=md(1ll*g[fa[u]]*bs%mod+s[u]-'a'+1);
	for(auto v:e[u])
	{
		if(v==fa[u])
			continue;
		fa[v]=u;
		d[v]=d[u]+1;
		dfs(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[mx[u]])
			mx[u]=v;
	}
}
void cal(int u)
{
	ti++;
	id[u]=ti,sq[ti]=u;
	if(sz[u]!=1)
	{
		tp[mx[u]]=tp[u];
		cal(mx[u]);
	}
	for(auto v:e[u])
	{
		if(v==fa[u]||v==mx[u])
			continue;
		tp[v]=v;
		cal(v);
	}
}
int kth(int u,int k)
{
	int z=d[u]-k;
	while(d[tp[u]]>z)
		u=fa[tp[u]];
	return sq[id[u]-d[u]+z];
}
inline int sol1(int k)
{
	if(k<fz1) return md(g[u1]+mod-1ll*g[kth(u1,k)]*pw[k]%mod);
	else if(p1>=0) return md(g1+1ll*f[kth(v1,z1-k)]*pw[p1]%mod);
	else return md(g1+1ll*f[kth(v1,z1-k)]*iv[-p1]%mod);
}
inline int sol2(int k)
{
	if(k<fz2) return md(g[u2]+mod-1ll*g[kth(u2,k)]*pw[k]%mod);
	else if(p2>=0) return md(g2+1ll*f[kth(v2,z2-k)]*pw[p2]%mod);
	else return md(g2+1ll*f[kth(v2,z2-k)]*iv[-p2]%mod);
}
int lca(int u,int v)
{
	while(tp[u]!=tp[v])
	{
		if(d[tp[u]]<d[tp[v]])
			swap(u,v);
		u=fa[tp[u]];
	}
	if(d[u]<d[v])
		swap(u,v);
	return v;
}
int main()
{
	n=rd();
	for(int i=1;i<=n;i++)
	{
		char c=getchar();
		while(c<'a'||c>'z')
			c=getchar();
		s[i]=c;
	}
	for(int i=1;i<n;i++)
	{
		int u=rd(),v=rd();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ny=qp(bs,mod-2);
	pw[0]=iv[0]=1;
	for(int i=1;i<=n;i++)
		pw[i]=1ll*pw[i-1]*bs%mod,iv[i]=1ll*iv[i-1]*ny%mod;
	d[0]=-1;
	dfs(1);
	cal(1);
	m=rd();
	while(m--)
	{
		u1=rd(),v1=rd(),u2=rd(),v2=rd();
		l1=lca(u1,v1);
		l2=lca(u2,v2);
		z1=d[u1]+d[v1]-d[l1]*2+1;
		fz1=d[u1]-d[l1]+1;
		p1=fz1-d[l1]-1;
		z2=d[u2]+d[v2]-d[l2]*2+1;
		fz2=d[u2]-d[l2]+1;
		p2=fz2-d[l2]-1;
		g1=md(g[u1]+mod-1ll*g[fa[l1]]*pw[fz1]%mod);
		if(p1>=0) g1=md(g1+mod-1ll*f[l1]*pw[p1]%mod);
		else g1=md(g1+mod-1ll*f[l1]*iv[-p1]%mod);
		g2=md(g[u2]+mod-1ll*g[fa[l2]]*pw[fz2]%mod);
		if(p2>=0) g2=md(g2+mod-1ll*f[l2]*pw[p2]%mod);
		else g2=md(g2+mod-1ll*f[l2]*iv[-p2]%mod);
		int lb=1,rb=min(z1,z2),ans=0;
		while(lb<=rb)
		{
			int mid=lb+rb>>1;
			if(sol1(mid)==sol2(mid))
				ans=mid,lb=mid+1;
			else
				rb=mid-1;
		}
		print(ans);
		*O++='\n';
	}
	fwrite(obuf,O-obuf,1,stdout);
	return 0;
}