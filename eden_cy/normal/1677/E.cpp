#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+50;
const int M=1e6+50;

#define ls p<<1
#define rs p<<1|1
#define lson L,mid,ls
#define rson mid+1,R,rs

struct expr {
    ll k,b;
    expr() {}
    expr(ll _k,ll _b) {
        k=_k;b=_b;
    }
    expr operator *(const int &s) const{
        return expr(k*s,b*s);
    }
    expr operator +(const expr &s) const{
        return expr(k+s.k,b+s.b);
    }
};
expr sum[N<<2];
expr laz[N<<2];
void Down(int L,int R,int p) {
    if(!laz[p].k && !laz[p].b) return ;
    int mid=L+R>>1;
    sum[ls]=sum[ls]+laz[p]*(mid-L+1);
    sum[rs]=sum[rs]+laz[p]*(R-mid);
    laz[ls]=laz[ls]+laz[p];
    laz[rs]=laz[rs]+laz[p];
    laz[p]=expr(0,0);
}
void upd(int L,int R,int p,int l,int r,expr v) {
    if(L==l && R==r) {
        sum[p]=sum[p]+v*(R-L+1);
        laz[p]=laz[p]+v;
        return ;
    }
    Down(L,R,p);
    int mid=L+R>>1;
    if(r<=mid) upd(lson,l,r,v);
    else if(l>mid) upd(rson,l,r,v);
    else upd(lson,l,mid,v),upd(rson,mid+1,r,v);
    sum[p]=sum[ls]+sum[rs];
}
expr qry(int L,int R,int p,int l,int r) {
    if(L==l && R==r) return sum[p];
    Down(L,R,p);
    int mid=L+R>>1;
    if(r<=mid) return qry(lson,l,r);
    else if(l>mid) return qry(rson,l,r);
    else return qry(lson,l,mid)+qry(rson,mid+1,r);
}

int a[N],p[N];
int mx[N][22];
vector<pii> g[N];
int Log[N];
int RMQ(int L,int R) {
    int K=Log[R-L+1];
    return max(mx[L][K],mx[R-(1<<K)+1][K]);
}
struct node {
    int l,r,v;
};
vector<node> u[N];
pii b[N];
void build(int L,int R) {
    int v=RMQ(L,R);
    int x=p[v];
    int K=0;
    for(auto e: g[v]) if(L<=e.first && e.second<=R) {
        b[++K]=make_pair(min(x,e.first),max(x,e.second));
    }
    sort(b+1,b+K+1);
    int pr=R+1;
    DOR(i,K,1) {
        if(i>1 && b[i-1].first==b[i].first) continue;
        int l=b[i].first,r=b[i].second;
        if(pr<=R) u[l].push_back((node){pr,R,-1});
        pr=min(pr,r);
        u[l].push_back((node){pr,R,1});
    }
    if(pr<=R) u[L-1].push_back((node){pr,R,-1});
    if(L<x) build(L,x-1);
    if(x<R) build(x+1,R);
}
vector<pii> Q[N];
ll ans[M];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    Log[1]=0;
    FOR(i,2,n) Log[i]=Log[i>>1]+1;
    FOR(i,1,n) scanf("%d",&a[i]),mx[i][0]=a[i],p[a[i]]=i;
    FOR(j,1,20) FOR(i,1,n-(1<<(j-1))) mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
    FOR(i,1,n) FOR(j,1,n/i) if(p[i]<p[j]) g[i*j].push_back(make_pair(p[i],p[j]));
    FOR(i,1,m) {
        int l,r;
        scanf("%d%d",&l,&r);
        Q[l].push_back(make_pair(r,i));
    }
    build(1,n);
    DOR(i,n,1) {
        for(auto e: u[i]) {
            upd(1,n,1,e.l,e.r,expr(-1,i+1)*e.v);
        }
        for(auto e: Q[i]) {
            auto w=qry(1,n,1,i,e.first);
            ans[e.second]=w.k*i+w.b;
        }
    }
    FOR(i,1,m) printf("%lld\n",ans[i]);
    return 0;
}