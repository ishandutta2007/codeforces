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
int k,n,ans;
vii v;
void solve(){
    cin>>n>>k;
    rep(i,1,n+1){
        int x,y;
        cin>>x>>y;
        v.pb({y,x});
    }
    sort(all(v));
    priority_queue<int,vi,greater<int>> pq;
    int cur=0;
    for(int i=n-1;i>=0;i--){
        cur+=v[i].y;
        pq.push(v[i].y);
        if(sz(pq)>k){
            cur-=pq.top();
            pq.pop();
        }
        ans=max(ans,v[i].x*cur);
    }
    cout<<ans<<endl;
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