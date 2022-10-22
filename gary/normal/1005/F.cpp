/**
 *    author:  gary
 *    created: 25.09.2021 14:44:04
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
const int MAXN=2e5+1;
int n,m,k;
vector<int> g[MAXN];
vector<vector<int> > cho;
int depth[MAXN];
map<mp,int> id;
int t=1;
bool rest[MAXN];
void dfs(int now){
    if(now==cho.size()){
        rb(i,1,m) putchar('0'+rest[i]);
        putchar('\n');
        t--;
        if(t==0) exit(0);
        return;
    }
    rep(i,cho[now].size()){
        rest[cho[now][i]]=1;
        dfs(now+1);
        rest[cho[now][i]]=0;
    }
}
int main(){
    cin>>n>>m>>k;
    queue<int> q;
    rb(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        id[II(u,v)]=id[II(v,u)]=i;
        g[u].PB(v);
        g[v].PB(u);
    }
    q.push(1);
    memset(depth,63,sizeof(depth));
    depth[1]=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto it:g[now]) if(depth[it]==INF){
            depth[it]=depth[now]+1;
            q.push(it);
        }
    }
    rb(i,2,n){
        vector<int> Now;
        for(auto it:g[i]) if(depth[it]<depth[i]){
            Now.PB(id[II(it,i)]);
        }
        cho.PB(Now);
        t=min((unsigned LL)(k),1ll*t*Now.size());
    }
    cout<<t<<endl;
    dfs(0);
    return 0;
}