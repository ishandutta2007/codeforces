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
int n,m,s,a[200005],f[200005];
void solve(){
    cin>>n>>m;
    rep(i,1,n+1) cin>>a[i];
    sort(a+1,a+n+1);
    rep(i,1,n+1){
        s+=a[i];
        if(i-m>0) s+=f[i-m];
        f[i]=(i-m>0?f[i-m]:0)+a[i];
        cout<<s<<" ";
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