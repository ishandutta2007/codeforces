#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> f(201);
	vector<int> g(201);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		f[x + 100]++;
	}
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		g[x + 100]++;
	}
	int cur = 0;
	for(int i = 0; i < 201; i++){
		if(cur > g[i] || cur + f[i] < g[i]){
			cout << "NO" << '\n';
			return;
		}
		cur = cur + f[i] - g[i];
	}
	cout << "YES" << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}