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
int n,x,d[101],h[101];
void solve(){
    cin>>n>>x;
    rep(i,0,n) cin>>d[i]>>h[i];
    rep(i,0,n){
    	if(x<=d[i]){
    		cout<<1<<endl;
    		return;
    	}
    }
    int ans=hell;
    rep(i,0,n){
    	if(d[i]-h[i]<=0) continue;
    	rep(j,0,n){
    		ans=min(ans,(x-d[j]+d[i]-h[i]-1)/(d[i]-h[i])+1);
    	}
    }
    if(ans==hell) ans=-1;
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}