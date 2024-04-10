#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front

typedef long long lli;
typedef pair<int, int> ii;
typedef pair<lli, lli> ll;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> os;

lli com(lli n, lli k) {
	lli ret = 1;
	for (lli i = 0; i < k; i++) {
		ret *= (n - i);
		ret /= (1 + i);
	}
	return ret;
}

int main() {
	/*os x;
	x.order_of_key(v); // banyak objek < v
	*x.find_by_order(v); // objek ke-v (0-based)*/
	lli n, left, right, mid, ans;
	double p, temp, eps = 1e-9;
	scanf("%lld %lf", &n, &p);
	left = 0;
	right = n - 2;
	ans = n - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		temp = 0.0;
		for (lli i = 1; i < 4; i++) {
			if ((i > mid) || (3 - i > n - mid))
				continue;
			if (i == 1)
				temp += (0.5 * com(mid, i) * com(n - mid, 3 - i) / com(n, 3));
			else
				temp += ((double) com(mid, i) * com(n - mid, 3 - i) / com(n, 3));
		}
		if (temp < p - eps)
			left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}