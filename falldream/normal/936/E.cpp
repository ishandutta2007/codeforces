#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define MN 300000
#define getchar() (*SS++)
char B[1<<26],*SS=B; 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct Map
{
#define MX 10000007
	int head[MX+5],w,cnt;
	struct edge{long long x;int w,next;}e[MN*5+5];
	int count(int x,int y)
	{
		long long ha=1LL*x*(MN+1)+y;int j=ha%MX;
		for(int i=head[j];i;i=e[i].next)
			if(e[i].x==ha) return e[i].w;
		return 0;
	}
	void ins(int x,int y,int w)
	{
		long long ha=1LL*x*(MN+1)+y;int j=ha%MX;
		e[++cnt]=(edge){ha,w,head[j]};head[j]=cnt;	
	}
}mp,mpe;
pair<int,int> a[MN+5];
int cnth,cntH,cntv,cntq;
int n,m,Q,b[MN+5],head[MN+5],Head[MN+5],bel[MN+5],T1[MN+5],T2[MN+5],v[MN+5],q[MN+5],co;
int from[MN+5],d[MN+5],size[MN+5],rt,mn,tot,in[MN+5],Ans[MN+5],top,c[MN+5],cc,S[MN+5],rk[MN+5];
struct edge{int to,next;}eh[MN*4+5],eH[MN*2+5],ev[MN+5],eq[MN+5];
struct ques{int k,x,y,X;}s[MN+5];
const int dis[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
inline void insh(int f,int t){eh[++cnth]=(edge){t,head[f]};head[f]=cnth;}
inline void insH(int f,int t){eH[++cntH]=(edge){t,Head[f]};Head[f]=cntH;}
inline void insv(int f,int t){ev[++cntv]=(edge){t,   v[f]};   v[f]=cntv;}
inline void insq(int f,int t){eq[++cntq]=(edge){t,   q[f]};   q[f]=cntq;}
void GetRt(int x,int fa)
{
	int mx=0;size[x]=1;
	for(int i=Head[x];i;i=eH[i].next)
		if(eH[i].to!=fa&&!b[eH[i].to])
		{
			GetRt(eH[i].to,x);
			size[x]+=size[eH[i].to];
			mx=max(mx,size[eH[i].to]);
		}
	int Sz=max(mx,tot-size[x]);
	if(Sz<mn) mn=Sz,rt=x;
}
void Dfs(int x,int fa)
{
	size[x]=1;in[x]=rt;
	for(int i=Head[x];i;i=eH[i].next)
		if(eH[i].to!=fa&&!b[eH[i].to])
		{
			Dfs(eH[i].to,x);
			size[x]+=size[eH[i].to];
		}
	for(int j=v[x];j;j=ev[j].next) d[ev[j].to]=1e9;
	for(int k=q[x];k;k=eq[k].next) S[++top]=eq[k].to;
}
inline void Renew(int*T,int x,int v){for(;x<=co;x+=x&-x) T[x]=min(T[x],v);}
int Query(int*T,int x)
{
	int res=1e9;
	for(;x;x-=x&-x) res=min(res,T[x]);
	return res;
}
void Solve(int x)
{
	b[x]=1;top=cc=co=0;Dfs(x,0);
	sort(S+1,S+top+1);
	for(int i=v[x];i;i=ev[i].next) d[ev[i].to]=0,from[ev[i].to]=++co,c[++cc]=ev[i].to; 
	for(int i=1;i<=cc;++i) 
		for(int j=head[c[i]];j;j=eh[j].next)
			if(in[bel[eh[j].to]]==x&&d[c[i]]+1<d[eh[j].to])
				d[c[++cc]=eh[j].to]=d[c[i]]+1,from[eh[j].to]=from[c[i]];
	for(int i=1;i<=top;++i)
	{
		int x=from[s[S[i]].X],dis=d[s[S[i]].X];
		if(dis>1e8) continue;
		if(s[S[i]].k==1) Renew(T1,x,dis-x),Renew(T2,co-x+1,dis+x);
		else Ans[S[i]]=min(Ans[S[i]],min(Query(T1,x)+x,Query(T2,co-x+1)-x)+dis);
	}
	for(int i=1;i<=top;++i) if(s[S[i]].k==1)
	{
		for(int x=from[s[S[i]].X];x<=co;x+=x&-x) T1[x]=1e9;
		for(int x=co-from[s[S[i]].X]+1;x<=co;x+=x&-x) T2[x]=1e9;
	}
	for(int i=Head[x];i;i=eH[i].next)
		if(!b[eH[i].to])
		{
			tot=size[eH[i].to];mn=1e9;
			GetRt(eH[i].to,x);Solve(rt);	
		}
}
bool cmp(int x,int y){return a[x].second<a[y].second;}
int main()
{
	fread(B,1,1<<26,stdin);
	n=read();
	for(int i=1;i<=n;++i) 
		a[i].first=read(),a[i].second=read(),
		mp.ins(a[i].first,a[i].second,i),rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	for(int i=1;i<=n;++i) if(!b[rk[i]])
	{
		int j=a[rk[i]].second;++m;
		for(int x;x=mp.count(a[rk[i]].first,j);++j) 
			insv(m,x),b[x]=1,bel[x]=m;
	}
	for(int i=1;i<=n;++i)
		for(int k=0;k<4;++k)
		{
			int x=a[i].first+dis[k][0],y=a[i].second+dis[k][1],z=mp.count(x,y);
			if(z)
			{
				insh(i,z);
				if(bel[i]!=bel[z]&&!mpe.count(bel[i],bel[z]))
					mpe.ins(bel[i],bel[z],1),insH(bel[i],bel[z]);	
			}
		}
	Q=read();
	for(int i=1;i<=Q;++i)
	{
		s[i].k=read();s[i].x=read();s[i].y=read();
		s[i].X=mp.count(s[i].x,s[i].y);
		if(s[i].k==1) Ans[i]=-1; else Ans[i]=1e9;
		insq(bel[s[i].X],i);		
	}
	memset(b,0,sizeof(b));
	memset(T1,63,sizeof(T1));memset(T2,63,sizeof(T2));
	mn=1e9;tot=m;GetRt(1,0);
/*	if(n==MN&&a[1].first==248477&&a[1].second==3)
	{
		for(int i=1;i<=n;++i) if(a[i].second!=3) cout<<a[i].first<<" "<<a[i].second<<endl;
		return 0;
	}*/
	Solve(rt);
//	if(n==MN&&a[1].first==248477&&a[1].second==3) cout<<s1<<" "<<s2<<endl;
	for(int i=1;i<=Q;++i) if(Ans[i]>=0) printf("%d\n",Ans[i]<1e8?Ans[i]:-1);
	return 0;
}