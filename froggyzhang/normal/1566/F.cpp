#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
#define int ll
const ll inf=1e18;
int n,m,a[N],dp[N][2];
vector<pair<int,int> > seg[N];
void Solve(){
    cin>>n>>m;
    for(int i=2;i<=n+1;++i){
    	cin>>a[i];
    }
    sort(a+2,a+n+2);
    a[1]=-inf;
    a[n+2]=inf;
    n+=2;
    for(int i=1;i<=n;++i)seg[i].clear(),dp[i][0]=dp[i][1]=inf;
    for(int i=1;i<=m;++i){
		int l,r;
		cin>>l>>r;
		int pl=lower_bound(a+1,a+n+1,l)-a;
		int pr=upper_bound(a+1,a+n+1,r)-a;
		if(pl^pr)continue;
		seg[pl].emplace_back(l,r);
	}
    dp[1][0]=dp[1][1]=0;
    for(int i=2;i<=n;++i){
    	sort(seg[i].begin(),seg[i].end());
    	int r=a[i];
    	for(int j=(int)seg[i].size();j>=0;--j){
    		if(j<(int)seg[i].size()){
				r=min(r,seg[i][j].second);	
			}	
			ll l=a[i-1];
			if(j>0){
				l=seg[i][j-1].first;
			}
			dp[i][0]=min(dp[i][0],dp[i-1][0]+(l-a[i-1])+2*(a[i]-r));
			dp[i][0]=min(dp[i][0],dp[i-1][1]+2*(l-a[i-1])+2*(a[i]-r));
			dp[i][1]=min(dp[i][1],dp[i-1][0]+(l-a[i-1])+(a[i]-r));
			dp[i][1]=min(dp[i][1],dp[i-1][1]+2*(l-a[i-1])+(a[i]-r));
    	}
    }
    cout<<min(dp[n][0],dp[n][1])<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}