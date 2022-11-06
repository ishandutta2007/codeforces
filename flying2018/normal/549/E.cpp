#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 20010
#define ll long long
#define ld long double
#define eps 1e-9
using namespace std;
struct point{
    int x,y;
    point(ll X=0,ll Y=0):x(X),y(Y){}
    point operator +(const point a)const{return point(x+a.x,y+a.y);}
    point operator -(const point a)const{return point(x-a.x,y-a.y);}
    bool operator <(const point a)const{return x==a.x?y<a.y:x<a.x;}
    int operator *(const point a)const{return x*a.x+y*a.y;}
    int operator ^(const point a)const{return x*a.y-y*a.x;}
}pa[N],pb[N],pc[N];
inline int cross(point a,point o,point b){return (a-o)^(b-o);}
inline ld slope(point a,point o,point b){return 1.0L*((a-o)*(b-o))/cross(a,o,b);}
int n,m;
bool check(point x,point y)
{
    ld l=-1e50,r=1e50;
    for(int i=1;i<=n;i++)
    if(cross(x,pa[i],y))
    {
        ld sl=slope(x,pa[i],y);
        if(cross(pa[i],x,y)<0) l=max(l,sl);
        else r=min(r,sl);
    }
    for(int i=1;i<=m;i++)
    {
        if(cross(x,pb[i],y))
        {
            ld sl=slope(x,pb[i],y);
            if(cross(pb[i],x,y)>0) l=max(l,sl);
            else r=min(r,sl);
        }
        else if(pb[i].x>=min(x.x,y.x) && pb[i].x<=max(x.x,y.x) && pb[i].y>=min(x.y,y.y) && pb[i].y<=max(x.y,y.y)) return false;
    }
    return r-l>eps;
}
bool dfs(int l,int r)
{
    if(check(pc[l],pc[r])) return true;
    if(r-l<=1) return false;
    int u=0;
    ld v=1e50;
    for(int i=l+1;i<r;i++)
    {
        ld sl=slope(pc[l],pc[i],pc[r]);
        if(sl<v) v=sl,u=i;
    }
    return dfs(l,u) || dfs(u,r);
}
int tot=0;
bool get_convex()
{
    tot=0;
    for(int i=1;i<=n;i++)
    {
        while(tot>1 && cross(pc[tot],pc[tot-1],pa[i])<=0) tot--;
        pc[++tot]=pa[i];
    }
    int s=tot;
    for(int i=n-1;i;i--)
    {
        while(tot>s && cross(pc[tot],pc[tot-1],pa[i])<=0) tot--;
        pc[++tot]=pa[i];
    }
    --tot;
    return dfs(1,tot);
}
int main()
{
    scanf("%d%d",&n,&m);
    if(n==1 || m==1){puts("YES");return 0;}
    for(int i=1;i<=n;i++) scanf("%d%d",&pa[i].x,&pa[i].y);
    for(int i=1;i<=m;i++) scanf("%d%d",&pb[i].x,&pb[i].y);
    sort(pa+1,pa+n+1);sort(pb+1,pb+m+1);
    if(get_convex()){puts("YES");return 0;}
    swap(n,m);
    for(int i=1;i<=max(n,m);i++) swap(pa[i],pb[i]);
    if(get_convex()){puts("YES");return 0;}
    puts("NO");
    return 0;
}