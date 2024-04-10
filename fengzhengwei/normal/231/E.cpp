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
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
struct yf
{
	struct node{int next,to;}w[xx<<1];
	int cnt=1,h[xx];
	void add(int x,int y)
	{
		cnt++;
		w[cnt].next=h[x];
		h[x]=cnt;
		w[cnt].to=y;
	}
}E,O;//O 
#define e E.w
#define h E.h
// 
int dfn[xx],low[xx],stk[xx],val[xx],bel[xx],top,cst,cnt;
void tj(int x,int y)
{
	dfn[x]=low[x]=++cst;stk[++top]=x;
	for(int i=h[x];i;i=e[i].next)
	{
		if(i==(y^1))continue;
		if(!dfn[e[i].to])
			tj(e[i].to,i),low[x]=min(low[x],low[e[i].to]);
		else low[x]=min(low[x],dfn[e[i].to]);
	}
	if(low[x]==dfn[x])
	{
		cnt++;
		int tt=0;
		while(stk[top]!=x)
			bel[stk[top--]]=cnt,tt++;
		bel[stk[top--]]=cnt,tt++;
		val[cnt]=tt!=1;
//		cerr<<tt<<" "<<val[cnt]<<"\n";
	}
}
#undef e
#undef h
#define e O.w
#define h O.h
int n,m,f[xx][21],dep[xx],Dp[xx];
const int mod=1e9+7;
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
void dfs(int x,int y)
{
//	cout<<x<<" "<<y<<" "<<val[x]<<'\n';
	f[x][0]=y;Dp[x]=Dp[y]+val[x];dep[x]=dep[y]+1;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=y)dfs(e[i].to,x);
}
int lg[xx];
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y])x=f[x][lg[dep[x]-dep[y]]];
	if(x==y)return x;
	for(int i=lg[dep[x]];i>=0;i--)(f[x][i]^f[y][i])?(x=f[x][i],y=f[y][i]):0;
	return f[x][0];
}
int main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	n=read(),m=read();
	vector<pair<int,int> >v;
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		v.push_back(make_pair(a,b));
		E.add(a,b),E.add(b,a);
	}
	tj(1,0);
	for(auto it:v)
	{
//		cerr<<it.first<<" "<<it.second<<"\n";
		if(bel[it.first]!=bel[it.second])
		{
//			cerr<<bel[it.first]<<" qqq "<<bel[it.second]<<"\n";
			O.add(bel[it.first],bel[it.second]);
			O.add(bel[it.second],bel[it.first]);
		}
	}
//	puts("ADWA");
	dfs(1,0);
	int q=read();
	while(q--)
	{
		int a=bel[read()],b=bel[read()],L=lca(a,b);
		cout<<ksm(2,Dp[a]+Dp[b]-Dp[L]-Dp[f[L][0]])<<"\n";
	}
	pc('1',1);
	return 0;
}
/*// 
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
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
struct yf
{
	struct node{int next,to;}w[xx<<1];
	int cnt=1,h[xx];
	void add(int x,int y)
	{
		cnt++;
		w[cnt].next=h[x];
		h[x]=cnt;
		w[cnt].to=y;
	}
}E,O;//O 
#define e E.w
#define h E.h
// 
int dfn[xx],low[xx],stk[xx],val[xx],bel[xx],top,cst,cnt;
void tj(int x,int y)
{
	dfn[x]=low[x]=++cst;stk[++top]=x;
	for(int i=h[x];i;i=e[i].next)
	{
		if(i==(y^1))continue;
		if(!dfn[e[i].to])
		{
			tj(e[i].to,i);low[x]=min(low[x],low[e[i].to]);
			if(low[e[i].to]>=dfn[x])
			{
				cnt++;
				if(low[e[i].to]==dfn[x])bel[x]=cnt;
				val[cnt]=low[e[i].to]==dfn[x];// 
				O.add(cnt,x),O.add(x,cnt);
				while(stk[top]!=e[i].to)
				{
					if(low[e[i].to]==dfn[x])bel[stk[top]]=cnt;
					O.add(cnt,stk[top]),O.add(stk[top],cnt),top--;
				}
				if(low[e[i].to]==dfn[x])bel[stk[top]]=cnt;
				O.add(cnt,stk[top]),O.add(stk[top],cnt),top--;
			}
		}
		else low[x]=min(low[x],dfn[e[i].to]);
	}
	
}
#undef e
#undef h
#define e O.w
#define h O.h
int n,m,f[xx][21],dep[xx],Dp[xx];
const int mod=1e9+7;
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
void dfs(int x,int y)
{
//	cout<<x<<" "<<y<<'\n';
	f[x][0]=y;Dp[x]=Dp[y]+val[x];dep[x]=dep[y]+1;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=y)dfs(e[i].to,x);
}
int lg[xx];
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y])x=f[x][lg[dep[x]-dep[y]]];
	if(x==y)return x;
	for(int i=lg[dep[x]];i>=0;i--)(f[x][i]^f[y][i])?(x=f[x][i],y=f[y][i]):0;
	return f[x][0];
}
int main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		E.add(a,b),E.add(b,a);
	}
	cnt=n;
	tj(1,0);
	for(int i=1;i<=n;i++)if(!bel[i])bel[i]=i;
	dfs(1,0);
	int q=read();
	while(q--)
	{
		int a=bel[read()],b=bel[read()],L=lca(a,b);
//		cout<<v[a]<<" "<<v[b]<<"\n";
//		cout<<L<<" "<<bel[L]<<"\n";
		int dlt=L<=n?val[bel[L]]:0;
		cout<<ksm(2,Dp[a]+Dp[b]-Dp[L]-Dp[f[L][0]]+dlt)<<"\n";
	}
	pc('1',1);
	return 0;
}

*/