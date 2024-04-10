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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

void solve(){
    cout<<"? ";
    rep(i,0,100) cout<<i<<" ";
    int a;
    cin>>a;
    vi v; 
    rep(i,1,1<<8) v.pb(i<<7);
    v.resize(100);
    cout<<"? ";
    rep(i,0,100) cout<<v[i]<<" ";
    int b;
    cin>>b;
    a^=b;
    rep(i,0,100){
        rep(j,0,100){
            if((i^v[j])==a){
                cout<<"! "<<(b^v[j])<<endl;
                return;
            }
        }
    }
}

signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}