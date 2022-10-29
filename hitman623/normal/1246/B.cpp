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
#define hell        100000
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,a[100005],f[100005],c[100005],freq[100005];
void solve(){
    cin>>n>>k;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,100005){
    	int m=i;
    	f[i]=1;
    	c[i]=1;
    	for(int j=2;j*j<=m;j++){
    		if(m%j==0){
    			int cnt=0;
    			while(m%j==0) m/=j,cnt++;
    			cnt%=k;
    			rep(_,0,cnt) f[i]*=j;
				if(cnt)
				rep(_,0,k-cnt){
					if(c[i]>hell) break;
					c[i]*=j;
				}
    		}
    	}
    	if(m>1){
    		f[i]*=m;
    		rep(_,0,k-1){
    			if(c[i]>hell) break;
    			c[i]*=m;
    		}
    	}
    }
    int ans=0;
    rep(i,1,n+1){
    	if(c[a[i]]<=hell) ans+=freq[c[a[i]]];
    	freq[f[a[i]]]++;
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