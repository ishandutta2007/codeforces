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
int n,q,a[200005],rig[200005],ans,freq[200005];
int get(int l,int r){
    int mx=0;
    rep(i,l,r+1){
        freq[a[i]]++;
        mx=max(mx,freq[a[i]]);
    }
    rep(i,l,r+1) freq[a[i]]=0;
    return r-l+1-mx;
}
void solve(){
    cin>>n>>q;
    rep(i,1,n+1){
        cin>>a[i];
        rig[a[i]]=i;
    }
    int mx=1,last=1;
    vii v;
    rep(i,1,n+1){
        mx=max(mx,rig[a[i]]);
        if(mx<=i){
            v.pb({last,i});
            last=i+1;
        }
    }
    for(auto i:v) ans+=get(i.x,i.y);
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