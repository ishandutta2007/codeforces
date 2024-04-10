#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef pair<int,int>pii;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;typedef vector<pii>VP;
typedef multiset<ll>MS;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2.5e5+3;
int n,dg[mxn],fa[mxn],T,px[mxn],w[mxn],vs[mxn];VP g[mxn];
void gad(int x,int y,int z){g[x].push_back(pii(y,z)),g[y].push_back(pii(x,z)),++dg[x],++dg[y];}
bool cmp1(pii x,pii y){return dg[x.first]>dg[y.first];}bool cmp2(int x,int y){return dg[x]>dg[y];}
void dfs0(int x,int f){
    fa[x]=f;for(pii k:g[x]){int y=k.first;if(y!=f)dfs0(y,x),w[y]=k.second;}
}
ll dp[mxn][2],d2[mxn][2];
MS s1[mxn],s2[mxn],s3[mxn],s4[mxn];
ll tk[3*mxn][2],tn;
ll top1(int x){return *--s1[x].end();}
ll top2(int x){return s2[x].size()?*s2[x].begin():0;}

void ins(int x,ll v){
    if(dg[x]<=T)return;
    if(v>0)v=0;
    if(T==1){ll t=top2(x);if(v<t)d2[x][1]+=v-t;s2[x].insert(v);return;}
    if(v>top1(x)){if(v<top2(x))d2[x][1]+=v-top2(x);s2[x].insert(v);}
    else{ll k=top1(x);d2[x][0]+=v-k,d2[x][1]+=v-top2(x),s1[x].erase(--s1[x].end()),s1[x].insert(v),s2[x].insert(k);}
}
void ins1(int x,ll v){
    if(v>0)v=0;
    if(T==1){ll t=top2(x);if(v<t)dp[x][1]+=v-t;s2[x].insert(v);tk[++tn][1]=v;return;}
    if(v>top1(x)){if(v<top2(x))dp[x][1]+=v-top2(x);s2[x].insert(v);tk[++tn][1]=v;}
    else{
        ll k=top1(x);dp[x][0]+=v-k,dp[x][1]+=v-top2(x),s1[x].erase(--s1[x].end()),s1[x].insert(v),s2[x].insert(k);
        tk[++tn][0]=2,tk[tn][1]=k;tk[++tn][0]=1,tk[tn][1]=v;tk[++tn][1]=k;
    }
}
void del(MS&s,ll v){s.erase(s.find(v));}
void dfs1(int x,int f=0){
    for(pii k:g[x]){int y=k.first;if(y!=f)dfs1(y,x);}
    dp[x][0]=d2[x][0],dp[x][1]=d2[x][1];for(pii k:g[x]){
        int y=k.first;if(y==f)continue;
        dp[x][1]+=dp[y][1]+w[y],dp[x][0]+=dp[y][1]+w[y],ins1(x,dp[y][0]-dp[y][1]-w[y]);
    }
    while(tn){int k=tk[tn][0];if(k==2)s1[x].insert(tk[tn][1]);else if(k)del(s1[x],tk[tn][1]);else del(s2[x],tk[tn][1]);tk[tn][0]=tk[tn][1]=0;--tn;}
}

int main(){
    scanf("%d",&n);for(int i=1,x,y,z;i<n;++i){scanf("%d%d%d",&x,&y,&z),gad(x,y,z);}
    for(int i=1;i<=n;++i)px[i]=i;sort(px+1,px+n+1,cmp2);
    for(int i=1;i<=n;++i)sort(g[i].begin(),g[i].end(),cmp1);
    dfs0(1,0);
    ll sm=0;for(int i=2;i<=n;++i)sm+=w[i];printf("%lld ",sm);
    int P=n;for(T=1;T<n;++T){
        for(int i=1;i<=P;++i){
            int x=px[i],s=s2[x].size();
            if(s){ll k=top2(x);d2[x][0]+=k;s1[x].insert(k),s2[x].erase(s2[x].begin());d2[x][1]+=top2(x);}
            else if(s1[x].size()<T-1)s1[x].insert(0);
            assert(s1[x].size()==T-1);
        }
        while(P&&dg[px[P]]<=T){int x=px[P];ins(fa[x],-w[x]);d2[fa[x]][0]+=w[x],d2[fa[x]][1]+=w[x];--P;}
        for(int i=1;i<=P;++i){int x=px[i];while(g[x].size()&&dg[(--g[x].end())->first]<=T)g[x].pop_back();}
        sm=0;
        for(int i=1;i<=P;++i){int x=px[i];if(dg[fa[x]]<=T)dfs1(x),sm+=min(dp[x][0],dp[x][1]+w[x]);}
        printf("%lld ",sm);
    }
    puts("");
    return 0;
}