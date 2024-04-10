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
#define hell        1000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

void solve(){
    int n,g=0,cnt=0;
    cin>>n;
    rep(i,0,n){
    	int x;
    	cin>>x;
    	g=__gcd(g,x);
    }
    for(int i=1;i*i<=g;i++){
    	if(g%i==0) cnt++;
    	if(g%i==0 and i*i!=g) cnt++;
    }
    cout<<cnt<<endl;
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