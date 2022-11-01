#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define mk make_pair
#define pa pair<int,int>
#define fir  first
#define sec  second
#define inf 1e9+5
using namespace std;

inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
/*------------------------------------------------------------------------------------------------------*/

const int N=2e5+5;
int dfn[N],low[N],q[N],top1,tim,Fa[N],top[N],w[N],n,tr[N*4],dep[N],siz[N],To[N];
priority_queue<pa,vector<pa>,greater<pa> > que[N]; 
int poi[N*2],nxt[N*2],head[N*2],cnt,poi1[N*2],nxt1[N*2],head1[N*2],cnt1,num,son[N],in[N],out[N];
inline void add(int x,int y)
{
	poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;
	poi[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;
}
inline void Add(int x,int y){poi1[++cnt1]=y;nxt1[cnt1]=head1[x];head1[x]=cnt1;}
inline void Tar(int x)
{
	dfn[x]=low[x]=++tim;q[++top1]=x;
	for(int i=head[x];i;i=nxt[i])
	{
		if(!dfn[poi[i]])
		{
			Tar(poi[i]);low[x]=min(low[x],low[poi[i]]);
			if(dfn[x]<=low[poi[i]])	
			{
				num++;
				for(;q[top1+1]!=poi[i];top1--)
				{
					Add(num,q[top1]);
					Fa[q[top1]]=num;
					que[num].push(mk(w[q[top1]],q[top1]));
				}
				w[num]=(que[num].top()).fir;
				Add(x,num);Fa[num]=x;
			}
		}else	low[x]=min(low[x],dfn[poi[i]]);
	}
}
inline void Dfs1(int x)
{
	siz[x]=1;
	for(int i=head1[x];i;i=nxt1[i])
	{
		dep[poi1[i]]=dep[x]+1;
		Dfs1(poi1[i]);
		siz[x]+=siz[poi1[i]];
		if(siz[poi1[i]]>siz[son[x]])	son[x]=poi1[i];
	}
}
inline void Dfs2(int x,int aci)
{
	top[x]=aci;
	in[x]=++tim;To[tim]=x;
	if(son[x])	Dfs2(son[x],aci);
	for(int i=head1[x];i;i=nxt1[i])
		if(son[x]!=poi1[i])	Dfs2(poi1[i],poi1[i]);
	out[x]=tim;
}
inline int Query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)	return tr[x];
	int mid=l+r>>1,tmp=inf;
	if(ql<=mid)	tmp=Query(x<<1,l,mid,ql,qr);
	if(qr>mid)	tmp=min(tmp,Query(x<<1|1,mid+1,r,ql,qr));
	return tmp;
}
inline void Build(int x,int l,int r)
{
	if(l==r)
	{
		tr[x]=w[To[l]];
		return;
	}
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	tr[x]=min(tr[x<<1],tr[x<<1|1]);
}
inline void Chg(int x,int l,int r,int to,int v)
{
	if(l==r){tr[x]=v;return;}
	int mid=l+r>>1;
	if(to<=mid)	Chg(x<<1,l,mid,to,v);
	else	Chg(x<<1|1,mid+1,r,to,v);
	tr[x]=min(tr[x<<1],tr[x<<1|1]);
}
inline int LCA(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])	swap(x,y);
		x=Fa[top[x]];
	}
	if(dep[x]>dep[y])	return y;else	return x;
}
inline int Que(int x,int lca)
{
	int ret=inf;
	while(top[x]!=top[lca])
	{
		ret=min(ret,Query(1,1,tim,in[top[x]],in[x]));
		x=Fa[top[x]];
	}
	
	ret=min(ret,Query(1,1,tim,in[lca],in[x]));
//	cout<<top[x]<<' '<<top[lca]<<' '<<in[lca]<<' '<<in[x]<<' '<<ret<<endl;
	return ret;
}
int m,Q;
char opt[5];
int main()
{
	n=read();m=read();Q=read();num=n;
	For(i,1,n)	w[i]=read();
	For(i,1,m)	add(read(),read());
	Tar(1);
	tim=0;
	Dfs1(1);Dfs2(1,1);
	Build(1,1,tim);
	while(Q--)
	{
		scanf("\n%s",opt+1);
		if(opt[1]=='C')
		{
			int x=read(),y=read();
			w[x]=y;
			que[Fa[x]].push(mk(y,x));
			while(1)
			{
				pa tmp=que[Fa[x]].top();
				if(w[tmp.sec]!=tmp.fir)	que[Fa[x]].pop();
				else	break;
			}
			w[Fa[x]]=(que[Fa[x]].top()).fir;
			Chg(1,1,tim,in[Fa[x]],w[Fa[x]]);
			Chg(1,1,tim,in[x],y);
		}
		else
		{
			int x=read(),y=read();
			int lca=LCA(x,y);
			int t1=Que(x,lca),t2=Que(y,lca),ans=0;
			if(lca>n)	ans=w[Fa[lca]];
			else	ans=inf;
//			cout<<t1<<' '<<t2<<' '<<w[Fa[lca]]<<endl;
			ans=min(ans,min(t1,t2));
			writeln(ans);
		}
	}
}