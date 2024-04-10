/**
 *    author:  gary
 *    created: 31.05.2022 23:35:17
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e5+10;
const int MOD=1e9+7;
int n,k;
int fact[MAXN+1],ifact[MAXN+1];
int quick(int k1,int k2){
    int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%MOD)if(k2&1)k3=1LL*k3*k1%MOD;return k3;
}
int inv(int A){return quick(A,MOD-2);}
void genmath(){
    fact[0]=1;
    rb(i,1,MAXN) fact[i]=1ll*fact[i-1]*i%MOD;
    ifact[MAXN]=inv(fact[MAXN]);
    // cout<<fact[MAXN]<<endl;
    rl(i,MAXN-1,0) ifact[i]=1ll*ifact[i+1]*(i+1)%MOD;
}
int comb(int A,int B){
    if(A<0||B<0) return 0;
    if(A<B) return 0;
    return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
}
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
void sub(int &A,int B){
    A+=MOD-B;
    if(A>=MOD) A-=MOD;
}
int siz[MAXN],F[MAXN],fa[MAXN];
vector<int> g[MAXN];
void dfs1(int now,int pre){
    siz[now]=1;
    fa[now]=pre;
    for(auto it:g[now]) if(it!=pre) dfs1(it,now),siz[now]+=siz[it];
}
int ans=0;
void dfs2(int now,int pre,int sum){
    g[now].PB(now);
    for(auto i:g[now]) sub(sum,F[i]),F[i]=1ll*(siz[i]-siz[fa[i]]+MOD)*comb(siz[i],k)%MOD,add(sum,F[i]);
    g[now].pop_back();
    add(ans,sum);
    int sumcomb=0;
    for(auto i:g[now]) add(sumcomb,comb(siz[i],k));
    for(auto nex:g[now]) if(nex!=pre){
        int siznex=siz[nex];
        int thisF=F[now];
        sub(sumcomb,comb(siznex,k));
        int nexsum=sum;
        siz[now]-=siz[nex];
        add(nexsum,1ll*sumcomb*siz[nex]%MOD);
        siz[nex]=n;
        fa[now]=nex;
        fa[nex]=0;
        dfs2(nex,now,nexsum);
        F[now]=thisF;
        siz[now]=n;
        add(sumcomb,comb(siznex,k));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    genmath();
    cin>>n>>k;
    rb(i,1,n-1){
        int u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs1(1,0);
    rb(i,1,n) F[i]=1ll*(siz[i]-siz[fa[i]]+MOD)*comb(siz[i],k)%MOD;
    int sum=0;
    rb(i,1,n) add(sum,F[i]);
    dfs2(1,0,sum);
    cout<<ans<<endl;
    return 0;
}