#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const int k=6;
ll n,m;
ll a[N],b[N];
ll f[N];
pair<ll,int>s[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	for(int i=1; i<=k ;i++) cin >> a[i];
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		for(int j=1; j<=k ;j++){
			s[6*(i-1)+j]={b[i]-a[j],i};
		}
	}
	sort(s+1,s+6*n+1);
	int r=0;
	int hv=0;
	ll ans=1e9;
	for(int i=1; i<=6*n ;i++){
		while(r<6*n && hv!=n){
			++r;
			if(f[s[r].se]++==0) hv++;
		}
		if(hv!=n) break;
		ans=min(ans,s[r].fi-s[i].fi);
		hv-=(--f[s[i].se])==0;
	}
	cout << ans << '\n';
}