/**
 *    author:  gary
 *    created: 17.01.2022 11:42:28
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
const int MAXN=3e5+1;
int n,c[MAXN],ans[MAXN],dist[MAXN],f[MAXN];
bool ok[MAXN],ok2[MAXN];
vector<int> g[MAXN];
int tot=0;
void dfs(int now,int pre){
    f[now]=pre;
    bool flag=c[now];
    for(auto it:g[now]) if(it!=pre) dfs(it,now),c[now]+=c[it];
    ok[now]|=(tot-c[now])>=2;
    for(auto it:g[now]) if(it!=pre) ok[now]|=c[it]>=2;
    if(flag&&c[now]!=tot) ans[now]++;
    if(flag)
    for(auto it:g[now]) if(it!=pre&&c[it]) {
        ans[1]++;
        ans[it]--;
    }
}
void dfs2(int now,int pre){
    for(auto it:g[now]) if(it!=pre) ans[it]+=ans[now],dfs2(it,now);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) dist[i]=INF;
    queue<int> q;
    rb(i,1,n) cin>>c[i],tot+=c[i];
    rb(i,1,n-1){
        int u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    rb(i,1,n) if(c[i]) q.push(i),dist[i]=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto it:g[now]) if(dist[it]==INF){
            dist[it]=dist[now]+1;
            q.push(it);
        }
    }
    rb(i,1,n){
        ok[i]=c[i];
        for(auto it:g[i]) ok[i]|=c[it];
    }
    dfs(1,0);
    rb(i,1,n) if(dist[i]==1){
        for(auto j:g[i]){
            int tmp=(f[j]==i? tot-c[j]:c[i]);
            if(tmp>=2){
                if(f[j]==i){
                    ans[j]++;
                }
                else{
                    ans[1]++;
                    ans[i]--;
                }
            }
        }
    }
    dfs2(1,0);
    rb(i,1,n) cout<<(((ans[i]>=1)||(dist[i]<=1)||ok2[i])&&ok[i])<<" ";
    cout<<endl;
    return 0;
}