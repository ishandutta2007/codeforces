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
int n,m,x[1001],y[1001];
void solve(){
    cin>>n>>m;
    rep(i,1,n+1){
        cin>>x[i];
    }
    rep(i,1,n+1){
        cin>>y[i];
    }
    if(x[1]==0){
        cout<<"NO"<<endl;
        return;
    }
    if(x[m]==1){
        cout<<"YES"<<endl;
        return;
    }
    if(y[m]==0){
        cout<<"NO"<<endl;
        return;
    }
    rep(i,m,n+1){
        if(x[i]==1 and y[i]==1){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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