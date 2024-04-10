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
int n,x[1001],y[1001],a[1001],b[1001];
mii mp;
void solve(){
    cin>>n;
    rep(i,0,n) cin>>x[i]>>y[i];
    rep(i,0,n) cin>>a[i]>>b[i],mp[{a[i],b[i]}]=i;
    rep(i,0,n){
        int tx=x[0]+a[i],ty=y[0]+b[i];
        bool f=1;
        rep(j,0,n){
            if(mp.count({tx-x[j],ty-y[j]})==0) f=0;
        }
        if(f){
            cout<<tx<<" "<<ty<<endl;
            return;
        }
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