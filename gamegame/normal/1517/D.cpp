#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
int n,m,k;
int dp[2][501][501];
int v[501][501];
int h[501][501];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m >> k;
	if(k%2!=0){
		for(int i=1; i<=n ;i++){
			for(int j=1; j<=m ;j++){
				cout << "-1 ";
			}
			cout << '\n';
		}
		return 0;
	}
	k/=2;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m-1 ;j++){
			cin >> h[i][j];
		}
	}
	for(int i=1; i<=n-1 ;i++){
		for(int j=1; j<=m ;j++){
			cin >> v[i][j];
		}
	}
	//cout << k << endl;
	for(int z=1; z<=k ;z++){
		int c=z%2;
		int p=c^1;
		for(int i=1; i<=n ;i++){
			for(int j=1; j<=m ;j++){
				int x=1e9;
				if(j!=m){
					x=min(x,dp[p][i][j+1]+h[i][j]);
				}
				if(j!=1){
					x=min(x,dp[p][i][j-1]+h[i][j-1]);
				}
				if(i!=1){
					x=min(x,dp[p][i-1][j]+v[i-1][j]);
				}
				if(i!=n){
					x=min(x,dp[p][i+1][j]+v[i][j]);
				}
				dp[c][i][j]=x;
			}
		}
		//cout << dp[c][1][1] << endl;
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cout << dp[k&1][i][j]*2 << ' ';
		}
		cout << '\n';
	}
}