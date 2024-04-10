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
int n,m,ans[100005],s[100005];
void solve(){
    cin>>n>>m;
    vi v;
    rep(i,0,m){
        int l;
        cin>>l;
        v.pb(l);
    }
    rep(i,0,sz(v)){
        if(v[i]+i>n){
            cout<<-1<<endl;
            return;
        }
        s[i]=v[i]+i;
    }
    for(int i=m-2;i>=0;i--) s[i]=max(s[i],s[i+1]);
    int shift=0;
    rep(i,0,sz(v)){
        ans[i]=i+1+shift;
        if(i==sz(v)-1) break;
        int d=min(v[i]-1,n-s[i+1]-shift);
        shift+=d;
    }
    if(s[m-1]+shift<n) cout<<-1<<endl;
    else rep(i,0,m) cout<<ans[i]<<" ";
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