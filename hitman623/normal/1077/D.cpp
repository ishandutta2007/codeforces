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
int n,k;
mi a;
bool check(int mid){
    int cnt=0;
    for(auto i:a){
        cnt+=i.y/mid;
    }
    return cnt>=k;
}
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        int x;
        cin>>x;
        a[x]++;
    }
    int lo=1,hi=2e5+2;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(check(mid)) lo=mid;
        else hi=mid;
    }
    for(auto i:a){
        rep(j,0,i.y/lo){
            if(k) cout<<i.x<<" ",k--;
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