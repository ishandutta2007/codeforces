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
int a[3],b[3],n,sa,sb;
void solve(){
    rep(i,0,3){
        cin>>a[i];
        sa+=a[i];
    }
    rep(i,0,3){
        cin>>b[i];
        sb+=b[i];
    }
    cin>>n;
    if((sa+4)/5+(sb+9)/10 > n) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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