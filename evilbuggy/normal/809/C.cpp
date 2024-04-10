#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int getSum(int x, int y, int k, int st){
	if(st >= k)return 0;
	long long l = st + 1, r = min(k, st + y);
	long long ret = (r - l + 1)*(r + l)/2;
	ret = (ret%mod)*x%mod;
	return ret;
}

long long f(int x, int y, int k, int st = 0){
	if(x == 0 || y == 0 || st >= k)return 0;
	if(x > y)swap(x, y);
	if(y&(y - 1)){
		for(int i = 30; i >= 0; i--){
			if((y >> i) & 1){
				if((x >> i) & 1){
					long long ret = f(x^(1 << i), y^(1 << i), k, st);
					ret += getSum(1 << i, 1 << i, k, st);
					ret += getSum(x^(1 << i), 1 << i, k, st^(1 << i));
					ret += getSum(y^(1 << i), 1 << i, k, st^(1 << i));
					ret %= mod;
					return ret;
				}else{
					int ret = getSum(x, 1 << i, k, st) + f(x, y^(1 << i), k, st^(1 << i));
					if(ret >= mod)ret -= mod; return ret;
				}
			}
		}
	}else{
		return getSum(x, y, k, st);
	}
	assert(false);
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;
	while(q--){
		int x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		long long answer = f(x2, y2, k) - f(x2, y1 - 1, k) - f(x1 - 1, y2, k) + f(x1 - 1, y1 - 1, k);
		answer %= mod; if(answer < 0)answer += mod;
		cout << answer << '\n';
	}

	return 0;
}