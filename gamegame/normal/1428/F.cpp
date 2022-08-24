#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,k;
char c[N];
vector<pair<int,int> >v[N];
ll sum(ll l,ll r){
	return r*(r+1)/2-(l-1)*l/2;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> c[i];
	}
	for(int i=1; i<=n ;i++){
		if(c[i]=='1'){
			int l=i,r=i;
			while(r<n && c[r+1]=='1') r++;
			i=r;
			for(int j=1; j<=r-l+1 ;j++) v[j].push_back({l,r});
		}
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		v[i].push_back({n+1,n+i});
		int prv=-1;
		for(int j=0; j<v[i].size() ;j++){
			auto c=v[i][j];
			int l=c.fi,r=c.se;
			if(l>n) break;
			ll x=l+i-1;
			//cout << "! " << x << ' ' << r << endl;
			ans+=sum(x,r)-1LL*(i-1)*(r-l+1-i+1);
			prv=r-i+1;
			ll nxt=min((int)n,v[i][j+1].fi+i-2);
			ans+=(nxt-r)*prv;
		}
	}
	cout << ans << '\n';
}