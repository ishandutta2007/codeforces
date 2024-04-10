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
//mt19937 rnd(time(0));
//int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=2e5+3,mxm=1e6+3;

int n,m,to[mxm],nxt[mxm],fir[mxm],ed[mxm],gn=1,co[mxn];
bool vs[mxn],O;
void gad(int x,int y,int v){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn,ed[gn]=v;}
vector<pii>g[mxn];

void dfs(int x){
    if(vs[x])return;vs[x]=1;forg(i,x){
        int y=to[i];if(!vs[y])co[y]=co[x]^ed[i],dfs(y);else O&=(co[x]^co[y])==ed[i];
    }
}
void dfs1(int x,int f=0){
    for(pii k:g[x]){
        int y=k.first,z=k.second;if(y==f)continue;
        if(z!=-1)printf("%d %d %d\n",x,y,z);else printf("%d %d %d\n",x,y,co[x]^co[y]);
        dfs1(y,x);
    }
}
void slv(){
    cin>>n>>m;for(int i=1;i<=n;++i)fir[i]=0;gn=1;
    for(int i=1;i<=n;++i)g[i].clear();for(int i=1,x,y,z;i<n;++i){
        scanf("%d%d%d",&x,&y,&z),g[x].emplace_back(y,z),g[y].emplace_back(x,z);if(~z)z=__builtin_parity(z),gad(x,y,z),gad(y,x,z);
    }
    while(m--){int x,y,z;scanf("%d%d%d",&x,&y,&z),gad(x,y,z),gad(y,x,z);}
    for(int i=1;i<=n;++i)vs[i]=0;O=1;
    for(int i=1;i<=n;++i)if(!vs[i])dfs(i);
    if(!O)return puts("no"),void();
    puts("yes");
    dfs1(1);
}

int main(){
    int ca;cin>>ca;while(ca--)slv();
    return 0;
}