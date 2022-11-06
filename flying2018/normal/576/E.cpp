#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 500010
#define D 55
#define P pair<int,int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int stk[N<<1],tot,col[N<<1];
struct node{
	int val[N],f[N],siz[N];
	int find_fa(int x){return f[x]?find_fa(f[x]):x;}
	int find_v(int x){return f[x]?val[x]^find_v(f[x]):0;}
	void merge(int x,int y,int c)
	{
		int hx=find_fa(x),hy=find_fa(y);
		if(hx==hy) return;
		if(siz[hx]<siz[hy])
		{
			stk[++tot]=hx;
			col[tot]=c;
            val[hx]=find_v(x)^find_v(y)^1;
			f[hx]=hy;
		}
		else
		{
			stk[++tot]=hy;
			col[tot]=c;
            val[hy]=find_v(x)^find_v(y)^1;
			f[hy]=hx;
			if(siz[hx]==siz[hy])
			{
				siz[hx]++;
				stk[++tot]=-hx;
				col[tot]=c;
			}
		}
	}
}p[D];
vector<P >qn[N<<2];
void reset(int x)
{
	for(;tot>x;tot--)
	if(stk[tot]>0) p[col[tot]].f[stk[tot]]=0;
	else p[col[tot]].siz[-stk[tot]]--;
}
void insert(int u,int l,int r,int L,int R,P a)
{
	if(L>R) return;
	if(L<=l && r<=R){qn[u].push_back(a);return;}
	int mid=(l+r)>>1;
	if(L<=mid) insert(u<<1,l,mid,L,R,a);
	if(R>mid) insert(u<<1|1,mid+1,r,L,R,a);
}
struct node2{
	int r,c,id;
}opt[N];
int clr[N];
int n,m,Q;
int x[N],y[N];
void solve(int u,int l,int r)
{
	int res=tot;
	for(P a:qn[u]) p[a.fi].merge(x[a.se],y[a.se],a.fi);
	if(l==r)
	{
		int x=::x[opt[l].id],y=::y[opt[l].id],c=opt[l].c;
		if(p[c].find_fa(x)!=p[c].find_fa(y) || p[c].find_v(x)!=p[c].find_v(y)){puts("YES");clr[opt[l].id]=opt[l].c;}
		else puts("NO");
		insert(1,1,Q,l+1,opt[l].r,MP(clr[opt[l].id],opt[l].id));
		reset(res);
		return;
	}
	int mid=(l+r)>>1;
	solve(u<<1,l,mid);
	solve(u<<1|1,mid+1,r);
	reset(res);
}
int lst[N];
int main()
{
	int k;
	scanf("%d%d%d%d",&n,&m,&k,&Q);
	for(int i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=Q;i++)
	{
		int id,c;
		scanf("%d%d",&id,&c);
		if(lst[id]) opt[lst[id]].r=i-1;
		opt[i].id=id;opt[i].c=c;opt[i].r=Q;
        lst[id]=i;
	}
	solve(1,1,Q);
	return 0;
}