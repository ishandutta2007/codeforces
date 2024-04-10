#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

inline int power(int a, int b){
	int ret = 1;
	while(b){
		if(b&1)ret = ret*1LL*a%mod;
		a = a*1LL*a%mod;
		b >>= 1;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> coef({1});
	for(int i = 1; i <= k; i++){
		vector<int> ncoef(min(n + 1, i + 1));
		for(int j = 0; j < (int)coef.size(); j++){
			add(ncoef[j], j*1LL*coef[j]%mod);
			if(j <= n && j <= i)add(ncoef[j + 1], (n - j)*1LL*coef[j]%mod);
		}
		coef = ncoef;
	}
	int prod = power(2, n), answer = 0;
	for(int i = 0; i < (int)coef.size(); i++){
		add(answer, coef[i]*1LL*prod%mod);
		prod = (prod*1LL*(mod + 1)/2)%mod;
	}
	cout << answer << '\n';

	return 0;
}