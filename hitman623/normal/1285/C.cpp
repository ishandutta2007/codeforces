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
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,ans=hell;
pii res;
vi v;
void solve(){
    cin>>n;
    for(int i=1;i*i<=n;i++){
    	if(n%i==0){
    		v.pb(i);
    		v.pb(n/i);
    	}
    }
    for(auto i:v){
    	int a=i;
    	int b=n/i;
    	if(__gcd(a,b)==1){
    		if(max(a,b)<ans){
				ans=max(a,b);
				res={a,b};    			
    		}
    	}
    }
    cout<<res.x<<" "<<res.y<<endl;
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