#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
int n,m;
ll a[N];
pair<ll,ll>b[N];
int king[N];
ll dp1[N],dp2[N],dp3[N],dp4[N];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=m ;i++){
		cin >> b[i].fi >> b[i].se;
	}
	sort(b+1,b+m+1);
	vector<pair<ll,ll> >v;
	int ptr=1;
	for(int i=1; i<=m ;i++){
		while(!v.empty() && v.back().se>=b[i].se) v.pop_back();
		while(ptr<=n && b[i].fi>a[ptr]) ptr++;
		if(ptr<=n && b[i].fi<=a[ptr] && a[ptr]<=b[i].se) continue;
		else{
			v.push_back(b[i]);
			king[v.size()-1]=ptr;
		}
	}
	a[0]=-1e18;
	a[n+1]=1e18;
	for(int i=0; i<v.size() ;i++){
		//cout << v[i].fi << ' ' << v[i].se << ' ' << king[i] << endl;
		if(i==0){
			dp1[i]=a[king[i]]-v[i].se;
			dp2[i]=2*dp1[i];
			dp3[i]=v[i].fi-a[king[i]-1];
			dp4[i]=2*dp3[i];
		}
		else if(king[i]==king[i-1]){
			dp1[i]=min(dp1[i-1],min(dp3[i-1],dp4[i-1])+a[king[i]]-v[i].se);
			dp2[i]=min(dp2[i-1],min(dp3[i-1],dp4[i-1])+2*(a[king[i]]-v[i].se));
			dp3[i]=dp3[i-1]+v[i].fi-v[i-1].fi;
			dp4[i]=dp4[i-1]+2*(v[i].fi-v[i-1].fi);
		}
		else if(king[i]==king[i-1]+1){
			ll queen=min(min(dp1[i-1],dp2[i-1]),min(dp3[i-1],dp4[i-1]));
			dp1[i]=a[king[i]]-v[i].se;
			dp2[i]=2*dp1[i];
			dp3[i]=v[i].fi-a[king[i]-1];
			dp4[i]=2*dp3[i];
			dp1[i]+=queen;dp2[i]+=queen;dp3[i]+=queen;dp4[i]+=queen;
			dp3[i]=v[i].fi-a[king[i]-1]+min(min(dp2[i-1],dp3[i-1]),dp4[i-1]);
		}
		else{
			ll queen=min(min(dp1[i-1],dp2[i-1]),min(dp3[i-1],dp4[i-1]));
			dp1[i]=a[king[i]]-v[i].se;
			dp2[i]=2*dp1[i];
			dp3[i]=v[i].fi-a[king[i]-1];
			dp4[i]=2*dp3[i];
			dp1[i]+=queen;dp2[i]+=queen;dp3[i]+=queen;dp4[i]+=queen;
		}
		
	}
	int i=v.size();
	ll queen=min(min(dp1[i-1],dp2[i-1]),min(dp3[i-1],dp4[i-1]));
	cout << queen << '\n';
	//cout << endl << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}