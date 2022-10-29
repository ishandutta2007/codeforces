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
int n,f[200005];
vi v1,v2;
void solve(){
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        f[x]++;
    }
    rep(i,0,200001){
        if(f[i]>2){
            cout<<"NO"<<endl;
            return;
        }
        if(f[i]) v1.pb(i);
        if(f[i]>1) v2.pb(i);
    }
    sort(all(v1));
    sort(all(v2));
    reverse(all(v2));
    cout<<"YES"<<endl;
    cout<<sz(v1)<<endl;
    for(auto i:v1) cout<<i<<" ";
    cout<<endl;
    cout<<sz(v2)<<endl;
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