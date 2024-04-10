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
int n,a[200005],val[200005],m,ss;
mii mp;
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        ss+=a[i];
    }
    cin>>m;
    rep(i,1,m+1){
        int s,t,u;
        cin>>s>>t>>u;
        int d=mp[{s,t}];
        if(d){
            ss+=min(a[d],val[d]);
            val[d]--;
            ss-=min(a[d],val[d]);
            mp[{s,t}]=0;
        }
        if(u){
            ss+=min(a[u],val[u]);
            val[u]++;
            ss-=min(a[u],val[u]);
            mp[{s,t}]=u;
        }
        cout<<ss<<endl;
    }
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