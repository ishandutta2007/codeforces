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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,a[200005],b[200005];
void solve(){
    cin>>n>>k;
    rep(i,1,n+1) cin>>a[i];
    k=n-k+1;
    int s=0,ans=1,last=0;
    rep(i,1,n+1){
    	if(a[i]>=k){
    		s+=a[i];
    		if(last) ans=ans*(i-last)%hell;
    		last=i;
    	}
    }
    cout<<s<<" "<<ans<<endl;
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