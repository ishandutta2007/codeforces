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
int n,a[100005],b[100005];
void solve(){
    int l=0,r=0;
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,n+1) cin>>b[i];
    rep(i,1,n+1){
        if(a[i]!=b[i]){
            l=i;
            break;
        }
    }
    for(int i=n;i>=1;i--){
        if(a[i]!=b[i]){
            r=i;
            break;
        }
    }
    if(l==0) cout<<"YES"<<endl;
    else{
        int d=b[l]-a[l],f=1;
        rep(i,l,r+1){
            if(b[i]-a[i]!=d){
                f=0;
            }
        }
        if(f and d>0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
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