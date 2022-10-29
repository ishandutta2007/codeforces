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
int n,m,f[101],res;
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        int x;
        cin>>x;
        f[x]++;
    }
    if(m<n){
        cout<<0<<endl;
        return;
    }
    rep(i,1,101){
        int ans=0;
        rep(j,1,101){
            ans+=f[j]/i;
        }
        if(ans>=n){
            res=i;
        }
        else break;
    }
    cout<<res<<endl;
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