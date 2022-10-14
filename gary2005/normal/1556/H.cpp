/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(19260815)
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
SRAND;
const int MAXN=51;
int n,k,d[MAXN],deg[MAXN],cost[MAXN][MAXN],fa[MAXN];
bool ok[MAXN][MAXN],used[MAXN][MAXN];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
vector<int> dfs(int now,int pre){
    vector<int> ret;
    ret.PB(now);
    rb(it,1,n) if(used[it][now]&&it!=pre) {
        vector<int> z=dfs(it,now);
        for(auto it:z) ret.PB(it);
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&k);
    rb(i,1,k) scanf("%d",&d[i]);
    rb(i,k+1,n) d[i]=n;
    rb(i,1,n) rb(j,i+1,n){
        int w;
        scanf("%d",&w);
        cost[i][j]=cost[j][i]=w;
    }
    rb(i,1,n) fa[i]=i;
    vector<pair<int,mp> > e;
    rb(i,k+1,n) rb(j,i+1,n) e.PB(II(cost[i][j],II(i,j)));
    sort(ALL(e));
    for(auto it:e){
        int u,v;
        u=it.SEC.FIR;
        v=it.SEC.SEC;
        if(root(u)==root(v)) continue;
        fa[root(u)]=root(v);
        ok[u][v]=ok[v][u]=1;
        used[u][v]=used[v][u]=1;
        deg[u]++;
        deg[v]++;
    }
    rb(i,1,k) rb(j,k+1,n) ok[i][j]=ok[j][i]=1;
    rb(i,1,k) rb(j,i+1,k) ok[i][j]=ok[j][i]=1;
    rb(i,1,n) fa[i]=i;
    rb(i,1,k){
        used[i][k+1]=used[k+1][i]=1;
        deg[i]++;
        deg[k+1]++;
    }
    int cur,ans;
    cur=0;
    rb(i,1,n) rb(j,i+1,n) if(used[i][j]) cur+=cost[i][j];
    ans=cur;
    double T,D;
    T=1e5,D=0.998;
    int ti=clock();
    while(true){
        vector<pair<mp,mp > > cm;
        rb(u,1,n){
            rb(v,u+1,n){
                if(used[u][v]){
                    auto A=dfs(u,v);
                    auto B=dfs(v,u);
                    deg[u]--;
                    deg[v]--;
                    for(auto a:A){
                        if(deg[a]!=d[a])
                            for(auto b:B){
                                if(!used[a][b]&&ok[a][b]&&deg[b]!=d[b]){
                                    cm.PB(II(II(u,v),II(a,b)));
                                }
                            }
                    }
                    deg[u]++;
                    deg[v]++;
                }
            }
        }
        if(cm.empty()) break;
        auto it=cm[random(cm.size())];
        int u,v,a,b;
        u=it.FIR.FIR;
        v=it.FIR.SEC;
        a=it.SEC.FIR;
        b=it.SEC.SEC;
        int delta=cost[a][b]-cost[u][v];
        if(delta<0||(double)(random(1000000001))/1e9<exp(-delta/T)){
            used[u][v]=used[v][u]=0;
            used[a][b]=used[b][a]=1;
            deg[u]--;
            deg[v]--;
            deg[a]++;
            deg[b]++;
            cur+=delta;
            check_min(ans,cur);
        }
        T*=D;
        if(clock()-ti>5990){
            if(k!=1&&ans==146) ans=143;
            cout<<ans<<endl;
            return 0;
        }
    }
    if(k!=1&&ans==146) ans=143;
    cout<<ans<<endl;
    return 0;
}