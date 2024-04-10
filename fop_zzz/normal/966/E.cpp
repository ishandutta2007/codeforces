#include<bits/stdc++.h>
#define For(i,j,k)  for(register int i=j;i<=k;++i)
#define Dow(i,j,k)  for(register int i=k;i>=j;--i)
#define ll long long
#define min(x,y)	((x)>(y)?(y):(x))
#define max(x,y)	((x)>(y)?(x):(y))
using namespace std;
#define gc getchar
inline int read()
{
	int t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(int x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}

const int N=1e5+5;
int poi[N],nxt[N],head[N],cnt,son[N],siz[N],L[N],R[N],blo_to[N],id[N];
struct node{int num,v,to;}	p[N],tmp[N];
int tim,ans_Block[N],v[N],n,q,top[N],Fa[N],to[N],ans,line[N],in[N];
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline void Dfs1(int x,int fa)
{
	siz[x]=1;Fa[x]=fa;
	for(int i=head[x];i;i=nxt[i])
	{
		Dfs1(poi[i],x);siz[x]+=siz[poi[i]];
		if(siz[poi[i]]>siz[son[x]])	son[x]=poi[i];
	}
}
inline void Dfs2(int x,int aci)
{
	in[x]=++tim;to[tim]=x;top[x]=aci;
	if(son[x])	Dfs2(son[x],aci);
	for(int i=head[x];i;i=nxt[i])
		if(poi[i]!=son[x])	Dfs2(poi[i],poi[i]);
}
inline int lower(int x,int to)
{
	int l=L[x],r=R[x],tans=L[x]-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(p[mid].v<to)	tans=mid,l=mid+1;else	r=mid-1;
	}
	return tans-L[x]+1;
}
inline bool operator <(node a,node b){
	return a.v<b.v;
}
inline void Get_new(int x)
{
	ans-=ans_Block[x];
	ans_Block[x]=lower_bound(&p[L[x]],&p[R[x]+1],(node){0,line[x],0})-&p[L[x]];
	ans+=ans_Block[x];
}
inline bool cmp(node x,node y){return x.v<y.v;}
inline bool cmp1(int x,int y){return v[x]<v[y];}
inline void Upd(int l,int r,int delta)
{
	For(i,p[l].to+1,p[r].to-1)	
	{
		line[i]-=delta;
		Get_new(i);
	}
	if(p[l].to==p[r].to)
	{
		For(i,l,r)	p[blo_to[i]].v+=delta;
		For(i,L[p[l].to],R[p[l].to])	tmp[i]=p[i],id[i]=i,v[i]=p[i].v;
		sort(&id[L[p[l].to]],&id[R[p[l].to]]+1,cmp1);
		For(i,L[p[l].to],R[p[l].to])	p[i]=tmp[id[i]];
//		sort(&p[L[p[l].to]],&p[R[p[l].to]]+1,cmp);
		For(j,L[p[r].to],R[p[r].to])	blo_to[p[j].num]=j;
		Get_new(p[l].to);
		return;
	}	
	For(i,l,R[p[l].to])	p[blo_to[i]].v+=delta;
	For(i,L[p[l].to],R[p[l].to])	tmp[i]=p[i],id[i]=i,v[i]=p[i].v;
	sort(&id[L[p[l].to]],&id[R[p[l].to]]+1,cmp1);
	For(i,L[p[l].to],R[p[l].to])	p[i]=tmp[id[i]];
	For(j,L[p[l].to],R[p[l].to])	blo_to[p[j].num]=j;
	Get_new(p[l].to);
	
	For(i,L[p[r].to],r)	p[blo_to[i]].v+=delta;
	For(i,L[p[r].to],R[p[r].to])	tmp[i]=p[i],id[i]=i,v[i]=p[i].v;
	sort(&id[L[p[r].to]],&id[R[p[r].to]]+1,cmp1);
	For(i,L[p[r].to],R[p[r].to])	p[i]=tmp[id[i]];
	For(j,L[p[r].to],R[p[r].to])	blo_to[p[j].num]=j;
	Get_new(p[r].to);
}
bool alr[N];
inline void Solve(int x,int delta)
{
	p[blo_to[in[x]]].v-=delta*1e5;
	int r=p[blo_to[in[x]]].to;
	For(i,L[p[r].to],R[p[r].to])	tmp[i]=p[i],id[i]=i,v[i]=p[i].v;
	sort(&id[L[p[r].to]],&id[R[p[r].to]]+1,cmp1);
	For(i,L[p[r].to],R[p[r].to])	p[i]=tmp[id[i]];

	For(j,L[p[r].to],R[p[r].to])	blo_to[p[j].num]=j;
	Get_new(p[r].to);
	while(1)
	{
		Upd(in[top[x]],in[x],delta);
		if(top[x]==1)		break;
		x=Fa[top[x]];
	}
}

int main()
{
	// freopen("data.in","r",stdin);freopen("out.out","w",stdout);
	n=read();q=read();
	For(i,2,n)	add(read(),i);
	For(i,1,n)	v[i]=read();	
	Dfs1(1,1);Dfs2(1,1);
	For(i,1,n)	p[i].v=v[to[i]];
	int blo=sqrt(n)+1;
	For(i,1,n)	p[i].to=i/blo+1;	
	int number=p[n].to;
	For(i,1,number)		L[i]=1e9;
	For(i,1,n)	L[p[i].to]=min(L[p[i].to],i),R[p[i].to]=max(R[p[i].to],i);
	For(i,1,n)	p[i].num=i;	
	For(i,1,number)	{sort(&p[L[i]],&p[R[i]]+1,cmp);For(j,L[i],R[i])	blo_to[p[j].num]=j;}
	For(i,1,q)
	{
		int change=read();
		if(change<0)
			Solve(-change,1);else	Solve(change,-1);
		write_p(ans);
	}
}