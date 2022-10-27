#include <bits/stdc++.h>
using namespace std;

const int N = 255;
const int mod = 998244353;

int dp1[N][N][N];
int dp2[N][N][N];
int dp3[N][N][N];
int ncr[N][N], uwu[N][N], fac[N], ans[N];

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

void init(){
	memset(ncr, 0, sizeof(ncr));
	for(int n = 0; n < N; n++){
		ncr[n][0] = 1;
		for(int r = 1; r <= n; r++){
			ncr[n][r] = ncr[n - 1][r];
			add(ncr[n][r], ncr[n - 1][r - 1]);
		}
	}
	fac[0] = 1;
	for(int n = 1; n < N; n++){
		fac[n] = n*1LL*fac[n - 1]%mod;
	}
	memset(uwu, 0, sizeof(uwu));
	uwu[0][0] = 1;
	for(int n = 1; n < N; n++){
		for(int c = 1; c <= n; c++){
			for(int r = 0; r < n; r++){
				int tmp = uwu[n - 1 - r][c - 1]*1LL*ncr[n - 1][r]%mod;
				tmp = tmp*1LL*fac[r]%mod;
				add(uwu[n][c], tmp);
			}
		}
	}
}

inline int reduce(vector<int> &p, vector<int> &q){
	int n = (int)p.size();
	int indp = -1, indq = -1;
	for(int i = 0; i < n; i++){
		if(p[i] == 0)continue;
		for(int j = 0; j < n; j++){
			if(p[i] == q[j]){
				indp = i;
				indq = j;
				break;
			}
		}
		if(indp != -1)break;
	}
	if(indp == -1)return -1;
	if(indp == indq){
		vector<int> np, nq;
		for(int i = 0; i < n; i++){
			if(i == indp)continue;
			np.emplace_back(p[i]);
			nq.emplace_back(q[i]);
		}
		p = np; q = nq;
		return 1;
	}
	vector<int> np, nq;
	np.emplace_back(p[indq]);
	nq.emplace_back(q[indp]);
	for(int i = 0; i < n; i++){
		if(i == indp || i == indq)continue;
		np.emplace_back(p[i]);
		nq.emplace_back(q[i]);
	}
	p = np; q = nq;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> q(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	for(int i = 0; i < n; i++){
		cin >> q[i];
	}
	int cycles = 0;
	while(true){
		int tmp = reduce(p, q);
		if(tmp == -1)break;
		cycles += tmp;
	}
	int m = (int)p.size();
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, empty = 0;
	for(int i = 0; i < m; i++){
		if(p[i] != 0 && q[i] == 0){
			cnt1++;
		}else if(p[i] == 0 && q[i] != 0){
			cnt2++;
		}else if(p[i] != 0 && q[i] != 0){
			cnt3++;
		}
	}
	empty = m - cnt1 - cnt2 - 2*cnt3;
	memset(dp1, 0, sizeof(dp1));
	dp1[cnt1][empty][cycles] = 1;
	for(int t = cnt1; t > 0; t--){
		for(int e = empty; e >= 0; e--){
			for(int c = cycles; c <= n; c++){
				if(dp1[t][e][c] == 0)continue;
				add(dp1[t - 1][e][c], dp1[t][e][c]*1LL*(t - 1)%mod);
				add(dp1[t - 1][e][c + 1], dp1[t][e][c]);
				add(dp1[t - 1][e][c], (cnt3 + empty - e)*1LL*dp1[t][e][c]%mod);
				if(e > 0)add(dp1[t - 1][e - 1][c], e*1LL*dp1[t][e][c]%mod);
			}
		}
	}
	memset(dp2, 0, sizeof(dp2));
	for(int e = 0; e <= empty; e++){
		for(int c = cycles; c <= n; c++){
			dp2[cnt2][e][c] = dp1[0][e][c];
		}
	}
	for(int t = cnt2; t > 0; t--){
		for(int e = empty; e >= 0; e--){
			for(int c = cycles; c <= n; c++){
				if(dp2[t][e][c] == 0)continue;
				add(dp2[t - 1][e][c], dp2[t][e][c]*1LL*(t - 1)%mod);
				add(dp2[t - 1][e][c + 1], dp2[t][e][c]);
				add(dp2[t - 1][e][c], (cnt3 + empty - e)*1LL*dp2[t][e][c]%mod);
				if(e > 0)add(dp2[t - 1][e - 1][c], e*1LL*dp2[t][e][c]%mod);
			}
		}
	}
	memset(dp3, 0, sizeof(dp3));
	for(int e = 0; e <= empty; e++){
		for(int c = cycles; c <= n; c++){
			if(dp2[0][e][c] == 0)continue;
			dp3[cnt3 + empty - e][e][c] = dp2[0][e][c];
		}
	}
	for(int t = cnt3 + empty; t > 0; t--){
		for(int e = empty; e >= 0; e--){
			for(int c = cycles; c <= n; c++){
				if(dp3[t][e][c] == 0)continue;
				add(dp3[t - 1][e][c + 1], (t + e)*1LL*dp3[t][e][c]%mod);
				add(dp3[t - 1][e][c], ((t - 1)*(t + e))*1LL*dp3[t][e][c]%mod);
				if(e > 0)add(dp3[t][e - 1][c], ((t + e)*e)*1LL*dp3[t][e][c]%mod);
			}
		}
	}
	memset(ans, 0, sizeof(ans));
	for(int e = 0; e <= empty; e++){
		for(int c = cycles; c <= n; c++){
			if(dp3[0][e][c] == 0)continue;
			int val = dp3[0][e][c];
			for(int ec = 0; ec <= e; ec++){
				int ncycles = c + ec;
				int tmp = (uwu[e][ec]*1LL*val%mod)*fac[e]%mod;
				add(ans[n - ncycles], tmp);
			}
		}
	}
	for(int k = 0; k < n; k++){
		cout << ans[k] << ' ';
	}
	cout << '\n';

	return 0;
}