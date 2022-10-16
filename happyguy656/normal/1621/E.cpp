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

const int mxn=2e5+5;
int n,m,le[mxn],pp[mxn],a[mxn],b[mxn],dy[mxn],cc[mxn],nx[mxn],vs[mxn];
ll s0[mxn];
bool jg[mxn];
int gp(ll x,ll k){
    int l=1,r=n+1,md;while(l!=r){
        md=(l+r)>>1;if(a[md]*k>=x)r=md;else l=md+1;
    }
    return l;
}
struct usssss{int f[mxn];void init(){for(int i=1;i<=n+2;++i)f[i]=i;}int fi(int x){while(x!=f[x])x=f[x]=f[f[x]];return x;}void mer(int x){f[fi(x)]=fi(x+1);}}us;
void wj(int k=0){if(!k){for(int i=1;i<pp[m+1];++i)putchar('0');puts("");return;}for(int i=pp[k];i<pp[k+1];++i)jg[i]=0;}
void sc(){for(int i=1;i<pp[m+1];++i)putchar('0'+jg[i]);puts("");}
void slv(){
    scanf("%d%d",&n,&m);for(int i=1;i<=n;++i)scanf("%d",a+i);sort(a+1,a+n+1);
    for(int i=1,p=1;i<=m;++i){fflush(stdout);pp[i]=p;int c;scanf("%d",&c);while(c--){int x;scanf("%d",&x);b[p++]=x;}pp[i+1]=p;}
    for(int i=1;i<=m;++i){s0[i]=0;for(int j=pp[i];j<pp[i+1];++j)s0[i]+=b[j];dy[i]=gp(s0[i],pp[i+1]-pp[i]);}
    us.init();
    for(int i=1;i<=n+2;++i)cc[i]=vs[i]=0;
    for(int i=1;i<pp[m+1];++i)jg[i]=0;
    for(int i=1;i<=m;++i){int x=dy[i];--cc[x];int y=us.fi(x);if(y>n+1)return sc();++cc[y],vs[y]=1,us.mer(y);}
    for(int i=n;i;--i)cc[i]+=cc[i+1];
    for(int i=n+2;i;--i)nx[i]=!cc[i]?i:nx[i+1];
    for(int i=1;i<=m;++i){
        int x=dy[i];x=nx[x+1]-1;
        if(vs[n+1]&&x!=n+1)continue;
        for(int t=pp[i];t<pp[i+1];++t){
            int p=gp(s0[i]-b[t],pp[i+1]-pp[i]-1);
            int e=us.fi(p);if(x>=p)e=min(e,x);
            jg[t]=e<=n;
        }
    }
    sc();
}

int main(){
    int ca;cin>>ca;while(ca--)slv();
    return 0;
}