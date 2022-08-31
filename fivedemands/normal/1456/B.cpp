#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
int n;
ll a[N];
ll dp[101][101];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	if(n>100){
		cout << "1\n";
		return 0;
	}
	dp[0][0]=0;
	int ans=1e9;
	for(int i=1; i<n ;i++){
		ll xl=0,xr=0;
		for(int j=i; j>=1 ;j--){
			xl^=a[j];
			xr=0;
			for(int k=i+1; k<=n ;k++){
				xr^=a[k];
				if(xl>xr){
					ans=min(ans,i-j+k-i-1);
				}
			}
		}
	}
	if(ans>n) cout << "-1\n";
	else cout << ans << '\n';
}