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
vi divisor;
set<int> res;
void solve(){
    int n;
    cin>>n;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            divisor.pb(i);
            if(n/i!=i) divisor.pb(n/i);
        }
    }
    for(auto i:divisor){
        int cur=(n/i)+i*(n/i)*(n/i-1)/2;
        res.insert(cur);
    }
    for(auto i:res) cout<<i<<" ";
    cout<<endl;
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