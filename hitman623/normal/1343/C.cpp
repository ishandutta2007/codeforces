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
int n,a[200005];
int s(int x){
    if(x<0) return-1;
    else return 1;
}
void solve(){
    vi v;
    cin>>n;
    rep(i,0,n) cin>>a[i];
    rep(i,0,n){
        if(sz(v)==0 or s(v.back())!=s(a[i])) v.pb(a[i]);
        else v.back()=max(v.back(),a[i]);
    }
    ll s=0;
    for(auto i:v) s+=i;
    cout<<s<<endl;
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