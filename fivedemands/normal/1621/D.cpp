#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll c[505][505];
ll d[505][505];
ll work(){
	ll res=1e18;
	for(int i=1; i<=2*n ;i++){
		for(int j=1; j<=2*n ;j++){
			d[i][j]=1e18;
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=n+1; j<=2*n ;j++){
			d[i][j]=min(d[i][j],d[i][j-1]+c[i][j]);
		}
		d[i][2*n]=c[i][2*n];
		for(int j=2*n-1; j>n ;j--){
			d[i][j]=min(d[i][j],d[i][j+1]+c[i][j]);
		}
	}
	for(int i=n+1; i<=2*n ;i++){
		for(int j=2; j<=n ;j++){
			d[j][i]=min(d[j][i],d[j-1][i]+c[j][i]);
		}
		for(int j=n-1; j>=1 ;j--){
			d[j][i]=min(d[j][i],d[j+1][i]+c[j][i]);
		}
		res=min(res,d[1][i]);
		res=min(res,d[n][i]);
	}
	return res;
}
void solve(){
	cin >> n;
	ll ans=0;
	ll ext=1e18;
	for(int i=1; i<=2*n ;i++){
		for(int j=1; j<=2*n ;j++){
			cin >> c[i][j];
			if(i<=n && j<=n || i>n && j>n){	
				ans+=c[i][j];c[i][j]=0;
			}
			if((i==n+1 || i==2*n) && (j==1 || j==n)) ext=min(ext,c[i][j]);
			if((j==n+1 || j==2*n) && (i==1 || i==n)) ext=min(ext,c[i][j]);
			d[i][j]=1e18;
		}
	}
	cout << (ans+ext) << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--) solve();
}