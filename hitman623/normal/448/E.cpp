#include <bits/stdc++.h>

#define int         long long
#define pb          emplace_back
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
vi ans,divisors;
void sol(int n,int k){
    if(k==0 or n==1){
        ans.pb(n);
        if(sz(ans)==1e5){
            for(auto i:ans) cout<<i<<" ";
            exit(0);
        }
        return;
    }
    for(auto i:divisors){
        if(n%i==0){
            sol(i,k-1);
        }
        if(i>n) break;
    }
}
void solve(){
    int x,k;
    cin>>x>>k;
    if(x==1){
        cout<<1<<endl;
        return;
    }
    if(k>1e5){
        rep(i,0,1e5){
            cout<<1<<" ";
        }
        return;
    }
    for(int i=1;i*i<=x;++i){
        if(x%i==0){
            divisors.pb(i);
            if(i!=x/i) divisors.pb(x/i);
        }
    }
    sort(all(divisors));
    sol(x,k);
    for(auto i:ans) cout<<i<<" ";
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