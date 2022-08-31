#include <cstdio>
#include <cstring>

#include <algorithm>
#include <limits>

using namespace std;

typedef long long ll;

const int N = 5010;

ll ans, ansC;
int id;
ll n;
int k;

int main() {
	ans = numeric_limits<ll>::max();
	scanf("%lld%d", &n, &k);
	for (int i = 1; i <= k; ++i) {
		ll a;
		scanf("%lld", &a);
		if (ans > (n % a)) {
			ans = n % a;
			id = i;
			ansC = n / a;
		}
	}
	printf("%d %lld\n", id, ansC);
	return 0;
}