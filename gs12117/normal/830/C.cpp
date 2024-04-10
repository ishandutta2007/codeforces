#include<cstdio>
#include<functional>
#include<queue>
#include<vector>
using namespace std;
int n;
long long int p;
int a[110];
int deg[110];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main() {
	scanf("%d%I64d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pq.push(make_pair(1, i));
	}
	long long int ans = 1;
	while (pq.size() > 0) {
		int vt = pq.top().first;
		while (pq.size() > 0 && pq.top().first == vt) {
			int d = pq.top().second;
			pq.pop();
			deg[d] = (a[d] + vt - 1) / vt;
			if (deg[d] > 1) {
				int nvt = (a[d] + deg[d] - 2) / (deg[d] - 1);
				pq.push(make_pair(nvt, d));
			}
		}
		long long int sumd = 0;
		long long int sump = p;
		for (int i = 0; i < n; i++) {
			sumd += deg[i];
			sump += a[i];
		}
		long long int tans = sump / sumd;
		if (tans >= vt)ans = tans;
	}
	printf("%I64d", ans);
	return 0;
}