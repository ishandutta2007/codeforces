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

const int mxn=63*63*63;
int n,m,M,co[mxn],dg[mxn],px[mxn],ed[65][65];bool O;
bool fw[mxn];
bool cmp1(int x,int y){return dg[x]<dg[y];}
int HH(int c){if(c<=0)return 3;return c;}
struct str{
    int n,a[100][2],v;
    void gz(int x,int y,int z){
        n=v=0;
        if(~co[x])v-=co[x];else a[++n][0]=x,a[n][1]=1;
        if(~co[y])v-=co[y];else a[++n][0]=y,a[n][1]=1;
        if(~co[z])v-=co[z];else a[++n][0]=z,a[n][1]=1;
        v=(v+300)%3;
        for(int i=1;i<=n;++i)++dg[a[i][0]];
    }
    int fi(int x){for(int i=1;i<=n;++i)if(a[i][0]==x)return a[i][1];return 0;}
    void zl(){
        assert(n<100);
        static int ee[mxn][2],vs[mxn];int nn=0;
        for(int i=1,x;i<=n;++i)if(!vs[x=a[i][0]])vs[x]=++nn,ee[nn][0]=x,ee[nn][1]=a[i][1];else ee[vs[x]][1]+=a[i][1];
        n=0;for(int i=1;i<=nn;++i)if(ee[i][1]%3)a[++n][0]=ee[i][0],a[n][1]=ee[i][1]%3;
        for(int i=1;i<=nn;++i)vs[ee[i][0]]=0;
        v%=3;
    }
    void operator+=(const str&b){
        v+=b.v;for(int i=1;i<=b.n;++i)a[++n][0]=b.a[i][0],a[n][1]=b.a[i][1];
        zl();
    }
    void tian(){
        for(int i=1;i<=n;++i)assert(a[i][0]&&a[i][1]);
        for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)assert(a[i][0]!=a[j][0]);
        int p=0;
        for(int i=1;i<=n;++i)if(~co[a[i][0]])v-=co[a[i][0]]*a[i][1];else p=i;
        v%=3;
        if(!p){O&=v==0;return;}
        for(int i=1;i<p;++i)if(co[a[i][0]]==-1)co[a[i][0]]=0;
        assert(co[a[p][0]]==-1);
        co[a[p][0]]=(v+3)*a[p][1]%3;
    }
}b[63*63*63];
void SOL(){
    memset(ed,0,sizeof(ed));O=1;memset(dg,0,sizeof(dg));memset(fw,0,sizeof(fw));
    cin>>n>>m;for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),ed[x][y]=ed[y][x]=i,co[i]=z;
    M=m,m=0;
    for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)for(int k=j+1;k<=n;++k)if(ed[i][j]&&ed[i][k]&&ed[j][k])b[++m].gz(ed[i][j],ed[i][k],ed[j][k]);
    for(int i=1;i<=M;++i)px[i]=i;sort(px+1,px+M+1,cmp1);
    VI vec;assert(vec.empty());
    for(int T=1;T<=M;++T){
        int x=px[T];//if(!dg[x]){if(co[x]==-1)co[x]=0;continue;}
        int p=0;for(int i=1;i<=m;++i)if(!fw[i]&&b[i].fi(x)&&(!p||b[i].n<b[p].n))p=i;
        if(!p)continue;vec.push_back(p),fw[p]=1;
        for(int i=1;i<=m;++i)if(!fw[i]){
            while(b[i].fi(x))b[i]+=b[p];
        }
    }
    reverse(vec.begin(),vec.end());
    for(int i=1;i<=m;++i)if(!fw[i])b[i].tian();
    if(!O)return puts("-1"),void();
    for(int k:vec)b[k].tian();
    for(int i=1;i<=M;++i)printf("%d ",HH(co[i]));puts("");
}

int main(){
    int ca;cin>>ca;while(ca--)SOL();
    return 0;
}