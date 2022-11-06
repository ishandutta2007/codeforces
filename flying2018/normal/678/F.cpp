#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 300010
#define inf 2000000000000000000
#define ll long long
#pragma GCC optimize(2,3)
using namespace std;
struct node{
    ll x,y;
    node(ll X=0,ll Y=0):x(X),y(Y){}
    node operator +(node a){return node(x+a.x,y+a.y);}
    node operator -(node a){return node(x-a.x,y-a.y);}
    ll operator *(node a){return x*a.y-y*a.x;}
    bool operator <(const node a)const{return x==a.x?y<a.y:x<a.x;}
};
ll cross(node a,node o,node b){return (a-o)*(b-o);}
node tmp[N];
ll calc(node a,ll k){return a.x*k+a.y;}
struct convex{
    vector<node>v;
    int pos;
    void push(node a){v.push_back(a);}
    void init()
    {
        int t=0;pos=0;
        for(node u:v)
        {
            while(t>1 && cross(tmp[t-1],tmp[t],u)<=0) --t;
            tmp[++t]=u;
        }
        v.clear();
        for(int i=1;i<=t;i++) v.push_back(tmp[i]);
    }
    ll answer(ll k)
    {
        if(v.empty()) return -inf;
        if(pos+1==v.size()) return calc(v[pos],k);
        while(pos+1<v.size() && calc(v[pos],k)<=calc(v[pos+1],k)) pos++;
        return calc(v[pos],k);
    }
}t[N<<2];
void insert(int u,int l,int r,int L,int R,node v)
{
    if(L<=l && r<=R){t[u].push(v);return;}
    int mid=(l+r)>>1;
    if(L<=mid) insert(u<<1,l,mid,L,R,v);
    if(R>mid) insert(u<<1|1,mid+1,r,L,R,v);
}
ll answer(int u,int l,int r,int p,ll v)
{
    ll ans=t[u].answer(v);
    if(l==r) return ans;
    int mid=(l+r)>>1;
    if(p<=mid) return max(ans,answer(u<<1,l,mid,p,v));
    else return max(ans,answer(u<<1|1,mid+1,r,p,v));
}
struct ques{
    int p;ll k,ans;
    bool operator <(const ques a)const{return k<a.k;}
}q[N];
bool cmp(ques a,ques b){return a.p<b.p;}
int qt=0;
struct nodes{
    node p;int l,r;
    bool operator <(const nodes a)const{return p<a.p;}
}rem[N];
bool has[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int opt;ll x,y;
        scanf("%d%lld",&opt,&x);
        if(opt==1)
        {
            scanf("%lld",&y);
            rem[i].p=node(x,y);has[i]=true;
            rem[i].l=i;
        }
        else if(opt==2) rem[x].r=i,has[x]=false;
        else q[++qt]=(ques){i,x};
    }
    for(int i=1;i<=n;i++) if(has[i]) rem[i].r=n;
    sort(rem+1,rem+n+1);
    for(int i=1;i<=n;i++)
    if(rem[i].r) insert(1,1,n,rem[i].l,rem[i].r,rem[i].p);
    for(int i=1;i<=2*n-1;i++) t[i].init();
    sort(q+1,q+qt+1);
    for(int i=1;i<=qt;i++) q[i].ans=answer(1,1,n,q[i].p,q[i].k);
    sort(q+1,q+qt+1,cmp);
    for(int i=1;i<=qt;i++)
    if(q[i].ans<=-inf) puts("EMPTY SET");
    else printf("%lld\n",q[i].ans);
    return 0;
}