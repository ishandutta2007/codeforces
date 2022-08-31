#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define fi first
#define se second
const int N=1001;
const int iu=2e5;
ll n,m,k;
int a[N][N];

void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			char c;cin >> c;
			a[i][j]=c-48;
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			char c;cin >> c;
			a[i][j]^=c-48;
		}
	}
	for(int i=2; i<=n ;i++){
		for(int j=2; j<=n ;j++){
			int x=a[1][1]^a[1][j]^a[i][1]^a[i][j];
			if(x!=0){
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}