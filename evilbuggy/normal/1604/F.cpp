#include <bits/stdc++.h>
using namespace std;

const int logN = 18;
const int maxD = 805;
const int maxN = 100005;

long long f[maxN], dp[logN][maxN];
int lpf[maxN], sz[maxN], phi[maxN];

long long cost(int l, int r){
	if(l > r)return 0;
	long long ret = 0;
	while(l <= r){
		int nl = 1 + r/(r/l);
		ret += f[r/l]*(nl - l); l = nl;
	}
	return ret;
}

void dnc(int k, int l, int r, int optl, int optr){
	if(l > r)return;
	int m = (l + r)/2;
	int optm = min(m, optr);
	long long curdp = LLONG_MAX;
	long long curcost = cost(optm + 1, m);
	for(int i = optm; i >= optl; i--){
		curcost += f[m/i];
		if(dp[k - 1][i - 1] + curcost < curdp){
			curdp = dp[k - 1][i - 1] + curcost;
			optm = i;
		}
	}
	dp[k][m] = curdp;
	dnc(k, l, m - 1, optl, optm);
	dnc(k, m + 1, r, optm, optr);
}

void init(){
	memset(lpf, -1, sizeof(lpf));
	for(int i = 2; i*i < maxN; i++){
		if(lpf[i] == -1){
			for(int j = i*i; j < maxN; j += i){
				if(lpf[j] == -1)lpf[j] = i;
			}
		}
	}
	phi[1] = 1;
	for(int i = 2; i < maxN; i++){
		if(lpf[i] == -1)lpf[i] = i;
		if((i/lpf[i])%lpf[i] == 0){
			phi[i] = phi[i/lpf[i]]*lpf[i];
		}else{
			phi[i] = phi[i/lpf[i]]*(lpf[i] - 1);
		}
	}
	f[0] = 0;
	for(int i = 1; i < maxN; i++){
		f[i] = f[i - 1] + phi[i];
	}
	memset(dp, 0x1f, sizeof(dp)); dp[1][0] = 0;
	for(int i = 1; i < maxN; i++){
		dp[1][i] = 1LL*i*(i + 1)/2;
	}
	for(int k = 2; k < logN; k++){
		dnc(k, 1, maxN - 1, 1, maxN - 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		if(k < logN){
			cout << dp[k][n] << '\n';
		}else{
			cout << n << '\n';
		}
	}

	return 0;
}