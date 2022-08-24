#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[501][501];
int b[501][501];
int g[501];
ll re[501];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n ;i++){
		cin >> g[i];
	}
	for(int i=1; i<=n/2 ;i++){
		swap(g[i],g[n-i+1]);
	}
	for(int k=1; k<=n ;k++){
		for(int i=1; i<=n ;i++){
			for(int j=1; j<=n ;j++){
				a[i][j]=min(a[i][j],a[i][g[k]]+a[g[k]][j]);
			}
		}
		ll ans=0;
		for(int i=1; i<=k ;i++){
			for(int j=1; j<=k ;j++){
				ans+=a[g[i]][g[j]];
			}
		}
		re[n-k+1]=ans;
	}
	for(int i=1; i<=n ;i++) cout << re[i] << ' ';
}