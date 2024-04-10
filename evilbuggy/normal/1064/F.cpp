#include <bits/stdc++.h>
using namespace std;

const int limn = 100005;
const long long lim = 1000*1000;

bool isPrime[lim];
vector<int> pfacs[limn];
long long lowerlim, factors[limn];

long long solve1(long long a, long long b, long long limx, long long limy){
	long long ret = -lim;
	if(b < 0)return ret;
	if(b <= limx){
		ret = max(ret, b + limy);
	}
	for(int z = 1; z <= lim; z++){
		long long r = b%z;
		long long q = b/z;
		long long c = q - a - r;
		if(c < 0 || r > limx)continue;
		long long lo, hi;
		if(c < limy){
			lo = 0;
		}else{
			lo = (c - limy + z)/(z + 1);
		}
		hi = min(c/(z + 1), (limx - r)/z);
		if(lo <= hi)ret = max(ret, c - lo + r);
	}
	if(ret < 0)ret = -lim;
	return ret;
}

inline int getFactors(long long k){
	assert(k > lowerlim);
	
	int m = 1;
	factors[0] = 1;
	for(int x : pfacs[k - lowerlim]){
		int cnt = 0;
		while(k%x == 0){
			k /= x;
			cnt++;
		}
		int pm = m;
		for(int i = 0; i < pm; i++){
			long long cur = factors[i];
			for(int j = 0; j < cnt; j++){
				cur *= x;
				factors[m] = cur; m++;
			}
		}
	}
	if(k > 1){
		int pm = m;
		for(int i = 0; i < pm; i++){
			factors[m] = factors[i]*k; m++;
		}
	}
	return m;
}

long long solve2(long long a, long long b, long long limx, long long limy){
	long long ret = -lim;
	if(b < 0)return ret;
	if(b <= limx){
		ret = max(ret, b + limy);
	}
	for(long long x = 0; x <= limx && x < b; x++){
		int m = getFactors(b - x);
		for(int i = 0; i < m; i++){
			long long y = factors[i] - a - x;
			if(0 <= y && y <= limy)ret = max(ret, x + y);
		}
	}
	return ret;
}

void init(long long k){
	for(int i = 2; i < lim; i++){
		isPrime[i] = true;
	}
	for(int i = 2; i*i < lim; i++){
		if(isPrime[i]){
			for(int j = i*i; j < lim; j += i){
				isPrime[j] = false;
			}
		}
	}
	lowerlim = k - limn + 1;
	for(int i = 2; i < lim; i++){
		if(!isPrime[i])continue;
		long long x = i*(lowerlim/i) + i;
		while(x < lowerlim + limn){
			pfacs[x - lowerlim].emplace_back(i);
			x += i;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, m, l, r, k;
	cin >> n >> l >> r >> k;
	if(l <= r){
		m = r - l + 1;
	}else{
		m = n - l + r + 1;
	}

	if((k - m)/n <= lim){
		long long ans = -lim;
		ans = max(ans, solve1(n, k - m, m - 1, n - m));
		ans = max(ans, 1 + solve1(n + 1, k - m, m - 1, n - m));
		ans = max(ans, 1 + solve1(n + 1, k - m - 1, m - 1, n - m));
		if(ans < 0){
			cout << -1 << '\n';
		}else{
			cout << ans << '\n';
		}
	}else{
		init(k - m);
		long long ans = -lim;
		ans = max(ans, solve2(n, k - m, m - 1, n - m));
		ans = max(ans, 1 + solve2(n + 1, k - m, m - 1, n - m));
		ans = max(ans, 1 + solve2(n + 1, k - m - 1, m - 1, n - m));
		cout << ans << '\n';
	}

	return 0;
}