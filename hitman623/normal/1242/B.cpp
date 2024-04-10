#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,ans,cnt;
bitset<100002> unvis;
unordered_set<int> a[100005];
void dfs(int node){
    cnt++;
    unvis[node]=0;
    for(int x=unvis._Find_first();x<=n;x=unvis._Find_next(x)){
        if(a[node].count(x)==0) dfs(x);
    }
}
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].insert(y);
        a[y].insert(x);
    }
    rep(i,1,n+1) unvis.set(i);
    rep(i,1,n+1){
        if(unvis[i]){
            cnt=0;
            dfs(i);
            ans++;
        }
    }
    cout<<ans-1<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}