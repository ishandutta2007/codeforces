#include <bits/stdc++.h>
using namespace std;

const int N = 3000005;
bool dp[N];

inline int solve(int a, int b, int h, int w, vector<int> mul){
	int k1 = (a + h - 1)/h;
	int k2 = (b + w - 1)/w;
	if(k1 == 1 && k2 == 1)return 0;
	if((int)mul.size() <= 18){
		__int128 total = 1;
		for(int m = 1; m <= (int)mul.size(); m++){
			total *= mul[m - 1];
			for(int mask = 0; mask < (1 << m); mask++){
				__int128 prod = 1;
				for(int i = 0; i < m; i++){
					if((mask >> i) & 1)prod *= mul[i];
				}
				if(prod >= k1 && total/prod >= k2)return m;
				if(prod >= k2 && total/prod >= k1)return m;
			}
		}
		return 1e9;
	}
	memset(dp, false, sizeof(dp)); dp[1] = true;
	for(int m = 1; m <= (int)mul.size(); m++){
		for(int x = (N - 1)/mul[m - 1]; x >= 1; x--){
			if(dp[x])dp[x*mul[m - 1]] = true;
		}
		__int128 total = 1;
		for(int i = 0; i < m; i++){
			total *= mul[i];
		}
		for(int i = 1; i < N; i++){
			if(dp[i]){
				if(i >= k1 && total/i >= k2)return m;
				if(i >= k2 && total/i >= k1)return m;
			}
		}
	}
	return 1e9;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, h, w, n;
	cin >> a >> b >> h >> w >> n;
	vector<int> mul(n);
	for(int &x : mul){
		cin >> x;
	}
	sort(mul.rbegin(), mul.rend());
	{
		long double prd = 1;
		for(int i = 0; i < n; i++){
			prd *= mul[i];
			if(prd > 1e15){
				mul.resize(i + 1);
				break;
			}
		}
	}
	int ans = min(solve(a, b, h, w, mul), solve(a, b, w, h, mul));
	if(ans > n)cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}