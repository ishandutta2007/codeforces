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

const int mxn=1e5+3;
int n,to[mxn*2],nxt[mxn*2],fir[mxn],gn=1;void gadd(int x,int y){to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn,to[++gn]=x,nxt[gn]=fir[y],fir[y]=gn;}
int dp[mxn],tn,xl[mxn],RR,lx[mxn],nt,z1[mxn],z2[mxn],nm[mxn],rt;
int cp[mxn],fa[mxn],vs[mxn];
bool cmp1(int x,int y){return dp[x]>dp[y];}
vector<int>cz[mxn];
void dfs0(int x,int f=0){
    fa[x]=f;
    forg(i,x)if(to[i]!=f)dfs0(to[i],x);
    tn=0;forg(i,x)if(to[i]!=f)xl[tn++]=dp[to[i]];sort(xl,xl+tn,greater<int>());
    dp[x]=1;for(int i=0;i<tn;++i)dp[x]=max(dp[x],xl[i]+i);
}
void dfs1(int x,int f=0,int v=-1){
    tn=0;forg(i,x)xl[tn++]=to[i]==f?v:dp[to[i]];sort(xl,xl+tn,greater<int>());
    nt=0;forg(i,x)if(to[i]!=f)lx[nt++]=to[i];sort(lx,lx+nt,cmp1);
    if(tn<=1)RR=max(RR,xl[0]);else{
        for(int i=0,mx=-1e9;i<tn;++i)RR=max(RR,mx+xl[i]+i-1),mx=max(mx,xl[i]);
    }
    for(int i=0,mx=0;i<tn;++i)mx=max(mx,xl[i]+i),z1[i]=mx;
    for(int i=tn-1,mx=0;i;--i)mx=max(mx,xl[i]+i-1),z2[i]=mx;
    z2[tn]=z2[tn+1]=0;
    int pp=0;
    for(int i=0;i<tn;++i){
        int z=z2[i+1];if(i>1)z=max(z,z1[i-1]);if(!z)z=1;
        for(;pp<nt&&dp[lx[pp]]==xl[i];++pp)nm[lx[pp]]=z;
    }
    assert(pp==nt);
    forg(i,x)if(to[i]!=f)dfs1(to[i],x,nm[to[i]]);
}
int aak(int x){if(vs[x])return vs[x];printf("? %d\n",x);fflush(stdout);scanf("%d",vs+x);return vs[x];}
void dfs2(int x,int f=0){
    forg(i,x)if(to[i]!=f)dfs2(to[i],x),cz[x].push_back(to[i]);
    sort(cz[x].begin(),cz[x].end(),cmp1);int ss=cz[x].size();
    for(int i=0;i<ss;++i)cz[x][i]=cp[cz[x][i]];
    cp[x]=ss?cz[x][0]:x;
}
int dfs3(int x){
    for(int i:cz[x]){int t=aak(i);if(t!=x)return dfs3(t);}
    return x;
}
int main(){
    scanf("%d",&n);for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),gadd(x,y);
    if(n>1)dfs0(1),dfs1(1);printf("%d\n",RR);fflush(stdout);
    scanf("%d",&rt);dfs0(rt),dfs2(rt);
    int r1=0,r2=0;
    for(int i:cz[rt]){int t=aak(i);if(t!=rt){if(!r1)r1=dfs3(t);else if(!r2)r2=dfs3(t);} if(r2)break;}
    printf("! %d %d\n",r1?r1:rt,r2?r2:rt);
    return 0;
}