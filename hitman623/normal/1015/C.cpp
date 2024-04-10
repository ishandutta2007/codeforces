#include <bits/stdc++.h>

#define int         long long
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
int n,m,s=0,ans;
void solve(){
    cin>>n>>m;
    priority_queue<pair<int,pii>> pq;
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        pq.push({a-b,{a,b}});
        s+=a;
    }
    while(s>m and !pq.empty()){
        ans++;
        auto d=pq.top();
        pq.pop();
        s-=d.x;
    }
    if(s<=m) cout<<ans<<endl;
    else cout<<-1<<endl;
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