/*

DONT NEVER AROUND . //
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
const int MOD=998244353;
inline int Add(int u,int v){return u+v>=MOD?u+v-MOD:u+v;}
inline int Sub(int u,int v){return u-v>=0?u-v:u-v+MOD;}
inline int Mul(int u,int v){return LL(u)*LL(v)%MOD;}
int QuickPow(int x,int p)
{
	if(p<0)	p+=MOD-1;
	int ans=1,base=x;
	while(p)
	{
		if(p&1)	ans=Mul(ans,base);
		base=Mul(base,base);
		p>>=1;
	}
	return ans;
}
#define mp make_pair
vector<pair<int,int>> F[200005];
struct Edge{
	int t,x,y;
	Edge(int T=0,int X=0,int Y=0){t=T,x=X,y=Y;}
};
vector<Edge> G[200005];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int n;
int buc[200005],maxn[200005];
inline void Add(int u)
{
	for(auto st:F[u])	buc[st.first]+=st.second;
}
inline void Sub(int u)
{
	for(auto st:F[u])	buc[st.first]-=st.second,maxn[st.first]=max(maxn[st.first],-buc[st.first]);
}
int inv[200005],w[200005];
void dfs(int u,int pre)
{
	for(auto st:G[u])
	{
		int v=st.t,x=st.x,y=st.y;
		if(v==pre)	continue;
		w[v]=Mul(w[u],Mul(inv[x],y));
		Add(y),Sub(x);
		dfs(v,u);
		Add(x),Sub(y);
	}
}
void Solve()
{
	n=read();
	for(int i=1;i<=n;++i)	G[i].clear(),maxn[i]=buc[i]=0;
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read(),x=read(),y=read();
		int d=gcd(x,y);
		x/=d,y/=d;
		G[u].push_back(Edge(v,x,y));
		G[v].push_back(Edge(u,y,x));
	}
	w[1]=1;
	dfs(1,0);
	int lcm=1;
	for(int i=1;i<=n;++i)	if(maxn[i])	lcm=Mul(lcm,QuickPow(i,maxn[i]));
	int sum=0;
	for(int i=1;i<=n;++i)	sum=Add(sum,w[i]);
	write(Mul(sum,lcm)),puts("");
}
void pre(int u)
{
	int t=u;
	for(int i=2;i*i<=u;++i)
	{
		int cnt=0;
		if(t%i==0)
		{
			while(t%i==0)
			{
				t/=i;++cnt;
			}
			F[u].push_back(mp(i,cnt));
		}
	}
	if(t!=1)	F[u].push_back(mp(t,1));
}
int main(){
	for(int i=2;i<=200000;++i)	pre(i);
	inv[1]=1;
	for(int i=2;i<=200000;++i)	inv[i]=MOD-Mul((MOD/i),inv[MOD%i]);
	int T=read();
	while(T-->0)	Solve();
	return 0;
}