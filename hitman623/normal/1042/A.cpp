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
int n,m,a[10004],mx,s,ans;
priority_queue<int,vi,greater<int>> pq;
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>a[i];
        pq.push(a[i]);
        mx=max(mx,a[i]);
    }
    rep(i,0,m){
        auto d=pq.top();
        pq.pop();
        pq.push(d+1);
    }
    while(!pq.empty()){
        ans=max(ans,pq.top());
        pq.pop();
    }
    cout<<ans<<" "<<mx+m<<endl;
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