/**
 *    author:  gary
 *    created: 20.02.2022 22:31:45
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
vector<mp> c[MAXN];
int d[MAXN];
vector<int> g[MAXN];
char ans[MAXN];
void dfs(int now){
    for(auto it:c[now]){
        if(it.first==1){
            if(ans[now]=='L'){
                g[now].PB(it.second);
            }
            else{
                g[it.second].PB(now);
            }
        }
        else{
            if(ans[now]=='R'){
                g[now].PB(it.second);
            }
            else{
                g[it.second].PB(now);
            }
        }
        char nx;
        if(ans[now]=='L') nx='R';
        else nx='L';
        if(ans[it.second]==nx) continue;
        if(ans[it.second]!='*'){
            cout<<"NO\n";
            exit(0);
        }
        ans[it.second]=nx;
        dfs(it.second);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    rb(i,1,n) ans[i]='*';
    rb(i,1,m){
        int t,x,y;
        cin>>t>>x>>y;
        c[x].PB(II(t,y));
        c[y].PB(II(t,x));
    }
    rb(i,1,n) if(ans[i]=='*') ans[i]='L',dfs(i);
    rb(i,1,n) for(auto it:g[i]) d[it]++;
    queue<int> q;
    vector<int> ansv;
    rb(i,1,n) if(!d[i]) q.push(i);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        ansv.PB(now);
        for(auto it:g[now]){
            d[it]--;
            if(d[it]==0) q.push(it);
        }
    }
    if(ansv.size()!=n){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES\n";
        rep(i,ansv.size()) d[ansv[i]]=i;
        rb(i,1,n){
            cout<<ans[i]<<' '<<d[i]<<endl;
        }
    }
    return 0;
}