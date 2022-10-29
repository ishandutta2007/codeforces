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
int n;
vi p;
void solve(){
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            p.pb(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) p.pb(n);
    if(sz(p)>1) cout<<1<<endl;
    else cout<<p[0]<<endl;
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