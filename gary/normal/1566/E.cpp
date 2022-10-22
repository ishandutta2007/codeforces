/**
 *    author:  gary
 *    created: 12.09.2021 22:33:00
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
int cnt0,cnt1;
bool bud[MAXN];
int n;
vector<int> g[MAXN];
void dfs(int now,int pre){
    bool have=0;
    for(auto it:g[now]) if(it!=pre){
        dfs(it,now);
        if(!bud[it]){
            have=1;
            if(now==1){
                cnt0++;
            }
        } 
    } 
    if(have&&now!=1){
        bud[now]=1;
        cnt1++;
    }
}
void solve(){
    cnt0=cnt1=0;
    scanf("%d",&n);
    rb(i,1,n) g[i].clear(),bud[i]=0;
    rb(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0);
    int answer=0;
    rb(i,2,n){
        answer+=!bud[i];
    }
    if(cnt1){
        answer-=cnt1-1;
        if(cnt0) answer--;
    }
    cout<<answer<<endl;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}