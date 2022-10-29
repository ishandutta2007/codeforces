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
int n,x[10005],mx;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>x[i];
        mx=max(mx,x[i]);
    }
    rep(k,mx,20000){
        int s=0,y=0;
        rep(i,0,n){
            s+=x[i];
            y+=k-x[i];
        }
        if(s<y){
            cout<<k<<endl;
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