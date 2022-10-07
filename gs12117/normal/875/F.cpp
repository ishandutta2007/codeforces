#include<cstdio>
#include<queue>
using namespace std;
int n, m;
struct edge {
	int a, b, w;
	bool operator<(const edge&r)const {
		return w < r.w;
	}
};
edge el[200100];
int uft[200100];
int wn[200100];
int en[200100];
priority_queue<edge> pq;
int uftf(int x) {
	if (x == uft[x])return x;
	return uft[x] = uftf(uft[x]);
}
void merge(int x, int y) {
	uft[x] = y;
	wn[y] += wn[x];
	en[y] += en[x];
	en[y]++;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &el[i].a, &el[i].b, &el[i].w);
		pq.push(el[i]);
	}
	for (int i = 0; i <= n; i++) {
		uft[i] = i;
		wn[i] = 1;
		en[i] = 0;
	}
	int ans = 0;
	while (pq.size() > 0) {
		edge t = pq.top();
		pq.pop();
		if (uftf(t.a) != uftf(t.b)) {
			if (wn[uftf(t.a)] + wn[uftf(t.b)] > en[uftf(t.a)] + en[uftf(t.b)]) {
				ans += t.w;
				merge(uftf(t.a), uftf(t.b));
			}
		}
		else {
			if (wn[uftf(t.a)] > en[uftf(t.a)]) {
				ans += t.w;
				en[uftf(t.a)]++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}