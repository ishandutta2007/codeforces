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

const int mxn=3e5+3;
int n,a[mxn],mx;
ll sm[mxn],b[mxn];
struct zsz{int a[mxn];void ins(int x){int y=x;for(;x<=mx;x+=x&-x)++a[x];}
    int ask(int x){x=min(x,mx);int r=0;for(;x;x-=x&-x)r+=a[x];return r;}int qh(int l,int r){return ask(r)-ask(l-1);}}ar;
struct zzs{ll a[mxn];void ins(int x,int y){for(;x<=mx;x+=x&-x)a[x]+=y;}
    ll ask(int x){ll r=0;for(;x;x-=x&-x)r+=a[x];return r;}}ra;
int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i),sm[i]=sm[i-1]+a[i],mx=max(mx,a[i]);
    for(int t=1;t<=n;++t){
        b[t]=b[t-1];int x=a[t];
        for(int i=1;i*x<=mx;++i)b[t]+=1ll*x*i*ar.qh(i*x,(i+1)*x-1);
        ar.ins(x);
        if(t-1){
            x=a[t-1];for(int i=1;x*i<=mx;++i){ra.ins(x*i,x*i);if(x*(i+1)<=mx)ra.ins(x*(i+1),-x*i);}
            b[t]+=ra.ask(a[t]);
        }

    }
    for(int i=1;i<=n;++i)printf("%lld ",(i-1)*sm[i]-b[i]);puts("");
    return 0;
}