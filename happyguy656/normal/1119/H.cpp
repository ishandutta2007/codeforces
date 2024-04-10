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

const int mod=998244353,mxn=1<<17;
ll por(ll x,ll y=mod-2){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%mod;x=x*x%mod;}return r;}
int n,m,nn,tp[mxn][3],a[8][mxn],b[8],xs[3];ll d[mxn];
void fwt(int f[],int n=::n){
    for(int d=1;d<n;d*=2){
        for(int i=0;i<n;i+=d*2)for(int j=0;j<d;++j)f[i+j]+=f[i+j+d],f[i+j+d]=f[i+j]-2*f[i+j+d];
    }
}
void ifwt(int f[],int n=::n){
    for(int d=1;d<n;d*=2){
        for(int i=0;i<n;i+=d*2)for(int j=0;j<d;++j)f[i+j]+=f[i+j+d],f[i+j+d]=f[i+j]-2*f[i+j+d];
        for(int i=0;i<n;++i)f[i]>>=1;
    }
}
void lfwt(ll f[],int n=::n){
    for(int d=1;d<n;d*=2){
        for(int i=0;i<n;i+=d*2)for(int j=0;j<d;++j)f[i+j]+=f[i+j+d],f[i+j+d]=f[i+j]-2*f[i+j+d];
        for(int i=0;i<n;++i)f[i]=(mod+1)/2*f[i]%mod;
    }
}

int main(){
    cin>>nn>>m>>xs[0]>>xs[1]>>xs[2];n=1<<m;for(int i=1;i<=nn;++i)for(int j=0;j<3;++j)scanf("%d",&tp[i][j]);
    for(int z=0;z<8;++z){
        for(int i=1;i<=nn;++i){int x=0;for(int j=0;j<3;++j)if(z>>j&1)x^=tp[i][j];++a[z][x];}
        fwt(a[z]);
    }
    int H=0;
    for(int i=0;i<n;++i){
        for(int z=0;z<8;++z)b[z]=a[z][i];
        ifwt(b,8);d[i]=1;
        for(int z=0;z<8;++z){ll c=0;for(int j=0;j<3;++j)if(z>>j&1)c-=xs[j];else c+=xs[j];d[i]=d[i]*por(c,b[z])%mod;}
    }
    lfwt(d);
    for(int i=0;i<n;++i)printf("%lld ",(d[i]+mod)%mod);puts("");
    return 0;
}