#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
int n,m;
map<ll,int>mp[21];
ll a[21][21];
int main(){
	ios::sync_with_stdio(false);
	ll k;
	cin >> n >> m >> k;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> a[i][j];
		}
	}
	for(int i=0; i<(1<<(n-1)) ;i++){
		int sx=1,sy=1;
		ll v=a[1][1];
		for(int j=0; j<n-1 ;j++){
			if(i&(1<<j)) sy++;
			else sx++;
			v^=a[sx][sy];
		}
		if(sx>n || sy>m) continue;
		mp[sx][v]++;
	}
	ll ans=0;
	for(int i=0; i<(1<<(m-1)) ;i++){
		int sx=n,sy=m;
		ll v=a[n][m];
		for(int j=0; j<m-1 ;j++){
			if(i&(1<<j)) sy--;
			else sx--;
			v^=a[sx][sy];
		}
		if(sx<1 || sy<1) continue;
		ans+=mp[sx][v^k^a[sx][sy]];
	}
	cout << ans << endl;
	
	
}