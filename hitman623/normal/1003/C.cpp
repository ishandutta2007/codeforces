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
int n,k,a[10001];
long double ans=0;
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        if(i+k>n) break;
        int s=0;
        rep(j,0,k-1){
            s+=a[i+j];
        }
        rep(j,k-1,n){
            if(i+j>=n) break;
            s+=a[i+j];
            ans=max(ans,1.0l*s/(j+1));
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}