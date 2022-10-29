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
vi p[200005];
void process_seive(int n){
    rep(i,2,n+1){
        if(sz(p[i])) continue;
        for(int j=i;j<=n;j+=i){
        	p[j].pb(i);
        }
    }
}
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
vi f[200005];
void solve(){
    process_seive(200000);
    int n;
    cin>>n;
    rep(i,0,n){
    	int x;
    	cin>>x;
    	for(auto j:p[x]){
    		int d=x,cnt=0;
    		while(d%j==0){
    			d/=j;
    			cnt++;
    		}
    		f[j].pb(cnt);
    	}
    }
    int ans=1;
    rep(i,1,200001){
    	if(sz(f[i])<n) f[i].pb(0);
    	if(sz(f[i])<n) f[i].pb(0);
    	sort(all(f[i]));
    	ans=ans*expo(i,max(f[i][0],f[i][1]),hell);
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