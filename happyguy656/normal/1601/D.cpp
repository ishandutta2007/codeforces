#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef pair<int,int>pii;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e6+3;
int li[mxn],ln,n,m,n1,n2;
ll va[mxn],dp[mxn];
struct thr{int a,b,w;bool operator<(const thr&x)const{return a<x.a;}}b[mxn],b1[mxn],b2[mxn];
bool cmp1(const thr&a,const thr&b){return a.a!=b.a?a.a<b.a:a.b<b.b;}
bool cmp2(const thr&a,const thr&b){return a.b<b.b;}
struct zzz{
    ll a[mxn];void add(int x,ll y){for(;x;x&=x-1)a[x]+=y;}
    ll ask(int x){ll r=0;for(;x<=ln;x+=x&-x)r+=a[x];return r;}
}ar;
struct sss{
    ll a[mxn];
    void add(int x,ll y){for(;x<=n1;x+=x&-x)a[x]=max(a[x],y);}
    ll ask(int x){ll r=0;for(;x;x&=x-1)r=max(r,a[x]);return r;}
}ra;
int main(){
    int D;cin>>m>>D;for(int i=1;i<=m;++i){int x,y;scanf("%d%d",&x,&y);if(x<D)continue;b[++n]={x,y,1};li[++ln]=x,li[++ln]=y;}
    sort(li+1,li+ln+1),ln=unique(li+1,li+ln+1)-li-1;
    for(int i=1;i<=n;++i)b[i].a=lower_bound(li+1,li+ln+1,b[i].a)-li,b[i].b=lower_bound(li+1,li+ln+1,b[i].b)-li;
    for(int i=1;i<=n;++i)if(b[i].a<b[i].b)b1[++n1]=b[i];else b2[++n2]=b[i];
    sort(b1+1,b1+n1+1,cmp2),sort(b2+1,b2+n2+1,cmp1);
    for(int i=1,j=0;i<=n1;++i){while(j!=n2&&b2[j+1].a<b1[i].b)++j,ar.add(b2[j].b,1);b1[i].w-=ar.ask(b1[i].a+1);}
    sort(b1+1,b1+n1+1,cmp1);for(int i=1;i<=n1;++i)va[i]=b1[i].w;
    ll ans=0;
    for(int i=1;i<=n1;++i){
        ll t=ra.ask(i)+va[i];ans=max(ans,t);
        ra.add(lower_bound(b1+1,b1+n1+1,(thr){b1[i].b,0,0})-b1,t);
    }
    ans+=n2;
    printf("%lld\n",ans);
    return 0;
}