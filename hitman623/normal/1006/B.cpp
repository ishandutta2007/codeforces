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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,a[2002],mark[2002],ans;
vii v;
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>a[i];
        v.pb({a[i],i});
    }
    sort(all(v));
    reverse(all(v));
    rep(i,0,k){
        mark[v[i].y]=1;
        ans+=v[i].x;
    }
    cout<<ans<<endl;
    int cnt=0;
    rep(i,0,n){
        if(mark[i]){
            k--;
            if(k==0) cout<<cnt+n-i<<endl;
            else cout<<cnt+1<<" ";
            cnt=0;
        }
        else cnt++;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}