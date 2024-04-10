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
int n,k,a[200001];
void solve(){
    cin>>n>>k;
    rep(i,1,n+1){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    mi mp;
    mp[0]=1;
    int f=0;
    rep(i,1,n+1){
        if(f) a[i]^=(1<<k)-1;
        if(mp.count(a[i]) and mp[a[i]]>mp[a[i]^((1<<k)-1)]){
            a[i]^=(1<<k)-1;
            f=f^1;
        }
        mp[a[i]]++;
    }
    int ans=0;
    for(auto i:mp){
        ans+=i.y*(i.y-1)/2;
    }
    cout<<n*(n+1)/2-ans<<endl;
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