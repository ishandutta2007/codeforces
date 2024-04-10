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
int n,k,h[200005],mn=hell,ans;
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        int x;
        cin>>x;
        h[x]++;
        mn=min(mn,x);
    }
    int height=200000;
    int cur=0;
    int cost=0;
    while(height>=mn){
        cost+=cur;
        if(cost>k){
            ans++;
            cost=cur;
        }
        cur+=h[height];
        height--;
    }
    if(cost) ans++;
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