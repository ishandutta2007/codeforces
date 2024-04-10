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

int n,b[100005],a[200005];
void solve(){
    cin>>n;
    rep(i,1,n/2+1) cin>>b[i];
    a[1]=0;
    a[n]=b[1];
    rep(i,2,n/2+1){
        a[i]=max(a[i-1],b[i]-a[n-i+2]);
        a[n-i+1]=b[i]-a[i];
    }
    rep(i,1,n+1) cout<<a[i]<<" ";
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