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
int n,a,b,x[22],ans;
void solve(){
    cin>>n>>a>>b;
    rep(i,0,n){
        cin>>x[i];
    }
    rep(i,0,n/2){
        if(x[i]!=2 and x[n-i-1]!=2){
            if(x[i]!=x[n-i-1]){
                cout<<-1<<endl; 
                return; 
            }
        }
        else if(x[i]==2 and x[n-i-1]==2) ans+=2*min(a,b);
        else if(x[i]==0 || x[n-i-1]==0) ans+=a;
        else ans+=b; 
    }
    if(n%2 and x[n/2]==2) ans+=min(a,b);
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