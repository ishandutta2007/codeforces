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
int n,k,a[200005];
ll ans;
unordered_map<int,int> v2[13];
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>a[i];
        int cur=10;
        rep(j,1,12){
            v2[j][(1LL*a[i]*cur)%k]++;
            cur=(10LL*cur)%k;
        }
    }
    rep(i,0,n){
        int req=(k-(a[i]%k))%k;
        int l=to_string(a[i]).length();
        ans+=v2[l][req];
        int d=a[i];
        rep(j,0,l) d=(1LL*d*10)%k;
        if((d+a[i])%k==0) ans--;
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