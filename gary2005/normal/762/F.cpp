/**
 *    author:  gary
 *    created: 28.10.2021 16:54:39
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
bool isprime(int x){
    rb(i,2,x-1) if(x%i==0) return 0;
    return 1;
}
vector<int> prime;
int n,m;
vector<int> trees[1000];
vector<int> treet[12];
vector<int> g[12];
bool sam[12];
int val[12];
int siz[12];
const int MOD=1e9+7;
void gethash(int now,int pre=-1){
    siz[now]=1;
    val[now]=1;
    for(auto it:treet[now]) if(it!=pre) gethash(it,now),(val[now]+=1ll*val[it]*prime[siz[it]]%MOD)%=MOD,siz[now]+=siz[it];
}
void build(int now,int pre=-1){
    for(auto it:treet[now]) if(it!=pre){
        g[now].PB(it);
        build(it,now);
    }
}
int root;
int dp[1000][12];
bool cmp(int A,int B){
    return II(val[A],siz[A])<II(val[B],siz[B]);
}
int cnt,Now,Noj;
vector<int> q[12];
int pt[12];
vector<int> tmpg;
vector<int> v;
void bs(int have,int targ){
    if(have==targ){
        vector<vector<int> > smalldp;
        smalldp.resize(tmpg.size());
        rep(i,smalldp.size()) smalldp[i]=vector<int>(v.size()+1,0);
        rep(i,smalldp.size()){
            smalldp[i][1]=dp[tmpg[i]][v[0]];
            if(i)
            rb(j,1,v.size()){
                (smalldp[i][j]+=smalldp[i-1][j])%=MOD;
                if(j!=1)
                (smalldp[i][j]+=1ll*smalldp[i-1][j-1]*dp[tmpg[i]][v[j-1]]%MOD)%=MOD;
            }
        }
        (dp[Now][Noj]+=smalldp.back()[v.size()])%=MOD;
        return ;
    }
    rb(i,0,cnt) if(pt[i]!=q[i].size()){
        v.PB(q[i][pt[i]]);
        pt[i]++;
        bs(have+1,targ);
        v.POB();
        pt[i]--;
    }
}
void dfs(int now,int pre){
    for(auto it:trees[now]) if(it!=pre) dfs(it,now);
    tmpg.clear();
    for(auto it:trees[now]) if(it!=pre) tmpg.PB(it);
    rep(i,m){
        if(sam[i]&&now<root) continue;
        if(g[i].empty()){
            dp[now][i]=1;
        }
        else{
            if(g[i].size()>tmpg.size()) continue;
            cnt=-1;
            Now=now;
            Noj=i;
            for(auto it:g[i]){
                if(cnt==-1||II(val[q[cnt].back()],siz[q[cnt].back()])!=II(val[it],siz[it])){
                    ++cnt;
                    q[cnt].clear();
                    q[cnt].PB(it);
                }
                else{
                    q[cnt].PB(it);
                }
            }
            rb(i,0,cnt) pt[i]=0;
            bs(0,g[i].size());
        }
    }
}
int solve(){
    memset(dp,0,sizeof(dp));
    dfs(root,-1);
    return dp[root][0];
}
int main(){
    prime.PB(1);
    rb(i,2,100) if(isprime(i)) prime.PB(i);
    scanf("%d",&n);
    rb(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        --u,--v;
        trees[u].PB(v);
        trees[v].PB(u);
    }
    scanf("%d",&m);
    rb(i,1,m-1){
        int u,v;
        scanf("%d%d",&u,&v);
        --u,--v;
        treet[u].PB(v);
        treet[v].PB(u);
    }
    gethash(0);
    auto root_val=II(val[0],siz[0]);
    rep(i,m) if(i) {
        gethash(i);
        if(root_val==II(val[i],siz[i])) sam[i]=1;
    }
    gethash(0);
    build(0);
    rep(i,m) sort(ALL(g[i]),cmp);
    int ans=0;
    rep(i,n){
        root=i;
        (ans+=solve())%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}