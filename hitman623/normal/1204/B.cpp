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

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    int mn=0,cur=1;
    rep(i,0,l){
        mn+=cur;
        cur*=2;
    }
    mn+=n-l;
    int mx=0;
    cur=1;
    rep(i,0,r){
        mx+=cur;
        cur*=2;
    }
    mx+=(n-r)*cur/2;
    cout<<mn<<" "<<mx<<endl;
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