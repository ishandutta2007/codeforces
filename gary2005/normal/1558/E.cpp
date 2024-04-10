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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
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
const int MAXN=1e3+1;
vector<int> g[MAXN];
int n,m,a[MAXN],b[MAXN];
bool vis[MAXN];
LL dis[MAXN];
int pre[MAXN];
bool check(int x){
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    LL totb=0;
    while(true){
        rb(i,1,n) dis[i]=-1;
        totb=0;
        bool ok=false;
        rb(i,1,n) if(vis[i]) totb+=b[i];
        rb(i,1,n) ok|=!vis[i];
        if(!ok) break;
        totb+=x;
        queue<int> q;
        rb(i,1,n) if(vis[i]) for(auto it:g[i]) {
            if(!vis[it]&&a[it]<totb&&dis[it]==-1){
                q.push(it);
                dis[it]=totb;
                pre[it]=i;
            }
        }
        ok=false;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            for(auto it:g[now]) if(it!=pre[now]){
                if(vis[it]){
                    ok=1;
                    while(!vis[now]){
                        vis[now]=1;
                        now=pre[now];
                    }
                    break;
                }
                else{
                    if(dis[now]+b[now]<=a[it]){
                        continue;
                    }
                    if(dis[it]!=-1){
                        ok=1;
                        while(!vis[now]){
                            vis[now]=1;
                            now=pre[now];
                        }
                        now=it;
                        while(!vis[now]){
                            vis[now]=1;
                            now=pre[now];
                        }
                        break;
                    }
                    else{
                        pre[it]=now;
                        dis[it]=dis[now]+b[now];
                        q.push(it);
                    }
                }
            }
            if(ok) break;
        }
        if(!ok) return false;
    }
    return true;
}
void solve(){
    scanf("%d%d",&n,&m);
    rb(i,2,n) scanf("%d",&a[i]);
    rb(i,2,n) scanf("%d",&b[i]);
    rb(i,1,n) g[i].clear();
    rb(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
    LL l=0,r=1e9+1;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();    
    return 0;
}