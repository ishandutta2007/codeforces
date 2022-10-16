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

const int mxn=1003;
int n,m,vv,cc=1,d[mxn],nn;
struct usssss{
    int f[mxn],sz[mxn];void ii(){for(int i=1;i<=n;++i)f[i]=i,sz[i]=1;}int fi(int x){while(x!=f[x])x=f[x]=f[f[x]];return x;}
    void mer(int x,int y){x=fi(x),y=fi(y);if(x==y)++cc;else f[x]=y,sz[y]+=sz[x];}
}u;
int main(){
    cin>>n>>m;u.ii();vv=1;for(int t=1;t<=m;++t){
        int x,y;scanf("%d%d",&x,&y);u.mer(x,y);
        nn=0;for(int i=1;i<=n;++i)if(u.f[i]==i)d[++nn]=u.sz[i];
        nth_element(d+1,d+cc,d+nn+1,greater<int>());
        ll ans=0;for(int i=1;i<=cc;++i)ans+=d[i];cout<<ans-1<<endl;
    }
    return 0;
}