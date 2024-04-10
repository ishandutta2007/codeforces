#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf(x...) assert(scanf(x))
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cerr<<(k>>20)<<endl;}

const int mxn=3e5+3;
VI g[mxn],gg[mxn],ve;int n,m,b[mxn],d[mxn],N;bool vs[mxn];
map<int,int>mp,xh;

ll cal(int x,int y){return 1ll*(b[x]+b[y])*(d[x]+d[y]);}

ll slv(){
    for(int i=1;i<=N;++i)gg[i].clear(),g[i].clear();ve.clear();
    mp.clear();xh.clear();scanf("%d%d",&n,&m);N=n;for(int i=1;i<=n;++i)scanf("%d",b+i),++mp[b[i]];
    sort(b+1,b+n+1),n=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;++i)d[i]=mp[b[i]],xh[b[i]]=i;
    for(int i=n;i;--i)gg[d[i]].push_back(i);
    for(int i=1;i<=n;++i)if(!vs[d[i]])ve.push_back(d[i]),vs[d[i]]=1;
    for(int i=1;i<=N;++i)vs[i]=0;
    while(m--){int x,y;scanf("%d%d",&x,&y),x=xh[x],y=xh[y],g[x].push_back(y),g[y].push_back(x);}
    ll re=0;for(int i=1;i<=n;++i){
        for(int y:g[i])vs[y]=1;
        for(int j:ve){
            for(int k:gg[j])if(!vs[k]&&k!=i){re=max(re,cal(i,k));break;}
        }
        for(int y:g[i])vs[y]=0;
    }
    return re;
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%lld\n",slv());
    return 0;
}