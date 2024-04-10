#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define Forg(i,x) for(register int i=Fir[x];i;i=Nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

int n,tt,S,T;
const int mxn=605,mxm=mxn*mxn;

int to[mxm],nxt[mxm],fir[mxn],ed[mxm],gn=1;
inline void gadd(int x,int y,int z=2e9){
    to[++gn]=y,nxt[gn]=fir[x],fir[x]=gn,ed[gn]=z;
    to[++gn]=x,nxt[gn]=fir[y],fir[y]=gn,ed[gn]=0;
}
int q[mxn],dep[mxn],cur[mxn];
inline bool bfs(){
    memset(dep,0,sizeof(dep));
    int qh=1,qt=1;dep[S]=1,q[1]=S,cur[S]=fir[S];
    while(qh<=qt){
        int x=q[qh++];
        forg(i,x)if(ed[i]&&!dep[to[i]]){
            dep[to[i]]=dep[x]+1,q[++qt]=to[i],cur[to[i]]=fir[to[i]];
            if(to[i]==T)return 1;
        }
    }
    return 0;
}
inline int dfs(int x,int fl){
    if(x==T)return fl;
    int re=fl;
    for(int i=cur[x];i&&re;cur[x]=i,i=nxt[i])if(dep[to[i]]==dep[x]+1&&ed[i]){
        int k=dfs(to[i],min(re,ed[i]));
        if(!k)dep[to[i]]=0;
        ed[i]-=k,ed[i^1]+=k,re-=k;
    }
    return fl-re;
}
vector<int>ele[303];
int rep[303],bel[303];
int main(){
    scanf("%d",&n);
    tt=2*n+2;
    for(int i=1;i<=n;++i){
        int t;scanf("%d",&t);
        gadd(tt-1,i,1),gadd(i+n,tt,1);
        while(t--){int x;scanf("%d",&x);ele[i].push_back(x);gadd(i,x+n,1);}
    }
    S=tt-1,T=tt;
    while(bfs())dfs(S,2e9);
    for(int i=1;i<=n;++i)forg(j,i)if(to[j]>n&&to[j]<S&&ed[j]==0){
        rep[i]=to[j]-n,bel[to[j]-n]=i;
    }
    for(int i=1;i<=n;++i)assert(rep[i]);
    for(int i=1;i<=n;++i)assert(bel[i]);
    memset(fir,0,sizeof(fir));gn=1;
    int sum=0;
    for(int i=1;i<=n;++i){
        int ww;scanf("%d",&ww);ww*=-1;
        if(ww>0)gadd(n+1,i,ww),sum+=ww;else gadd(i,n+2,-ww);
        
        for(int jj=0;jj<ele[i].size();++jj){
            int x=ele[i][jj];
            if(x==rep[i])continue;
            gadd(i,bel[x]);
        }
    }
    S=n+1,T=n+2;
    while(bfs())sum-=dfs(S,2e9);
    printf("%d\n",-sum);
    return 0;
}