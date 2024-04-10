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
void solve(){
    cin>>n;
    int m=n*(n+1)/2;
    for(int i=2;i*i<=m;++i){
        if(m%i==0){
            if(i<=n){
                cout<<"Yes"<<endl;
                cout<<1<<" "<<i<<endl;
                cout<<n-1<<" ";
                rep(j,1,n+1){
                    if(j!=i) cout<<j<<" ";
                }
                cout<<endl;
                return;
            }
        }
    }
    cout<<"No"<<endl;
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