#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=3e5+3;
VI gg[mxn],g[mxn];int n,m,qn,vs[mxn],fa[mxn],as[mxn][2],z[mxn],cnt;
int ans[mxn],an,a2[mxn],na;
void dfs(int x,int f){
    fa[x]=f;vs[x]=1;
    for(int y:gg[x])if(y!=f&&!vs[y])dfs(y,x),g[x].push_back(y);
}
int main(){
    cin>>n>>m;for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),gg[x].push_back(y),gg[y].push_back(x);
    dfs(1,0);
    cin>>qn;for(int i=1,x,y;i<=qn;++i)scanf("%d%d",&x,&y),as[i][0]=x,as[i][1]=y,z[x]^=1,z[y]^=1;
    for(int i=1;i<=n;++i)cnt+=z[i];
    if(!cnt){
        puts("YES");
        for(int i=1;i<=qn;++i){
            int x=as[i][0],y=as[i][1];
            for(int j=0;j<=n;++j)vs[j]=0;
            for(;y;y=fa[y])vs[y]=1;
            an=0;
            for(;x&&!vs[x];x=fa[x])ans[++an]=x;
            na=0;y=as[i][1];
            for(y=as[i][1];y!=x;y=fa[y])a2[++na]=y;
            printf("%d\n",an+na+1);
            for(int j=1;j<=an;++j)printf("%d ",ans[j]);printf("%d ",x);for(int j=na;j;--j)printf("%d ",a2[j]);
            puts("");
        }
    }else{
        puts("NO");printf("%d\n",cnt/2);
    }
    return 0;
}