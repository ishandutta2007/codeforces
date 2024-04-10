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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,ans,x;
void solve(){
    cin>>n;
    cout<<1<<" "<<n-1<<" ";
    rep(i,1,n+1) cout<<i<<" ";
    cout<<endl;
    cin>>ans;
    int lo=1,hi=n;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        cout<<1<<" "<<mid-1<<" ";
        rep(i,1,mid+1) cout<<i<<" ";
        cout<<endl;
        cin>>x;
        if(x==ans) hi=mid;
        else lo=mid;
    }
    cout<<1<<" "<<n-1<<" "<<hi<<" ";
    rep(i,1,n+1) if(i!=hi) cout<<i<<" ";
    cout<<endl;
    cin>>ans;
    cout<<-1<<" "<<ans<<endl;
}

signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}