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
int n,k,a[500005],pre[500006],suf[500005],ans;
map<int,vi> f;
void solve(){
	cin>>n>>k;
    rep(i,1,n+1){
    	cin>>a[i];
    	a[i]=k-a[i];
   		f[a[i]].pb(i);
    }
    rep(i,1,n+1) pre[i]=pre[i-1]+(a[i]==0);
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+(a[i]==0);
    for(auto i:f){
    	n=sz(i.y);
    	int cur=n+suf[i.y.back()+1];
    	for(int j=n-1;j>=0;j--){
    		ans=max(ans,pre[i.y[j]-1]+cur-j);
    		if(j) cur=max(cur,j+suf[i.y[j-1]+1]);
    	}
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