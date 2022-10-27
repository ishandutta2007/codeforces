#include <bits/stdc++.h>
using namespace std;

const int maxK = 111;
const int maxN = 2222;
const int mod = 998244353;

int fac[maxN], ifac[maxN], inv[maxN];
int L[maxN], R[maxN], f[2][maxN][maxN], g[2][maxN][maxN];

void init(){
	inv[1] = 1;
	fac[0] = ifac[0] = 1;
	fac[1] = ifac[1] = 1;
	for(int i = 2; i < maxN; i++){
		fac[i] = i*1LL*fac[i - 1]%mod;
		inv[i] = (mod - mod/i)*1LL*inv[mod%i]%mod;
		ifac[i] = ifac[i - 1]*1LL*inv[i]%mod;
	}
}

inline int npr(int n, int r){
	if(r < 0 || r > n)return 0;
	return fac[n]*1LL*ifac[n - r]%mod;
}

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int N, K;
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		int x;
		cin >> x;
		L[i] = x - K;
		R[i] = x + K;
		if(L[i] < 0)L[i] = 0;
	}
	L[0] = R[0] = 0;
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));

	int flg = 0;
	f[flg][0][0] = 1;
	g[flg][0][0] = 1;
	for(int i = 1; i <= N; i++){
		int nlg = flg^1;
		for(int d = 0; d <= i; d++){
			for(int y = L[i]; y <= R[i]; y++){
				f[nlg][d][y] = 0;
				if(L[i - 1] <= y && y <= R[i - 1]){
					add(f[nlg][d][y], 1LL*(d + y)*f[flg][d][y]%mod);
					if(d > 0){
						add(f[nlg][d][y], f[flg][d - 1][y]);
					}
				}
				if(y > L[i - 1]){
					int ny = min(y - 1, R[i - 1]);
					int nd = d + y - 1 - ny;
					add(f[nlg][d][y], 1LL*ifac[d]*g[flg][nd][ny]%mod);
				}
			}
		}
		for(int d = i; d >= 0; d--){
			for(int y = L[i]; y <= R[i]; y++){
				g[nlg][d][y] = fac[d]*1LL*f[nlg][d][y]%mod;
				if(y > L[i]){
					add(g[nlg][d][y], g[nlg][d + 1][y - 1]);
				}
			}
		}
		flg = nlg;
	}
	
	int answer = 0;
	for(int d = 0; d <= N; d++){
		for(int x = L[N]; x <= R[N]; x++){
			if(N - x >= d)add(answer, npr(N - x, d)*1LL*f[flg][d][x]%mod);
		}
	}
	cout << answer << '\n';

	return 0;
}