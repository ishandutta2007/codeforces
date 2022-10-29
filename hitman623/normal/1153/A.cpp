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
#define hell        1000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,t,mn=hell,ans;
void solve(){
    cin>>n>>t;
    rep(i,0,n){
    	int s,d;
    	cin>>s>>d;
    	// s+r*d>=t
    	int r=(t-s)/d;
    	while(r<0 or s+r*d<t) r++;
    	if(mn>s+r*d){
    		mn=s+r*d;
    		ans=i+1;
    	}
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}