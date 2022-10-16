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
typedef vector<ll>VL;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3,mod=998244353;
ll por(ll x,int y=mod-2){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%mod;x=x*x%mod;}return r;}
int n,a[mxn],m,R[mxn],N;ll w[2][mxn];bool b[mxn];
bool chk(){
    for(int i=1;i<=n;){
        int x=a[i],y=x;b[++m]=x>1;
        while(y--){if(a[i]!=x)return 0;++i;}
    }
    return 1;
}

struct VV{
    VL a[2][2];void ii(int s){a[0][0].resize(s),a[0][1].resize(s),a[1][0].resize(s),a[1][1].resize(s);}
};
void ntt(VL&a,int n,bool tp=0){
    for(int i=1;i<n;++i)R[i]=R[i>>1]>>1,R[i]|=(i&1)*(n>>1);
    for(int i=0;i<n;++i)a[i]%=mod;
    for(int i=0;i<n;++i)if(i>R[i])swap(a[i],a[R[i]]);
    for(int d=1,t=N>>1;d<n;d*=2,t>>=1){
        for(int i=0;i<n;i+=d*2)for(int j=0;j<d;++j){
            ll x=a[i+j+d]*w[tp][t*j];
            a[i+j+d]=(a[i+j]-x)%mod,a[i+j]=(a[i+j]+x)%mod;
        }
    }
    if(tp){ll iv=por(n);for(int i=0;i<n;++i)a[i]=a[i]*iv%mod;}
}
VL d;
void NTT(VL&a,VL&b,VL&c,int t){
    for(int i=0;i<n;++i)d[i]=a[i]*b[i]%mod;ntt(d,n,1);
    for(int i=0;i<n;++i)if(d[i])c[i]+=d[i]*t,c[i-1]+=d[i]*2;
    for(int i=0;i<n;++i)c[i]%=mod;
}
VV sol(int L,int R){
    if(L==R){VV r;r.ii(2);r.a[b[L]][b[L]][1]=1;return r;}
    int md=(L+R)>>1;VV v1=sol(L,md),v2=sol(md+1,R),re;
//    printf("!%d %d\n",L,R);
    n=1;while(n<=R-L+1)n*=2;
    v1.ii(n),v2.ii(n),re.ii(n),d.resize(n);
    for(int i1=0;i1<=1;++i1)for(int i2=0;i2<=1;++i2)for(int i3=0;i3<=1;++i3)for(int i4=0;i4<=1;++i4){
        VL&h1=v1.a[i1][i2],&h2=v2.a[i3][i4];
        int b1=h1[1]!=0,b2=h2[1]!=0;
        if(i1==i2&&i3==i4)re.a[i1][i3][2]+=b1*b2,re.a[1][1][1]+=b1*b2;
        if(i1==i2){if(b1)for(int i=2;i<n;++i){if(h2[i])re.a[i1][i4][i+1]+=(i3+1)*h2[i],re.a[1][i4][i]+=h2[i];}}
        if(i3==i4){if(b2)for(int i=2;i<n;++i){if(h1[i])re.a[i1][i4][i+1]+=(i2+1)*h1[i],re.a[i1][1][i]+=h1[i];}}
    }
    for(int i=0;i<=1;++i)for(int j=0;j<=1;++j){VL&v=v1.a[i][j];v[1]=0;ntt(v,n);}
    for(int i=0;i<=1;++i)for(int j=0;j<=1;++j){VL&v=v2.a[i][j];v[1]=0;ntt(v,n);}
    for(int i1=0;i1<=1;++i1)for(int i2=0;i2<=1;++i2)for(int i3=0;i3<=1;++i3)for(int i4=0;i4<=1;++i4)
        NTT(v1.a[i1][i2],v2.a[i3][i4],re.a[i1][i4],(i2+1)*(i3+1));
    return re;
}
int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);if(!chk())return puts("0"),0;
    N=1;while(N<=m)N*=2;
    w[0][0]=w[1][0]=1,w[0][1]=por(3,(mod-1)/N),w[1][1]=por(w[0][1]);for(int i=2;i<N;++i)w[0][i]=w[0][i-1]*w[0][1]%mod,w[1][i]=w[1][i-1]*w[1][1]%mod;
    VV re=sol(1,m);
    ll ans=0;
    for(int i1=0;i1<=1;++i1)for(int i2=0;i2<=1;++i2){
        VL&v=re.a[i1][i2];
        ll jc=(m&1)?-1:1;
        for(int i=1;i<=m;++i){
            jc*=-i,jc%=mod;
            if(i==1)ans+=v[i]*(i1+1)*jc%mod;else ans+=v[i]*(i1+1)*(i2+1)*jc%mod;
        }
        ans%=mod;
    }
    printf("%lld\n",(ans%mod+mod)%mod);
    return 0;
}