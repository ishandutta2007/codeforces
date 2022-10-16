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
int n,a[mxn];
bool wk(){
    int c1=0,c2=0;ll ans=0;for(int i=1;i<=n;++i)if(a[i])++c1;else ++c2;
    if(n&1){
        if(c1==n/2){
            c1=c2=0;for(int i=1;i<=n;++i)if(a[i])++c1,ans+=max(i-2*c1,0);else ++c2,ans+=max(i-2*c2+1,0);
        }else if(c2==n/2){
            c1=c2=0;for(int i=1;i<=n;++i)if(a[i])++c1,ans+=max(i-2*c1+1,0);else ++c2,ans+=max(i-2*c2,0);
        }else return 0;
        printf("%lld\n",ans);
        return 1;
    }else{
        if(c1*2!=n)return 0;
        c1=c2=0;for(int i=1;i<=n;++i)if(a[i])++c1,ans+=max(i-2*c1,0);else ++c2,ans+=max(i-2*c2+1,0);
        ll ans0=ans;ans=0;
        c1=c2=0;for(int i=1;i<=n;++i)if(a[i])++c1,ans+=max(i-2*c1+1,0);else ++c2,ans+=max(i-2*c2,0);
        printf("%lld\n",min(ans0,ans));
        return 1;
    }
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)cin>>a[i],a[i]&=1;
        if(!wk())puts("-1");
    }
    return 0;
}