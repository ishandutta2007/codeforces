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
int n,x;
vi v;
void solve(){
    cin>>n>>x;
    rep(i,1,(1<<n)){
        if(i==x) continue;
        int a=i;
        int b=i^x;
        v.pb(min(a,b));
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    for(int i=sz(v)-2;i>=0;i--){
        v[i+1]^=v[i];
    }
    cout<<sz(v)<<endl;
    for(auto i:v) cout<<i<<" ";
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