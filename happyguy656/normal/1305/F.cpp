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
mt19937 rnd(time(0));
inline int rd(int l,int r){return rnd()%(r-l+1)+l;}

const int mxn=2e5+3,mxm=1e6+3;
int n,ans,pr[mxm],pt,mv[mxm];ll a[mxn];
void chk(ll x){
    if(x<=1)return;
    ll t;ll re=0;
    for(int i=1;i<=n;++i)if(a[i]<x)re+=x-a[i];else t=a[i]%x,re+=min(t,x-t);
    ans=min(1ll*ans,re);
}
void fj(ll x){
    if(x<1)return;
    for(int i=1;i<=pt&&1ll*pr[i]*pr[i]<=x;++i)if(x%pr[i]==0){
        while(x%pr[i]==0)x/=pr[i];chk(pr[i]);
    }
    if(x>1)chk(x);
}
int main(){
    for(int i=2;i<mxm;++i){if(!mv[i])mv[i]=i,pr[++pt]=i;for(int j=1;i*pr[j]<mxm&&j<=pt&&pr[j]<=mv[i];++j)mv[i*pr[j]]=pr[j];}
    cin>>n;ans=n;for(int i=1;i<=n;++i)cin>>a[i];
    int T=30;while(T--){
        int x=rd(1,n);
        fj(a[x]),fj(a[x]-1),fj(a[x]+1);
    }
    printf("%d\n",ans);
    return 0;
}