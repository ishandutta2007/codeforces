#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
using namespace std;
#define gc getchar
inline int rd()
{
	int t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(int x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}

int poi[200005],nxt[200005],head[200005];
int cnt,dis[200005],dep[200005],tr[200005*4];
int rt,yz[200005],in[200005],out[200005],tim,to[200005],Fa[200005];
int lazy[200005*4],p;
bool vis[200005];
int n;
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;poi[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;}
inline void GOT_RT()
{
	queue<int> Q;
	Q.push(1);dis[1]=1;
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();rt=x;
		for(int i=head[x];i;i=nxt[i])
			if(!dis[poi[i]])	dis[poi[i]]=dis[x]+1,Q.push(poi[i]);
	}
}
inline void Push(int x)
{
	if(lazy[x])
	{
		tr[x<<1]-=lazy[x];tr[x<<1|1]-=lazy[x];
		lazy[x<<1]+=lazy[x];lazy[x<<1|1]+=lazy[x];
		lazy[x]=0;
	}
}
inline int Dfs(int x,int fa)
{
	yz[x]=1;in[x]=++tim;to[tim]=x;Fa[x]=fa;
	for(int i=head[x];i;i=nxt[i])
	{
		if(poi[i]==fa)	continue;
		yz[x]=0;
		dep[poi[i]]=dep[x]+1;
		Dfs(poi[i],x);
	}
	out[x]=tim;
}

inline void change(int x,int l,int r,int to,int v)
{
	if(l==r){tr[x]=v;return;}
	int mid=l+r>>1;
	Push(x);
	if(to<=mid)	change(x<<1,l,mid,to,v);else	change(x<<1|1,mid+1,r,to,v);
	tr[x]=max(tr[x<<1],tr[x<<1|1]);
}
inline int query(int x,int l,int r)
{
	if(l==r){p=to[l];return tr[x];}
	Push(x);
	int mid=l+r>>1,tmp=0;
	if(tr[x<<1]==tr[x])	tmp=query(x<<1,l,mid);else	tmp=query(x<<1|1,mid+1,r);
	tr[x]=max(tr[x<<1],tr[x<<1|1]);
	return tmp;
}
inline void upd(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		lazy[x]++;tr[x]--;
		return;
	}
	int mid=l+r>>1;
	Push(x);
	if(ql<=mid)	upd(x<<1,l,mid,ql,qr);if(qr>mid)	upd(x<<1|1,mid+1,r,ql,qr);
	tr[x]=max(tr[x<<1],tr[x<<1|1]);
}
int main()
{
	n=rd();
	For(i,1,n-1)	add(rd(),rd());
	GOT_RT();
	Dfs(rt,rt);

	For(i,1,n)	if(yz[i])	change(1,1,n,in[i],dep[i]);//cout<<i<<' '<<rt<<' '<<dep[i]<<endl;
	cout<<1<<' ';
	vis[rt]=1;
	int ans=1;
	For(i,1,n-1)
	{
		int tmp=query(1,1,n);
		if(tmp<=0)	{For(j,i,n-1)	write_p(ans);return 0;}
		ans+=tmp;//P
		write_p(ans);
		while(p!=rt)
		{
			if(vis[p])	break;
			vis[p]=1;
			upd(1,1,tim,in[p],out[p]);	p=Fa[p];
		}
	}
}