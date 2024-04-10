#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
int n, p[maxn], cntp[maxn][maxn], cnts[maxn][maxn];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for(int x = 1; x <= n; x++){
		cntp[0][x] = cnts[n + 1][x] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int x = 1; x <= n; x++){
			cntp[i][x] = cntp[i - 1][x];
			if(x >= p[i])cntp[i][x]++;
		}
	}
	for(int i = n; i >= 1; i--){
		for(int x = 1; x <= n; x++){
			cnts[i][x] = cnts[i + 1][x];
			if(x >= p[i])cnts[i][x]++;
		}
	}
	long long ans = 0;
	for(int b = 1; b <= n; b++){
		for(int c = b + 1; c <= n; c++){
			ans += cntp[b - 1][p[c]]*cnts[c + 1][p[b]];
		}
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}