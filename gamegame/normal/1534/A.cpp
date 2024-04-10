#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
ll n,m;
ll a[N],b[N];
char c[51][51];
char d[51][51];
char e[51][51];
int cnt[2][226];
void solve(){
	cin >> n >> m;
	bool okd=true;
	bool oke=true;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> c[i][j];
			if((i+j)%2==0) d[i][j]='R',e[i][j]='W';
			else d[i][j]='W',e[i][j]='R';
			if(c[i][j]!='.' && c[i][j]!=d[i][j]) okd=false;
			if(c[i][j]!='.' && c[i][j]!=e[i][j]) oke=false;
		}
	}
	if(okd){
		cout << "YES\n";
		for(int i=1; i<=n ;i++){
			for(int j=1; j<=m ;j++) cout << d[i][j];
			cout << '\n';
		}
	}
	else if(oke){
		cout << "YES\n";
		for(int i=1; i<=n ;i++){
			for(int j=1; j<=m ;j++) cout << e[i][j];
			cout << '\n';
		}
	}
	else cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}