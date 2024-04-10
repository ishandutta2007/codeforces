#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
ll a[N],w[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> w[i];
	}
	sort(w+1,w+n+1);
	int ans=0;
	for(int i=1; i<=n ;i++){
		for(int j=i+1; j<=n ;j++){
			ll c=w[i]+w[j];
			int r=j-1;
			int l=i+1;
			int cnt=1;
			while(l<r){
				if(w[l]+w[r]==c){
					cnt++;l++;r--;
				}
				else if(w[l]+w[r]<c) l++;
				else r--;
			}
			ans=max(ans,cnt);
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
	
}