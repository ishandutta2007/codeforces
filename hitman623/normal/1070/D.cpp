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
int n,k,ans,cur=0;
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        int x;
        cin>>x;
        if(cur+x>=k){
            ans++;
            x-=k-cur;
            ans+=x/k;
            cur=x%k;
        }
        else if(cur) ans++,cur=0;
        else cur=x;
    }
    if(cur) ans++;
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