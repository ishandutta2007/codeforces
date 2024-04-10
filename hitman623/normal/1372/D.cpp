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
int n,ans,p[200005],s[200005],a[200005];
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,n+1){
        p[i]=a[i];
        if(i>=2) p[i]+=p[i-2];
    }
    for(int i=n;i>=1;i--){
        s[i]=a[i];
        s[i]+=s[i+2];
    }
    rep(i,1,n+1){
        ans=max(ans,p[i-1]+s[i]);
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