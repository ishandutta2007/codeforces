#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	int n, m, ans = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i += 1){
		int pans = 1e9;
		for(int j = 0; j < m; j += 1){
			int x;
			cin >> x;
			pans = min(pans, x);
		}
		ans = max(ans, pans);
	}
	cout << ans;
}