#include <bits/stdc++.h>
using namespace std;

const int logr = 65;
const int maxn = 1005;
const int mod = 1000*1000*1000 + 7;

int ncr[maxn][maxn], dp[logr][maxn];

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

inline void init(){
	memset(ncr, 0, sizeof(ncr));
	for(int n = 0; n < maxn; n++){
		ncr[n][0] = 1;
		for(int r = 1; r <= n; r++){
			ncr[n][r] = ncr[n - 1][r];
			add(ncr[n][r], ncr[n - 1][r - 1]);
		}
	}
}

int f(int i, int n, int carry, long long r, long long z){
	if(r == 0)return (z == 0);
	if(dp[i][carry] != -1)return dp[i][carry];
	
	int b = z&1;
	int ret = 0;
	for(int k = b; k <= n; k += 2){
		int ncarry = carry + k;
		if(r%2 == 0){
			ncarry += (r^ncarry)&1;
		}
		if(ncarry > r)break;
		add(ret, 1LL*ncr[n][k]*f(i + 1, n, ncarry >> 1, r >> 1, z >> 1)%mod);
	}
	return dp[i][carry] = ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	int n; cin >> n;
	long long l; cin >> l;
	long long r; cin >> r;
	long long z; cin >> z;

	int ans = 0;
	{
		memset(dp, -1, sizeof(dp));
		add(ans, f(0, n, 0, r, z));
	}
	{
		memset(dp, -1, sizeof(dp));
		add(ans, mod - f(0, n, 0, l - 1, z));
	}
	cout << ans << '\n';

	return 0;
}