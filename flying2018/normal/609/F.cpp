#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#define MAXN 1000000000ll
#define N 200010
#define ll long long
using namespace std;
int val[N*30],ls[N*30],rs[N*30],tot;
void push_down(int u)
{
    if(!val[u]) return;
    if(!ls[u]) ls[u]=++tot;
    if(!rs[u]) rs[u]=++tot;
    val[ls[u]]=val[rs[u]]=val[u];val[u]=0;
}
void assign(int &u,int l,int r,int L,ll R,int v)
{
    if(!u) u=++tot;
    if(L<=l && r<=R){val[u]=v;return;}
    int mid=(l+r)>>1;
    push_down(u);
    if(L<=mid) assign(ls[u],l,mid,L,R,v);
    if(R>mid) assign(rs[u],mid+1,r,L,R,v);
}
int answer(int u,int l,int r,int p)
{
    if(!u || val[u]) return val[u];
    int mid=(l+r)>>1;
    if(p<=mid) return answer(ls[u],l,mid,p);
    else return answer(rs[u],mid+1,r,p);
}
struct flys{
    int p,b;
    flys(int P=0,int B=0):p(P),b(B){}
    bool operator <(const flys a)const{return p==a.p?b<a.b:p<a.p;}
};
multiset<flys>s;
struct frog{
    int x,tot,id;ll t;
    bool operator <(const frog a)const{return x<a.x;}
}fr[N];
bool cmp(frog a,frog b){return a.id<b.id;}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%lld",&fr[i].x,&fr[i].t),fr[i].id=i;
    sort(fr+1,fr+n+1);
    int maxn=0,root=0;
    for(int i=1;i<=n;i++)
    if(fr[i].x+fr[i].t>maxn) assign(root,1,MAXN,max(maxn+1,fr[i].x),fr[i].x+fr[i].t,i),maxn=fr[i].x+fr[i].t;
    while(m --> 0)
    {
        int p,b,r;
        scanf("%d%d",&p,&b);
        if((r=answer(root,1,MAXN,p))==0) s.insert(flys(p,b));
        else
        {
            ll t=fr[r].t;
            t+=b;fr[r].tot++;
            for(auto u=s.upper_bound(flys(fr[r].x,-1));u!=s.end();u=s.upper_bound(flys(fr[r].x,-1)))
            if(u->p<=fr[r].x+t) t+=u->b,fr[r].tot++,s.erase(u);
            else break;
            if(fr[r].x+fr[r].t<=MAXN) assign(root,1,MAXN,fr[r].x+fr[r].t,min(fr[r].x+t,MAXN),r);
            fr[r].t=t;
        }
    }
    sort(fr+1,fr+n+1,cmp);
    for(int i=1;i<=n;i++) printf("%d %lld\n",fr[i].tot,fr[i].t);
    return 0;
}