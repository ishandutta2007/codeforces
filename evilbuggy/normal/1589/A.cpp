#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int u, v;
		cin >> u >> v;
		cout << 1LL*u*u << " " << -1LL*v*v << '\n';
	}

	return 0;
}