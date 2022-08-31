#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define fi first
#define se second
const int N=2e6+1;
ll n,m,k;
ll a[N],b[N];
ll c[N],d[N];
const int iu=1000;
ll C[iu+1][iu+1];
void init(){
	C[0][0]=1;
	for(int i=1; i<=iu ;i++){
		C[i][0]=1;
		for(int j=1; j<=i ;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int k=m;
	int l=k,r=k;
	while(l>1 && a[l-1]==a[k]) l--;
	while(r<n && a[r+1]==a[k]) r++;
	cout << C[r-l+1][m-l+1] << '\n';
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	init();
	int t;cin >> t;while(t--) solve();
}