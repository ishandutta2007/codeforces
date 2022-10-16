#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
char gc(){static char buf[1<<20],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2e5+5,mod=1e9+7;
int fi[xx],vs[xx],g[xx],prim[xx];
//g(R)=\sum_{d|R} {d\over \fi(d) \mu({R \over d})}
//, 
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
void pre()
{
	int cnt=0;
	fi[1]=g[1]=1;
	for(int i=2;i<xx;i++)
	{
		if(!vs[i])fi[i]=i-1,g[i]=(i*ksm(i-1,mod-2)-1+mod)%mod,prim[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(i*prim[j]>=xx)break;
			vs[i*prim[j]]=1;
			fi[i*prim[j]]=fi[i]*fi[prim[j]];
			g[i*prim[j]]=1ll*g[i]*g[prim[j]]%mod;
			if(i%prim[j]==0)
			{
				fi[i*prim[j]]=fi[i]*prim[j];
				g[i*prim[j]]=0;
			}
			if(i%prim[j]==0)break;
		}
	}
}
int A[xx],n;
struct nod{int next,to,v;}e[xx<<1];
int cnt,lg[xx],h[xx],dfn[xx];
vector<int>Cl;
void cls(){for(auto it:Cl)h[it]=0;Cl.clear();cnt=0;}
void add(int x,int y,int z){cnt++;e[cnt]={h[x],y,z};h[x]=cnt;}
namespace T// 
{
	struct nod{int next,to;}e[xx<<1];
	int cnt,h[xx],f[xx][21],dep[xx],cst;
	void add(int x,int y){cnt++;e[cnt]={h[x],y};h[x]=cnt;}
	void dfs(int x,int y)
	{
		dfn[x]=++cst,f[x][0]=y,dep[x]=dep[y]+1;
		for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
		for(int i=h[x];i;i=e[i].next)
			if(e[i].to!=y)dfs(e[i].to,x);
	}
	int lca(int x,int y)
	{
		if(dep[x]<dep[y])swap(x,y);
		while(dep[x]!=dep[y])x=f[x][lg[dep[x]-dep[y]]];
		if(x==y)return x;
		for(int i=20;i>=0;i--)(f[x][i]^f[y][i])?(x=f[x][i],y=f[y][i]):0;
		return f[x][0];
	}
	int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
}
using T::dis;
using T::lca;
using T::dep;
void ad(int x,int y){int z=dis(x,y);Cl.push_back(x),Cl.push_back(y);add(x,y,z),add(y,x,z);}
int stk[xx],cr[xx],top;
ll res,sum[xx];
void dfs(int x,int y)
{
	sum[x]=cr[x]?fi[x]:0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		sum[x]+=sum[e[i].to];
		sum[x]%=mod;
	}
}
void dfss(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfss(e[i].to,x);
		res+=e[i].v*sum[e[i].to]%mod*(sum[1]-sum[e[i].to]+mod)%mod;
//		cout<<sum[e[i].to]<<" "<<sum[1]-sum[e[i].to]<<"!!\n";
		res%=mod;
	}
}
int main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	
	pre();
	n=read();
	for(int i=1;i<=n;i++)A[i]=read();// 
//	for(int i=1;i<=n;i++)cout<<i<<" "<<fi[i]<<"!!\n";
	for(int i=1;i<n;i++)
	{
		int a=A[read()],b=A[read()];
		T::add(a,b),T::add(b,a);
//		cout<<a<<" "<<b<<"!!!\n";
	}
	T::dfs(1,0);
	ll ans=0;
//	for(int i=1;i<=n;i++)cout<<i<<" "<<dfn[i]<<"!!\n";
//	for(int i=1;i<=n;i++)cout<<i<<" "<<T::f[i][0]<<"!!\n";
	for(int R=1;R<=n;R++)
	{
		vector<int>v;
		// 
		// 
		cls();
		for(int j=R;j<=n;j+=R)v.push_back(j);
		for(auto it:v)cr[it]=1;
		sort(v.begin(),v.end(),[&](int x,int y){return dfn[x]<dfn[y];});
		stk[top=1]=1;
//		cerr<<R<<"!!\n";
		for(auto it:v)
		{
			if(it==stk[top])continue;
			int L=lca(it,stk[top]);
//			cout<<it<<" "<<dfn[it]<<" "<<L<<" "<<stk[top]<<" "<<dep[L]<<" "<<dep[stk[top]]<<"!!asd\n";
			while(dep[L]<dep[stk[top]])
			{
				if(dep[L]>dep[stk[top-1]])
				{
					ad(L,stk[top]);
					stk[top]=L;
					break;
				}
				ad(stk[top-1],stk[top]),top--;
			}
			stk[++top]=it;
		}
		while(top>1)ad(stk[top-1],stk[top]),top--;
		res=0;
		dfs(1,0),dfss(1,0);
		ans+=res*g[R];
//		cout<<R	<<" "<<res<<"!!\n";
		ans%=mod;
		for(auto it:v)cr[it]=0;
	}
//	cout<<ans<<"!!\n";
	// 
	cout<<ans*2%mod*ksm(n,mod-2)%mod*ksm(n-1,mod-2)%mod<<"\n";
	pc('1',1);
	return 0;
}