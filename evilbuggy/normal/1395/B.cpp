#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n, m, x, y;
	cin>>n>>m>>x>>y;
	cout<<x<<" "<<y<<'\n';
	for(int i = 1; i <= n; i++){
		if(i != x)cout<<i<<" "<<y<<'\n';
	}
	int cur = n;
	for(int j = 1; j <= m; j++){
		if(j == y)continue;
		if(cur == n){
			for(int i = n; i >= 1; i--){
				cout<<i<<" "<<j<<'\n';
			}
			cur = 1;
		}else{
			for(int i = 1; i <= n; i++){
				cout<<i<<" "<<j<<'\n';
			}
			cur = n;
		}
	}

	return 0;
}