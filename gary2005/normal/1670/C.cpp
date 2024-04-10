/**
 *    author:  gary
 *    created: 06.05.2022 22:35:07
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
const int MAXN=1e5+10;
int n,a[MAXN],b[MAXN],d[MAXN],fa[MAXN],ans[MAXN],coef=1;
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
vector<mp> g[MAXN];
void dfs(int now,int pre){
    if(ans[pre]!=-1){
        coef&=ans[pre]==now;
        return ;
    }
    ans[pre]=now;
    for(auto it:g[now]) if(it.second!=pre){
        dfs(it.first,it.second);
    }
}
void solve(){
    coef=1;
    cin>>n;
    rb(i,1,n) ans[i]=-1,fa[i]=i,g[i].clear();
    rb(i,1,n) cin>>a[i];
    rb(i,1,n) cin>>b[i];
    rb(i,1,n) cin>>d[i];
    rb(i,1,n) fa[root(a[i])]=root(b[i]),g[a[i]].PB(II(b[i],i)),g[b[i]].PB(II(a[i],i));
    rb(i,1,n) if(d[i]&&a[i]!=b[i]){
        if(d[i]==a[i]){
            dfs(a[i],i);
        }
        else{
            dfs(b[i],i);
        }
    }
    rb(i,1,n) if(a[g[i][0].second]!=b[g[i][0].second]&&root(i)==i&&ans[g[i][0].second]==-1) coef=(coef*2)%(int)(1e9+7);
    cout<<coef<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}