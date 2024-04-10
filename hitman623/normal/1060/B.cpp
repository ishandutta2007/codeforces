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
ll n,ans=0;
ll s(ll x){
    ll res=0;
    while(x) res+=x%10,x/=10;
    return res;
}
void solve(){
    cin>>n;
    if(n<100){
        rep(i,0,n+1){
            ans=max(ans,s(i)+s(n-i));
        }
    }
    else{
        ll cur=9;
        while(cur<=n){
            ans=max(ans,s(cur)+s(n-cur));
            cur=cur*10+9;
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