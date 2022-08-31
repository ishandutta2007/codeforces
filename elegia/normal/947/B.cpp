#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

typedef long long ll;

const int N = 100010;

priority_queue<ll, vector<ll>, greater<ll> > q;

int qc;
int v[N], t[N];

int main() {
	int n;
	ll cur = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &v[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	for (int i = 1; i <= n; ++i) {
		q.push(v[i] + cur);
		cur += t[i];
		++qc;
		ll ans = 0;
		while (!q.empty() && q.top() <= cur) {
			ans += q.top() + t[i] - cur;
			q.pop();
			--qc;
		}
		ans += qc * (ll)t[i];
		printf("%lld ", ans);
	}
	return 0;
}