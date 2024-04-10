#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
char c[1001][1001];
void solve(){
	cin >> n >> m;
	if(m*2>n+1){
		cout << "-1\n";
		return;
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			c[i][j]='.';
		}
	}
	for(int i=1; i<=m ;i++){
		c[i*2-1][i*2-1]='R';
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			cout << c[i][j];
		}
		cout << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--) solve();
}