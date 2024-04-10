#include <bits/stdc++.h>
using namespace std;

const int mod = 31607;
const int inv = 3973;

const int N = 21;

int inverse(int n){
	if(n == 1)return 1;
	return inverse(mod%n)*(mod - mod/n)%mod;
}

short int n, a[N][N], row[N], col[N][1 << N], arr[N][1 << N], bit[1 << N];

inline int compute00(){
	int ret = 0;
	for(int i = 0; i < n; i++){
		row[i] = 1;
		for(int j = 0; j < n; j++){
			row[i] = int(row[i])*a[i][j]%mod;
		}
	}
	for(int mask = 1; mask < (1 << n); mask++){
		for(int i = 0; i < n; i++){
			if((mask >> i) & 1){
				bit[mask] = i;
				break;
			}
		}
	}
	for(int i = 0; i < n; i++){
		col[i][0] = 1;
		for(int mask = 1; mask < (1 << n); mask++){
			int b = bit[mask];
			col[i][mask] = int(col[i][mask^(1 << b)])*a[b][i]%mod;
		}
	}
	int MASK = (1 << n) - 1;
	for(int mask = 0; mask < (1 << n); mask++){
		int prod = 1;
		for(int i = 0; i < n; i++){
			(prod *= (mod + 1 - col[i][MASK^mask])) %= mod;
		}
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if((mask >> i) & 1){
				(prod *= row[i]) %= mod;
				cnt++;
			}
		}
		if(cnt&1)ret += mod - prod;
		else ret += prod;

		if(ret >= mod)ret -= mod;
	}
	ret += mod - 1; if(ret >= mod)ret -= mod;
	return ret;
}

inline int compute01(){
	int ret = 0;
	for(int i = 0; i < n; i++){
		row[i] = 1;
		for(int j = 0; j < n; j++){
			if(i == j)continue;
			row[i] = int(row[i])*a[i][j]%mod;
		}
	}
	int MASK = (1 << n) - 1;
	for(int mask = 0; mask < (1 << n); mask++){
		int prod = 1;
		for(int i = 0; i < n; i++){
			(prod *= (mod + 1 - col[i][MASK^(mask|(1 << i))])) %= mod;
		}
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if((mask >> i) & 1){
				(prod *= row[i]) %= mod;
				cnt++;
			}
		}
		if(cnt&1)ret += mod - prod;
		else ret += prod;

		if(ret >= mod)ret -= mod;
	}
	for(int i = 0; i < n; i++){
		(ret *= a[i][i]) %= mod;
	}
	return ret;
}

inline int compute10(){
	int ret = 0;
	for(int i = 0; i < n; i++){
		row[i] = 1;
		for(int j = 0; j < n; j++){
			if(i + j == n - 1)continue;
			row[i] = int(row[i])*a[i][j]%mod;
		}
	}
	int MASK = (1 << n) - 1;
	for(int mask = 0; mask < (1 << n); mask++){
		int prod = 1;
		for(int i = 0; i < n; i++){
			(prod *= (mod + 1 - col[i][MASK^(mask|(1 << (n - 1 - i)))])) %= mod;
		}
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if((mask >> i) & 1){
				(prod *= row[i]) %= mod;
				cnt++;
			}
		}
		if(cnt&1)ret += mod - prod;
		else ret += prod;

		if(ret >= mod)ret -= mod;
	}
	for(int i = 0; i < n; i++){
		(ret *= a[i][n - 1 - i]) %= mod;
	}
	return ret;
}

inline int compute11(){
	int ret = 0;
	for(int i = 0; i < n; i++){
		row[i] = 1;
		for(int j = 0; j < n; j++){
			if(i == j || i + j == n - 1)continue;
			row[i] = int(row[i])*a[i][j]%mod;
		}
	}
	int MASK = (1 << n) - 1;
	for(int mask = 0; mask < (1 << n); mask++){
		int prod = 1;
		for(int i = 0; i < n; i++){
			(prod *= (mod + 1 - col[i][MASK^(mask|(1 << i)|(1 << (n - 1 - i)))])) %= mod;
		}
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if((mask >> i) & 1){
				(prod *= row[i]) %= mod;
				cnt++;
			}
		}
		if(cnt&1)ret += mod - prod;
		else ret += prod;

		if(ret >= mod)ret -= mod;
	}
	for(int i = 0; i < n; i++){
		(ret *= a[i][i]) %= mod;
		if(i != n - 1 - i)(ret *= a[i][n - 1 - i]) %= mod;
	}
	return ret;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			a[i][j] = int(a[i][j])*inv%mod;
		}
	}
	int ans = compute00() + mod - compute01() + mod - compute10() + compute11(); ans %= mod;
	if(ans != 0)ans = mod - ans;
	cout << ans << '\n';


	return 0;
}