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
int n,cnt00,cnt01,cnt10,cnt11;
string a,b;
void solve(){
    cin>>n>>a>>b;
    rep(i,0,n){
        if(a[i]=='1' and b[i]=='0') cnt10++;
        if(a[i]=='0' and b[i]=='1') cnt01++;
        if(a[i]=='0' and b[i]=='0') cnt00++;
        if(a[i]=='1' and b[i]=='1') cnt11++;
    }
    cout<<cnt10*cnt01+cnt11*cnt00+cnt10*cnt00<<endl;
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