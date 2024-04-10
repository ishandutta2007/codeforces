#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

using namespace std;

long long x;
long long k;

vector<long long> divisors;
map<long long, vector<long long>> divs;

int generate(long long x, long long k, int lim) {
	if (x == 1 || k == 0) {
		printf("%lld ", x);
		return 1;
	}

	if (divs[x].empty()) {
		for (long long d: divisors) {
			if (x % d == 0) divs[x].push_back(d);
		}
	}

	int tot = 0;
	for (long long d : divs[x]) {
		tot += generate(d,k-1,lim - tot);
		if (tot == lim) break;
	}
	return tot;
}

int main() {
	scanf("%lld %lld", &x, &k);	

	for (int i = 1; i*1ll*i <= x; i++) {
		if (x % i == 0) {
			divisors.push_back(i);
			if (x/i != i) divisors.push_back(x/i);
		}
	}

	sort(divisors.begin(), divisors.end());
	generate(x,k,100000);
}