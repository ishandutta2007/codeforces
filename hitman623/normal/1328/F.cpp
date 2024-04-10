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
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,a[200005],p[200005];
mi mp;
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>a[i];
        mp[a[i]]++;
    }
    for(auto i:mp){
        if(i.y>=k){
            cout<<0<<endl;
            return;
        }
    }
    sort(a,a+n);
    rep(i,0,n) p[i]=(i?p[i-1]:0)+a[i];
    int ans=hell;
    rep(i,0,n){
        int small=lower_bound(a,a+n,a[i])-a;
        int big=n-(upper_bound(a,a+n,a[i])-a);
        int eq=n-small-big;
        int csmall=small*(a[i]-1)-(small?p[small-1]:0);
        int cbig=p[n-1]-(n-big-1>=0?p[n-big-1]:0)-big*(a[i]+1);
        if(small+eq>=k) ans=min(ans,csmall+k-eq);
        if(big+eq>=k) ans=min(ans,cbig+k-eq);
        ans=min(ans,csmall+cbig+k-eq);
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