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
int n,m,ans;
int f[1000006];
void compute(){
	f[0]=1;
	rep(i,1,1000001) f[i]=(1LL*i*f[i-1])%m;
}
void solve(){
    cin>>n>>m;
    compute();
    rep(l,1,n+1){
    	ans=(ans+(n-l+1)*f[n-l+1]%m*f[l]%m)%m;
    }
    cout<<ans<<endl;
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