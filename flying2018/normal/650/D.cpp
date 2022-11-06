#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 800010
using namespace std;
int a[N],pa[N],n,m;
int tn,pr[N],sf[N];
struct tree_arr{
	int v[N],opt;
	void add(int x,int y){if(opt) x=tn-x;for(;x<=tn;x+=(x&-x)) v[x]=max(v[x],y); }
	int qry(int x){if(opt) x=tn-x;int r=0; for(;x;x-=(x&-x)) r=max(r,v[x]); return r;}
	void clr(){for(int i=1;i<=tn;i++) v[i]=0;}
}t[2];
struct node{
	int x,y,id,pr,sf;
	bool operator <(const node a)const{return x==a.x?y<a.y:x<a.x;}
}q[N];
int cnt[N],ans[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),pa[++tn]=a[i];
	for(int i=1;i<=m;i++) scanf("%d%d",&q[i].x,&q[i].y),q[i].id=i,pa[++tn]=q[i].y;
	sort(pa+1,pa+tn+1);
	tn=unique(pa+1,pa+tn+1)-pa-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(pa+1,pa+tn+1,a[i])-pa;
	for(int i=1;i<=m;i++) q[i].y=lower_bound(pa+1,pa+tn+1,q[i].y)-pa;
	sort(q+1,q+m+1);
	++tn,t[1].opt=1;
    for(int i=1;i<=n;i++) t[0].add(a[i],pr[i]=t[0].qry(a[i]-1)+1);
    for(int i=n;i>=1;i--) t[1].add(a[i],sf[i]=t[1].qry(a[i]+1)+1);
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,pr[i]+sf[i]-1);
    for(int i=1;i<=n;i++) if(pr[i]+sf[i]-1==res) ++cnt[pr[i]];
    t[0].clr(),t[1].clr();
    int u=1;
    for(int i=1;i<=m;i++)
    {
        for(;u<q[i].x;u++) t[0].add(a[u],pr[u]);
        q[i].pr=t[0].qry(q[i].y-1);
    }
    u=n;
    for(int i=m;i>=1;i--)
    {
        for(;u>q[i].x;u--) t[1].add(a[u],sf[u]);
        q[i].sf=t[1].qry(q[i].y+1);
    }
    for(int i=1;i<=m;i++)
    {
        if(q[i].sf+q[i].pr+1>res) ans[q[i].id]=q[i].sf+q[i].pr+1;
        else if(pr[q[i].x]+sf[q[i].x]-1==res && cnt[pr[q[i].x]]==1 && q[i].sf+q[i].pr+1<res) ans[q[i].id]=res-1;
        else ans[q[i].id]=res;
    }
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}