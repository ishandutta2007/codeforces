#include <cstdio>

#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;

const int N = 150010;

int n;
ll a[N];
bool f[N];
priority_queue<ll, vector<ll>, greater<ll> > q;
map<ll, priority_queue<int, vector<int>, greater<int> > > mp;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		mp[a[i]].push(i);
		if (mp[a[i]].size() == 2)
			q.push(a[i]);
	}
	while (!q.empty()) {
		ll v = q.top();
		q.pop();
		int i, j;
		i = mp[v].top();
		mp[v].pop();
		j = mp[v].top();
		mp[v].pop();
		if (mp[v].size() >= 2)
			q.push(v);
		f[i] = true;
		a[j] *= 2;
		mp[v * 2].push(j);
		if (mp[v * 2].size() == 2)
			q.push(v * 2);
	}
	printf("%d\n", count(f + 1, f + n + 1, false));
	for (int i = 1; i <= n; ++i)
		if (!f[i])
			printf("%lld ", a[i]);
	return 0;
}