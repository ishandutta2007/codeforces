#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define uu unsigned
#define scanf(x...) assert(~scanf(x))
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cerr<<(k>>20)<<endl;}

const int mxn=2e5+3;
int n,a[mxn],b[mxn],cc[mxn],dg[mxn],nx[mxn],wz[mxn],to[mxn],X;
VI g[mxn];
void gad(int x,int y){x=a[x],y=a[y];if(x==X||y==X)return;g[x].push_back(y),++dg[y];}
bool slv(){
    cin>>n;static int vs[mxn];for(int i=1;i<=n;++i)vs[i]=cc[i]=dg[i]=wz[i]=0,g[i].clear();
    for(int i=1;i<=n;++i)scanf("%d",a+i),++cc[a[i]];for(int i=1;i<=n;++i)scanf("%d",b+i),nx[i]=wz[b[i]],wz[b[i]]=i;
    for(int i=1;i<=n;++i)to[i]=wz[a[i]],wz[a[i]]=nx[wz[a[i]]];
    X=0;for(int i=1;i<=n;++i)if(cc[i]>cc[X])X=i;
    for(int i=1,e=0;i<=n;++i)if(!vs[i]&&a[i]==X){
        for(int x=i;!vs[x];x=to[x])vs[x]=1;
        if(e)swap(to[e],to[i]);e=i;
    }
    for(int i=1;i<=n;++i)if(!vs[i])return 0;
    for(int i=1;vs[i]==1;i=to[i])vs[i]=2;
    for(int i=1;i<=n;++i)assert(vs[i]==2),gad(i,to[i]);
    static int qu[mxn];int qh=1,qt=0;for(int i=1;i<=n;++i)if(!dg[i])qu[++qt]=i;
    while(qh<=qt){int x=qu[qh++];for(int y:g[x])if(--dg[y]==0)qu[++qt]=y;}
    return qt==n;
}
int main(){
    int ca;cin>>ca;while(ca--)puts(slv()?"AC":"WA");
    return 0;
}