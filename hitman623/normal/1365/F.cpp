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
int n,a[505],b[505];
void solve(){
    vii va,vb;
    cin>>n;
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>b[i];
    rep(i,0,n/2){
        int l=a[i];
        int r=a[n-i-1];
        if(l>r) swap(l,r);
        va.pb({l,r});
    }
    rep(i,0,n/2){
        int l=b[i];
        int r=b[n-i-1];
        if(l>r) swap(l,r);
        vb.pb({l,r});
    }
    sort(all(va));
    sort(all(vb));
    if(va==vb and (n%2==0 or a[n/2]==b[n/2])) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}