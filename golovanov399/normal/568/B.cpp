#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;

const int N = 4444;
int c[N][N];
long long f[N];

int main(){

	c[0][0] = 1;
	for (int i = 1; i < N; i++){
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			c[i][j] %= mod;
		}
	}
	f[0] = 1;
	for (int i = 1; i < N; i++){
		for (int j = 0; j < i; j++){
			f[i] += f[i - j - 1] * c[i - 1][j];;
			f[i] %= mod;
		}
	}

	int n = nxt();
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		ans += 1ll * c[n][i] * f[n - i];
		ans %= mod;
	}
	cout << ans << "\n";

	return 0;
}