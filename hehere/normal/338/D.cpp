#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const LL maxN = (LL)1e12;
const int maxK = 10000 + 233;
LL n, m, a[maxK];
int k;

LL gcd(LL a, LL b) {
	return !b ? a : gcd(b, a%b);
}

LL combine(LL &r, LL &m, LL rr, LL mm) {
	if(mm > m) {
		std::swap(r, rr);
		std::swap(m, mm);
	}
	while(r % mm != rr) r += m;
	m *= mm;
}

bool solve() {
	LL lcm = 1;
	for(int i = 1; i <= k; ++i) {
		LL g = gcd(lcm, a[i]);
		lcm /= g;
		if((double)lcm * a[i] > 1e15) return false;
		lcm *= a[i];
	}
	if(n < lcm) return false;
	vector<LL> power, rem;
	LL tmp = lcm;
	for(LL i = 2; i*i <= tmp; ++i) {
		if(tmp % i == 0) {
			LL inp = 1;
			while(tmp % i == 0) inp *= i, tmp /= i;
			power.push_back(inp);
		}
	}
	if(tmp > 1) power.push_back(tmp);
	rem.resize(power.size());
	for(int i = 0; i < power.size(); ++i) {
		LL pn = power[i];
		LL &r = rem[i];
		for(int j = 1; j <= k; ++j) if(a[j] % pn == 0) {
			r = (-j) % pn;
			if(r < 0) r += pn;
			break;
		}
	}
//	for(int i = 0; i < power.size(); ++i) printf("x == %lld (mod %lld)\n", rem[i], power[i]);
	LL ans = 0, mod = 1;
	for(int j = 0; j < power.size(); ++j) combine(ans, mod, rem[j], power[j]);
	if(ans + k > m) return false;
	for(int i = 1; i <= k; ++i) if(a[i] != gcd(lcm, ans + i)) return false;
	return true;
}

int main() {
	cin >> n >> m >> k;
	for(int i = 1; i <= k; ++i) cin >> a[i];
	printf("%s\n", solve() ? "YES" : "NO");
	return 0;
}