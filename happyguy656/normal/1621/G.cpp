#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cout<<(k>>20)<<endl;}

const int mxn=2e5+3,mod=1e9+7;
int n,b[mxn],px[mxn],mv[mxn],v1[mxn],v2[mxn],m,d[mxn];
bool cmp1(int x,int y){if(b[x]!=b[y])return b[x]<b[y];return x>y;}
struct arrrrr{ll a[mxn];void add(int x,int y){for(;x<=n;x+=x&-x)a[x]+=y;}ll ask(int x){ll r=0;for(;x;x&=x-1)r+=a[x],r%=mod;return r;}void clr(){for(int i=0;i<=n;++i)a[i]=0;}}ar;
struct rrrrra{
    ll a[mxn];int tk[mxn][2],tn;
    void add(int x,int y){tk[++tn][0]=x,tk[tn][1]=y;for(;x;x&=x-1)a[x]+=y;}ll ask(int x){ll r=0;for(;x<=n;x+=x&-x)r+=a[x],r%=mod;return r;}
    void clr(){while(tn){int x=tk[tn][0],y=tk[tn--][1];for(;x;x&=x-1)a[x]-=y;}}
}ra;
ll slv(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",b+i),px[i]=i;sort(px+1,px+n+1,cmp1);for(int i=1;i<=n;++i)b[px[i]]=i;
    ar.clr(),ra.clr();for(int i=1;i<=n;++i)v1[i]=ar.ask(b[i])+1,ar.add(b[i],v1[i]);for(int i=n;i;--i)v2[i]=ra.ask(b[i])+1,ra.add(b[i],v2[i]);
    m=0;
    for(int i=n,v=0;i;--i)if(b[i]>v)v=b[i],d[++m]=v;
    ra.clr();ll re=0;
    for(int t=0;t<m;++t){
        ra.add(px[d[t+1]],1);
        int k=px[d[t+1]];
        for(int i=d[t+1]-1;i>d[t];--i){
            int x=px[i],v=ra.ask(x);re+=1ll*v1[x]*(v2[x]-v),re%=mod;
            ra.add(x,v);
        }
        ra.clr();
    }
    return re;
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%lld\n",(slv()+mod)%mod);
    return 0;
}