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
int n,a[1001][1001],ans[1001];
void solve(){
    cin>>n;
    rep(i,0,n){
    	rep(j,0,n){
    		cin>>a[i][j];
    	}
    }
    ans[0]=sqrt(a[0][1]*a[0][2]/a[1][2]);
    rep(i,1,n) ans[i]=a[0][i]/ans[0];
    rep(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;
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