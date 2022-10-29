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
vi v;
void solve(){
    cin>>n>>k;
    if(n<(k*(k+1)/2)){
        cout<<"NO"<<endl;
        return;
    }
    n-=(k*(k+1)/2);
    int rem=n%k;
    rep(i,1,k+1) v.pb(i);
    rep(i,0,k) v[i]+=n/k;
    for(int i=k-1;i>=0;i--){
        if(rem) v[i]++,rem--;
    }
    int extra=0;
    rep(i,1,k){
        if(v[i]>v[i-1]*2){
            extra+=v[i]-2*v[i-1];
            v[i]=2*v[i-1];
        }
    }
    v.back()+=extra;
    rep(i,1,k){
        if(v[i]>2*v[i-1] or v[i]<=v[i-1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(auto i:v) cout<<i<<" ";
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