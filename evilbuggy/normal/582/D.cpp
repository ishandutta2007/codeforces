#include <bits/stdc++.h>
using namespace std;

const int N = 3555;
const int mod = 1000000007;

vector<long long> dig;
int p, alpha, dp[2][N][2][2];

inline void mulandadd(int mul, int add){
	for(auto &x : dig){
		x *= mul;
	}
	dig[0] += add;
	long long carry = 0;
	for(auto &x : dig){
		carry += x;
		x = carry%p;
		carry /= p;
	}
	while(carry > 0){
		dig.emplace_back(carry%p);
		carry /= p;
	}
}

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

inline int count(int l, int r){
	if(l < 0)l = 0;
	if(l > r)return 0;
	if(r < p){
		long long ret = (r - l + 1)*1LL*(r + l + 2)/2;
		return ret%mod;
	}
	if(l >= p){
		r = 2*p - 2 - r;
		l = 2*p - 2 - l;
		long long ret = (l - r + 1)*1LL*(l + r + 2)/2;
		return ret%mod;
	}
	int ret = count(l, p - 1) + count(p, r);
	if(ret >= mod)ret -= mod;
	return ret;
}

inline void process(int i, int flg, int nc, int co, int lim, int val){
	if(!val)return;
	if(co == 0){
		// no carry into
		if(lim){
			add(dp[flg][nc][0][0], count(0, dig[i] - 1)*1LL*val%mod);
			add(dp[flg][nc][0][1], count(dig[i], dig[i])*1LL*val%mod);
		}else{
			add(dp[flg][nc][0][0], count(0, p - 1)*1LL*val%mod);
		}
		// carry into
		if(lim){
			add(dp[flg][nc + 1][1][0], count(0, dig[i] - 2)*1LL*val%mod);
			add(dp[flg][nc + 1][1][1], count(dig[i] - 1, dig[i] - 1)*1LL*val%mod);
		}else{
			add(dp[flg][nc + 1][1][0], count(0, p - 2)*1LL*val%mod);
		}
	}else{
		// no carry into
		if(lim){
			add(dp[flg][nc][0][0], count(p, p + dig[i] - 1)*1LL*val%mod);
			add(dp[flg][nc][0][1], count(p + dig[i], p + dig[i])*1LL*val%mod);
		}else{
			add(dp[flg][nc][0][0], count(p, 2*p - 2)*1LL*val%mod);
		}
		//carry into
		if(lim){
			add(dp[flg][nc + 1][1][0], count(p - 1, p + dig[i] - 2)*1LL*val%mod);
			add(dp[flg][nc + 1][1][1], count(p + dig[i] - 1, p + dig[i] - 1)*1LL*val%mod);
		}else{
			add(dp[flg][nc + 1][1][0], count(p - 1, 2*p - 2)*1LL*val%mod);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> p >> alpha;
	string A;
	cin >> A;
	int len = (int)A.size();
	dig = vector<long long>(1, 0);
	for(int i = 0; i < len; i += 7){
		int val = 0, mul = 1;
		for(int j = 0; j < 7 && i + j < len; j++){
			val = val*10 + (A[i + j] - '0');
			mul *= 10;
		}
		mulandadd(mul, val);
	}
	int n = (int)dig.size();
	if(alpha >= n){
		cout << 0 << '\n';
		exit(0);
	}
	int flg = 0;
	memset(dp, 0, sizeof(dp));
	reverse(dig.begin(), dig.end());
	dp[0][0][0][1] = 1;
	for(int i = 0; i < n; i++){
		int nflg = flg^1;
		memset(dp[nflg], 0, sizeof(dp[nflg]));
		for(int nc = 0; nc <= n; nc++){
			for(int co = 0; co <= 1; co++){
				for(int lim = 0; lim <= 1; lim++){
					process(i, nflg, nc, co, lim, dp[flg][nc][co][lim]);
				}
			}
		}
		flg = nflg;
	}
	int answer = 0;
	for(int nc = alpha; nc <= n; nc++){
		for(int lim = 0; lim <= 1; lim++){
			add(answer, dp[flg][nc][0][lim]);
		}
	}
	cout << answer << '\n';

	return 0;
}