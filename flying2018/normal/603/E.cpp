#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#define N 300010
using namespace std;
int fa[N],siz[N],tot;
int find(int x){return x==fa[x]?fa[x]:find(fa[x]);}
int chg[N],qtot;
void merge(int x,int y)
{
    int hx=find(x),hy=find(y);
    if(hx==hy) return;
    tot-=(siz[hx]&1)+(siz[hy]&1);
    if(siz[hx]>siz[hy]) swap(hx,hy);
    fa[hx]=hy;
    siz[hy]+=siz[hx];
    tot+=(siz[hy]&1);chg[++qtot]=hx;
}
void erase()
{
	int y=chg[qtot--],x=fa[y];
	tot-=siz[x]&1;
    siz[x]-=siz[y];fa[y]=y;
	tot+=(siz[x]&1)+(siz[y]&1);
}
struct road{
    int x,y,w,t;
    bool operator <(const road a)const{return w<a.w;}
}rd[N],rp[N];
int id[N],ans[N],ptot,n,m;
vector<road>ru[N<<2];
void insert(int u,int l,int r,int L,int R,road v)
{
    if(L>R) return;
    if(L<=l && r<=R){ru[u].push_back(v);return;}
    int mid=(l+r)>>1;
    if(L<=mid) insert(u<<1,l,mid,L,R,v);
    if(R>mid) insert(u<<1|1,mid+1,r,L,R,v);
}
void solve(int u,int l,int r,int pre)
{
    if(l>r) return;
    int mid=(l+r)>>1,ut=qtot;
    for(road p:ru[u]) merge(p.x,p.y),pre=max(pre,p.w);
    if(l==r)
    {
		int cnt=0;
		while(tot && ptot<m)
        {
			road u=rp[++ptot];
			if(u.t<=l)
				merge(u.x,u.y),pre=max(pre,u.w),rd[++cnt]=u;
		}
		if(!tot)
        {
			for(int i=1;i<=cnt;i++) insert(1,1,m,rd[i].t,l-1,rd[i]);
			ans[l]=pre;
		}
		else ans[l]=-1;
	}
    else
    {
		int mid=(l+r)>>1;
        solve(u<<1|1,mid+1,r,pre);
        solve(u<<1,l,mid,pre);
	}
	while(qtot!=ut) erase();
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) fa[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&rd[i].x,&rd[i].y,&rd[i].w),rd[i].t=i;
        rp[i]=rd[i];
    }
    sort(rp+1,rp+m+1);
    tot=n;
    solve(1,1,m,-1);
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}