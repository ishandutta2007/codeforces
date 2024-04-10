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
int n,a[200005];
mi mp;
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    int last=0,ans=0;
    mp[0]=0;
    rep(i,1,n+1){
        if(mp.count(a[i])) last=max(last,mp[a[i]]+1);
        mp[a[i]]=i;
        ans+=i-last;
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