#include<bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<ll,ll> pr;
 
const int maxn = 1e6 + 10;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
 
inline int read()
{
	int x=0;char c=getchar();bool f=false;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=true;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+(c^48);
	return f?-x:x;
}
inline ll sqr(ll x){return x*x;}
 
ll n,dg[maxn],head[maxn],siz[maxn],en=1;
struct edge{
	int v,n;
}e[maxn<<1];
inline void addedge(int u,int v)
{
	dg[u]++;dg[v]++;
	e[en].v=v;e[en].n=head[u];head[u]=en++;
	e[en].v=u;e[en].n=head[v];head[v]=en++;
}
void input()
{
	int i;
 
	n=read();
	for(i=1;i<n;i++) addedge(read(),read());
}
 
ll f[maxn],ans;
vector<pair<pr,int> > V,C;
void Convex()
{
	int i,qn;
 
	for(i=0;i<(int)V.size();i++)
	{
		if(C.size() && V[i].fir.fir==C.back().fir.fir) continue;
 
		qn=C.size()-1;
		while((qn=C.size()-1) > 0 && 
			(C[qn].fir.sec-C[qn-1].fir.sec) * (V[i].fir.fir - C[qn].fir.fir) >=
			(V[i] .fir.sec-C[qn].fir.sec) * (C[qn].fir.fir-C[qn-1].fir.fir)) C.pop_back();
		C.push_back(V[i]);
	}
}
void dfs(int x,int fa)
{
	int i,j,v;
 
	siz[x]=1;
	for(i=head[x];i;i=e[i].n) if(e[i].v^fa) dfs(e[i].v,x),siz[x]+=siz[e[i].v];
	if(siz[x]==1){f[x]=1;return;}
 
	for(i=head[x];i;i=e[i].n) if(e[i].v^fa)
	{
		v=e[i].v;
		V.push_back(make_pair(pr(siz[v],(siz[v]-2*n)*siz[v]+f[v]),i));
	}
	sort(V.begin(),V.end());Convex();
 
	j=C.size()-1;
	for(i=0;i<(int)V.size();i++)
	{
		for(;j>0 && -(V[i].fir.sec+C[j].fir.sec  +2*V[i].fir.fir*C[j].fir.fir) < 
					-(V[i].fir.sec+C[j-1].fir.sec+2*V[i].fir.fir*C[j-1].fir.fir);j--);
 
		if(C[j].sec == V[i].sec)
		{
			if(j>0) ans=max(ans,-(V[i].fir.sec+C[j-1].fir.sec+2*V[i].fir.fir*C[j-1].fir.fir));
			if(j+1<(int)C.size())
					ans=max(ans,-(V[i].fir.sec+C[j+1].fir.sec+2*V[i].fir.fir*C[j+1].fir.fir));
		}
		else ans=max(ans,-(V[i].fir.sec+C[j].fir.sec  +2*V[i].fir.fir*C[j].fir.fir));
	}
 
	f[x]=INFLL;V.clear();C.clear();
	for(i=head[x];i;i=e[i].n) if(e[i].v^fa)
	{
		f[x]=min(f[x],f[e[i].v]+sqr(siz[x]-siz[e[i].v]));
	}
}
 
int main()
{
	input();
	if(n==1) puts("0"),exit(0);
	if(n==2) puts("2"),exit(0);
	for(int i=1;i<=n;i++) if(dg[i]!=1) {dfs(i,0);break;}
 
	cout<<(ll)n*(n-1)/2+ans/2;
	return 0;
}