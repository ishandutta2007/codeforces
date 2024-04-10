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
#define endl        '\n'
#define hell        1000000007
#define pi          1.0l*acos(-1)
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

void solve(){
    int n;
    cin>>n;
    n*=2;
    long double theta=2*pi/n;
    long double r=1.0l/(2*sin(theta/2));
    long double ans=0;
    rep(d,0,n/4+1) ans=max(ans,2*r*(cos(theta*d)+sin(theta*d))/sqrtl(2));
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}