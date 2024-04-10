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
int n,m;
long double mn,mx;
long double ans;
void solve(){
    cin>>n>>m;
    if(n%2){
        mn=(n/2)*(n/2+1);
        mx=n*(n-1)/2;
    }
    else{
        mn=(n/2)*(n/2+1)/2 + (n/2)*(n/2-1)/2;
        mx=n*(n-1)/2;
    }
    rep(i,0,m){
        long double x,d;
        cin>>x>>d;
        ans+=x*n+max(d*mx,d*mn);
    }
    cout<<fixed<<setprecision(20)<<ans/n<<endl;
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