#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e6+1;
ll n,m;
ll a[100001];
ll cnt[61];
ll cnt2[61];
void solve(){
	cin >> n >> m;
	for(int i=0; i<=60 ;i++) cnt[i]=0;
	for(int i=1; i<=m ;i++){
		cin >> a[i];
		for(int j=0; j<=30 ;j++){
			if(a[i]==(1<<j)) cnt[j]++;
		}
	}
	ll ans=0;
	bool req=false;
	for(int j=0; j<=60 ;j++){
		if(n&1){
			if(cnt[j]==0){
				if(!req){
					ans-=j;req=true;
				}
			}
			else cnt[j]--;
		}
		if(cnt[j]>0 && req){
			ans+=j;req=false;
			cnt[j]--;
		}
		cnt[j+1]+=cnt[j]/2;
		n/=2;
	}
	if(n || req) cout << "-1\n";
	else cout << ans << '\n';
	
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}