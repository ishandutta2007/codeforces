#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1503,B=13331,mod=1e9+9;
int n,m,a[mxn][mxn],b[mxn][mxn],rk[mxn];
ll ha1[mxn],ha2[mxn];
vector<int>hx[mxn],xh[mxn];int cc[mxn];
int cz[mxn],qh,qt,vs[mxn];
void del(int x){if(vs[x])return;vs[x]=1;for(int i:hx[x])if(--cc[i]==0)cz[++qt]=i;}

int main(){
    scanf("%d%d",&n,&m);for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&b[i][j]);
    for(int i=1;i<=n;++i){
        ll h=0;for(int j=1;j<=m;++j)h=(h*B+a[i][j])%mod;ha1[i]=h;
    }
    for(int i=1;i<=n;++i){
        ll h=0;for(int j=1;j<=m;++j)h=(h*B+b[i][j])%mod;ha2[i]=h;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)if(ha2[i]==ha1[j]){rk[i]=j;ha1[j]=-1;goto tb;}
        return puts("-1"),0;
        tb:;
    }
    for(int j=1;j<=m;++j){
        for(int i=1;i<=n;++i){
            hx[i].push_back(j),xh[j].push_back(i);++cc[j];
            while(i!=n&&b[i][j]<=b[i+1][j]){
                if(b[i][j]<b[i+1][j])xh[j].push_back(i+1);
                ++i;
            }
        }
    }
    qh=1,qt=0;del(1);
    while(qh<=qt){
        int x=cz[qh++];
        for(int i:xh[x])del(i);
    }
    for(int l=1,r;l<=n;l=r+1){
        r=l;while(r<n&&!vs[r+1])++r;
        for(int i=l;i<r;++i)if(rk[i]>rk[i+1])return puts("-1"),0;
    }
    printf("%d\n",qt);for(int i=qt;i;--i)printf("%d\n",cz[i]);
    return 0;
}