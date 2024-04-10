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
int n,ans,a[1001],vis[1001];
void solve(){
    cin>>n;
    rep(i,0,n) cin>>a[i];
    sort(a,a+n);
    rep(i,0,n){
    	if(vis[i]==0){
    		ans++;
    		rep(j,i+1,n){
    			if(a[j]%a[i]==0){
    				vis[j]=1;
    			}
    		}
    	}
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