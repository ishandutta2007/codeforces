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
int n,ans;
vi pos[100005];
void solve(){
    cin>>n;
    rep(i,0,2*n){
        int x;
        cin>>x;
        pos[x].pb(i);
    }
    int cur1=0,cur2=0;
    rep(i,1,n+1){
        ans+=min(abs(cur1-pos[i][0])+abs(cur2-pos[i][1]),abs(cur2-pos[i][0])+abs(cur1-pos[i][1]));
        cur1=pos[i][0];
        cur2=pos[i][1];
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