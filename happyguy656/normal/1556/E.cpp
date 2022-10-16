#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int abc;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e5+3;
int n,qn;ll a[mxn];
#define mid ((l+r)>>1)
struct seeee{
    ll mx[mxn*4],mn[mxn*4];
    void bu(int x=1,int l=1,int r=n){
        if(l==r)return mx[x]=mn[x]=a[l],void();
        bu(x*2,l,mid),bu(x*2+1,mid+1,r);mx[x]=max(mx[x*2],mx[x*2+1]),mn[x]=min(mn[x*2],mn[x*2+1]);
    }
    ll ask1(int lc,int rc,int x=1,int l=1,int r=n){
        if(lc<=l&&r<=rc)return mx[x];
        ll re=-1e18;if(lc<=mid)re=ask1(lc,rc,x*2,l,mid);if(rc>mid)re=max(re,ask1(lc,rc,x*2+1,mid+1,r));return re;
    }
    ll ask2(int lc,int rc,int x=1,int l=1,int r=n){
        if(lc<=l&&r<=rc)return mn[x];
        ll re=1e18;if(lc<=mid)re=ask2(lc,rc,x*2,l,mid);if(rc>mid)re=min(re,ask2(lc,rc,x*2+1,mid+1,r));return re;
    }
}se;
#undef mid
int main(){
    cin>>n>>qn;for(int i=1;i<=n;++i)cin>>a[i];for(int i=1,x;i<=n;++i)cin>>x,a[i]-=x;
    for(int i=1;i<=n;++i)a[i]+=a[i-1];se.bu();
    while(qn--){
        int l,r;scanf("%d%d",&l,&r);
        ll t1=se.ask1(l,r),t2=se.ask2(l,r);
        t1-=a[l-1],t2-=a[l-1];
        if(t1>0||a[r]!=a[l-1])puts("-1");else printf("%lld\n",-t2);
    }
    return 0;
}