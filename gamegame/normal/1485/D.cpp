#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll a[501][501],b[501][501];
//ll a[N],b[N];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> a[i][j];
			int x=a[i][j];
			if((i+j)%2==0) b[i][j]=720720;
			else b[i][j]=720720-x*x*x*x;
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	solve();
	//int t;cin >> t;while(t--) solve();
}