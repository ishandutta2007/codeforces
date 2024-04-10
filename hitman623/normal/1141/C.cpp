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
int n,q[200005],p[200005],mn=hell;
void solve(){
    cin>>n;
    rep(i,0,n-1) cin>>q[i];
    rep(i,1,n-1) q[i]+=q[i-1];
    rep(i,0,n-1){
        mn=min(mn,q[i]);
    }
    p[0]=1-min(0,mn);
    rep(i,1,n) p[i]=p[i-1]+(q[i-1]-(i>=2?q[i-2]:0));
    vi v;
    rep(i,0,n) v.pb(p[i]);
    sort(all(v));
    rep(i,0,n) if(v[i]!=i+1){
        cout<<-1<<endl;
        return;
    }
    rep(i,0,n) cout<<p[i]<<" ";
    cout<<endl;
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