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
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
int x,n,ans=1;
vi v;
void solve(){
    cin>>x>>n;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            v.pb(i);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) v.pb(x);
    for(auto p:v){
        int d=n;
        int cnt=0;
        while(d){
            cnt+=d/p;
            d/=p;
        }
        ans=ans*expo(p,cnt,hell)%hell;
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