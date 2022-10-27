#include <bits/stdc++.h>
using namespace std;

inline int power(int x, int n, int p){
	int ret = 1;
	while(n){
		if(n&1)ret = ret*1LL*x%p;
		x = x*1LL*x%p;
		n >>= 1;
	}
	return ret;
}

inline vector<int> factorise(int n){
	vector<int> ret;
	for(int x = 2; x*x <= n; x++){
		if(n%x == 0){
			ret.emplace_back(x);
		}
		while(n%x == 0){
			n /= x;
		}
	}
	if(n > 1)ret.emplace_back(n);
	return ret;
}

int order(int x, int p, int ord, vector<int> &pfacs){
	for(auto y : pfacs){
		if(ord%y == 0 && power(x, ord/y, p) == 1){
			return order(x, p, ord/y, pfacs);
		}
	}
	return ord;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	int p; cin >> p;
	vector<int> ordset;
	vector<int> pfacs = factorise(p - 1);
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		ordset.emplace_back(order(x, p, p - 1, pfacs));
	}
	int g = 0;
	for(int i = 1; i <= m; i++){
		int x;
		cin >> x;
		g = __gcd(g, x);
	}
	vector<int> divs;
	for(int x = 1; x*x <= p - 1; x++){
		if((p - 1)%x == 0){
			divs.emplace_back(x);
			if(x*x != p - 1)divs.emplace_back((p - 1)/x);
		}
	}
	sort(divs.begin(), divs.end());
	
	int r = (int)divs.size();
	vector<long long> sum(r);

	for(auto x : ordset){
		int y = __gcd(1LL*(p - 1), 1LL*((p - 1)/x)*g);
		int ind = lower_bound(divs.begin(), divs.end(), y) - divs.begin();
		assert(divs[ind] == y); sum[ind] = 1;
	}
	long long ans = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < i; j++){
			if(sum[j] == 1 && divs[i]%divs[j] == 0){
				sum[i] = 1;
				break;
			}
		}
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < i; j++){
			if(divs[i]%divs[j] == 0){
				sum[i] -= sum[j];
			}
		}
		ans += sum[i]*(p - 1)/divs[i];
	}
	cout << ans << '\n';

	return 0;
}