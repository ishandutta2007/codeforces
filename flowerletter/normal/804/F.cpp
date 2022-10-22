#pragma GCC optimze(3)
#include <bits/stdc++.h>
const int MAXN = 10010;
const int MAXL = 2000010;
const int Mod = 1000000007;
using namespace std;
int n,a,b,c;
char str[MAXL];
vector<int> G[MAXN];
vector<int> per[MAXN];
int siz[MAXN],dfn[MAXN],low[MAXN],dcnt,blo[MAXN],bgcd[MAXN],blocnt;
int stk[MAXN],t,num[MAXN],mx[MAXN],mn[MAXN],fact[MAXN],inv[MAXN];
bool instk[MAXN];
int PowMod(int x,int y){
    int ret=1;
    while(y){
        if(y&1) ret=1LL*ret*x%Mod;
        x=1LL*x*x%Mod,y>>=1;
    }return ret;
}
inline int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
inline void InPut(){
    scanf("%d %d %d",&n,&a,&b);
    for(int i=1;i<=n;i++){
        scanf("%s",str+1);
        for(int j=1;j<=n;j++)
            if(str[j]=='1') G[i].push_back(j);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&siz[i]);
        per[i].resize(siz[i]+1);
        scanf("%s",str);
        for(int j=0;j<siz[i];j++)
            if(str[j]=='1') per[i][j]=1;
            else if(str[j]=='0') per[i][j]=0;
    }
}
inline void Tarjan(int u,int fa){
    dfn[u]=low[u]=++dcnt,instk[u]=true,stk[t++]=u;
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(dfn[v]==0){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }else if(instk[v]==true) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        int fro=0;blocnt++;
        do{
            fro=stk[--t];instk[fro]=false;
            blo[fro]=blocnt;
            bgcd[blocnt]=gcd(bgcd[blocnt],siz[fro]);
        }while(fro!=u);
    }
}
inline void Part1(){
    for(int i=1;i<=n;i++)
        if(dfn[i]==0) Tarjan(i,-1);
    for(int i=1;i<=blocnt;i++)
        per[i+n].resize(bgcd[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=0;j<siz[i];j++)
            per[blo[i]+n][j%bgcd[blo[i]]]|=per[i][j];
    for(int i=blocnt;i>1;i--){
        int now=gcd(bgcd[i],bgcd[i-1]);
        for(int j=0;j<bgcd[i];j++)
            if(per[i+n][j]) per[i-1+n][j%now]|=1,num[i]++;
    }
    for(int j=0;j<bgcd[1];j++) num[1]+=per[1+n][j];
    for(int i=1;i<=n;i++){
        mx[i]=mn[i]=0;
        mx[i]=1LL*num[blo[i]]*siz[i]/bgcd[blo[i]];
        for(int j=0;j<siz[i];j++) mn[i]+=per[i][j];
    }
}
inline void Prepare(){
    fact[0]=1;
    for(int i=1;i<MAXN;i++) fact[i]=1LL*fact[i-1]*i%Mod;
    inv[MAXN-1]=PowMod(fact[MAXN-1],Mod-2);
    for(int i=MAXN-2;i>=0;i--) inv[i]=1LL*inv[i+1]*(1LL*i+1LL)%Mod;
}
inline int C(int x,int y){
    return 1LL*fact[x]*inv[y]%Mod*inv[x-y]%Mod;
}
inline int Part2(){
    Prepare();
    int cnt1=0,cnt2=0,ret=0;
    for(int i=1;i<=n;i++){
        cnt1=cnt2=0;
        for(int j=1;j<=n;j++){
            if(i!=j && mn[j]>mx[i]) cnt1++;
            if(i!=j && mn[j]<=mx[i] && (mx[j]>mx[i] || (mx[j]==mx[i] && j<i))) cnt2++;
        }
        if(cnt1>a-1) continue;
        for(int j=min(b,min(a-1-cnt1,cnt2));j>=0 && j+1+cnt1>=b;j--)
            ret=(1LL*ret+1LL*C(cnt2,j)*C(cnt1,b-j-1)%Mod)%Mod;
    }
    return ret;
}
int main(){
    InPut();
    Part1();
    printf("%d\n",Part2());
    return 0;
}