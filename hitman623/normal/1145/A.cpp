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
int n,a[1003];
void solve(){
    cin>>n;
    rep(i,0,n) cin>>a[i];
    for(int s=n;s;s/=2){
        for(int i=0;i<n-s+1;i+=s){
            vi v;
            rep(j,i,i+s){
                v.pb(a[j]);
            }
            if(is_sorted(all(v))){
                cout<<s<<endl;
                return;
            }
        }
    }
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