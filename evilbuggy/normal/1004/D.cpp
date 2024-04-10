#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int t, f[N], g[N];

inline bool check(int n, int m, int x, int y){
	if(n*1LL*m != t)return false;
	if(x < 1 || y < 1 || x > n || y > m)return false;
	memset(g, 0, sizeof(g));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int dist = abs(x - i) + abs(y - j);
			if(f[dist] == g[dist])return false;
			g[dist]++;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= t; i++){
		int x; cin >> x; f[x]++;
	}
	if(f[0] != 1){
		cout << -1 << '\n';
		exit(0);
	}
	int mx = 0, x = 0;
	for(int i = 1; i <= t; i++){
		if(f[i] != 4*i){
			x = i;
			break;
		}
	}
	for(int i = 1; i <= t; i++){
		if(f[i]){
			mx = i;
		}
	}
	for(int n = 2*x - 1; n <= t; n++){
		if(t%n)continue;
		int m = t/n;
		int y = n + m - x - mx;
		if(2*y - 1 <= m && check(n, m, x, y)){
			cout << n << " " << m << '\n';
			cout << x << " " << y << '\n';
			exit(0);
		}
	}
	cout << -1 << '\n';

	return 0;
}