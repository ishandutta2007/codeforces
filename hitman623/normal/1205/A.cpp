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
int n;
vi v1,v2;
void solve(){
    cin>>n;
    if(n%2==0){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    rep(i,1,n+1){
        if(i%2) v1.pb(2*i-1),v2.pb(2*i);
        else v1.pb(2*i),v2.pb(2*i-1);
    }
    for(auto i:v1) cout<<i<<" ";
    for(auto i:v2) cout<<i<<" ";
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