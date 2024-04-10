#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
const ll INF=(1ll<<60)-1;
const int N=4e2+1,K=62,mod=998244353;
struct segment_tree{
    int n,rt,tot,cnt[K],qwq[K];
    ll a[K][N],b[K][N];
    struct ele{int ls,rs,tag;}t[N*K<<2];
    #define lc t[p].ls
    #define rc t[p].rs
    #define lson lc,L,mid
    #define rson rc,mid+1,R
    V ins(int&p,ll L,ll R,ll l,ll r){
        if(!p)p=++tot;
        if(L==l&&R==r)return void(t[p].tag=1);
        ll mid=L+R>>1;
        if(l>mid)return ins(rson,l,r);
        if(r<=mid)return ins(lson,l,r);
        ins(lson,l,mid),ins(rson,mid+1,r);
    }
    V input(){
        cin>>n;
        for(ll l,r;n--;)
            cin>>l>>r,ins(rt,0,INF,l,r);
    }
    V dfs(rnt p,ll L,ll R,rnt dep){
        b[dep][++qwq[dep]]=L&R;
        if(t[p].tag)
            return void(a[dep][++cnt[dep]]=L&R);
        ll mid=L+R>>1;
        if(lc)dfs(lson,dep+1);
        if(rc)dfs(rson,dep+1);
    }
    V init(){dfs(rt,0,INF,0);}
}A,B;
int n,m,ans;
struct P{
    ll l,r;
    bool operator<(const P&u)const{
        return l==u.l?r<u.r:l<u.l;
    }
    I val(){
        return 1ll*((r-l+1)%mod)*((l+r)%mod)%mod;
    }
}a[10000000];
V check(int&x){x-=mod,x+=x>>31&mod;}
int main(){
    A.input(),A.init();
    B.input(),B.init();
    FOR(i,0,60){
        FOR(j,1,A.cnt[i])FOR(k,1,B.qwq[i])
            n++,a[n].l=A.a[i][j]^B.b[i][k],a[n].r=a[n].l+(1ll<<60-i)-1;
        FOR(j,1,B.cnt[i])FOR(k,1,A.qwq[i])
            n++,a[n].l=B.a[i][j]^A.b[i][k],a[n].r=a[n].l+(1ll<<60-i)-1;
    }
    sort(a+1,a+1+n);
    ll l=a[1].l,r=a[1].r;
    FOR(i,2,n){
        if(a[i].l>r)
            check(ans+=((r-l+1)%mod)*((l+r)%mod)%mod),l=a[i].l;
        if(r<a[i].r)
            r=a[i].r;
    }
    check(ans+=((r-l+1)%mod)*((l+r)%mod)%mod);
    cout<<1ll*(mod+1)/2*ans%mod;
    return 0;
}