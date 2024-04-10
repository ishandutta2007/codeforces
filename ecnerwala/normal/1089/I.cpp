#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


LL ways[401][401];
// ways to sum to x, cnt = c;

int main(){
	LL n = 400;
	LL MOD;
	int T;
	cin >> T;
	cin >> MOD;
	vector<LL> fact(n+1);
	fact[0] = 1;
	for(LL i = 1; i <= n; i++){
		fact[i] = (i * fact[i-1]) % MOD;
	}
	vector<LL> inc(n+1);
	inc[1] = 0;
	for(LL len = 1; len <= n; len++){
		vector<LL> tmp(len+1, 0);
		tmp[0] = 1;
		for(LL f = 1; f <= len; f++){
			for(LL g = 1; g <= f; g++){
				if(g == len) continue;
				tmp[f] += tmp[f-g] * (fact[g] - inc[g]);
				tmp[f] %= MOD;
			}
		}
		inc[len] = tmp[len];
	}
	vector<LL> ans(n+1);
	ans[0] = 0;
	ways[0][0] = 1;
	for(LL a = 1; a <= n; a++){
		for(LL b = 1; b <= n; b++){
			for(LL c = 0; c < a; c++){
				ways[a][b] += ways[c][b-1] * fact[a-c];
				ways[a][b] %= MOD;
			}
		}
	}

	for(LL len = 1; len <= n; len++){
		ans[len] = fact[len];
		ans[len] -= 2 * inc[len];
		for(LL cnt = 2; cnt < len; cnt++){
			ans[len] -= ans[cnt] * ways[len][cnt];
			ans[len] %= MOD;
		}
	}
	ans[2] = 2;
	for(int t = 0; t < T; t++){
		int nn;
		cin >> nn;
		LL f = ans[nn];
		f %= MOD;
		if(f < 0) f += MOD;
		cout << f << '\n';
	}
}