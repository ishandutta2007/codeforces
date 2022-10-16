#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int abc;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
typedef pair<int,int>pii;
int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1003;
VI g[mxn];int n,v1[mxn],v2[mxn],m,fr[mxn],ee;ll vv[mxn],H;bool iq[mxn],qi[mxn];
bool cmp1(int x,int y){return v1[x]<v1[y];}
bool dfs(int x,int f,ll v){
    fr[x]=f,vv[x]=v;
    for(int y:g[x])if(y!=f){
        if(iq[y]){
            if(!iq[x]){for(int i=x;!iq[i];i=fr[i])++ee,H+=v2[i],iq[i]=1;return 1;}
        }else if(v>v1[y]){
            if(!fr[y]){if(dfs(y,x,v+v2[y]))return 1;}else{
                memcpy(qi+1,iq+1,n);
                for(int i=x;!iq[i];i=fr[i])++ee,iq[i]=1,H+=v2[i];
                for(int i=y;!qi[i];i=fr[i])if(!iq[i])++ee,iq[i]=1,H+=v2[i];
                return 1;
            }
        }//else return 0;
    }
    return 0;
}
bool chk(int v){
    memset(iq+1,0,n);iq[1]=1;
    H=v;ee=1;
    while(ee<n){
        memset(fr+1,0,sizeof(int)*n);for(int i=1;i<=n;++i)if(iq[i]&&dfs(i,0,H))goto tb;
        return 0;tb:;
    }
    return 1;
}

int main(){
    assert(sizeof(bool)==1);
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d%d",&n,&m);for(int i=1;i<=n;++i)g[i].clear();for(int i=2;i<=n;++i)scanf("%d",v1+i);for(int i=2;i<=n;++i)scanf("%d",v2+i);
        for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
        for(int i=1;i<=n;++i)sort(g[i].begin(),g[i].end(),cmp1);
        int l=1,r=1e9+3,md;while(l<r){int md=(l+r)>>1;if(chk(md))r=md;else l=md+1;}printf("%d\n",l);
    }
    return 0;
}