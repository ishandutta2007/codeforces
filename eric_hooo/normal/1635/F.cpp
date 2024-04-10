#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, long long> pil;

const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, q;
int a[300010], b[300010];
int L[300010], R[300010];
vector <pil> mdy[300010];
vector <int> qry[300010];
long long ans[300010];
vector <int> st;
long long T[300010];

void modify(int x, long long v) {
	while (x <= 300005) T[x] = min(T[x], v), x += x & -x;
}

long long query(int x) {
	long long res = INF;
	while (x) res = min(res, T[x]), x -= x & -x;
	return res;
}

int main() {
	memset(T, 0x3f, sizeof(T));
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	for (int i = 1; i <= n; i++) {
		while (st.size() && b[st.back()] > b[i]) st.pop_back();
		if (st.size()) mdy[st.back()].push_back(mp(i, 1ll * (a[i] - a[st.back()]) * (b[i] + b[st.back()])));
		st.push_back(i);
	}
	st.clear();
	for (int i = n; i >= 1; i--) {
		while (st.size() && b[st.back()] > b[i]) st.pop_back();
		if (st.size()) mdy[i].push_back(mp(st.back(), 1ll * (a[st.back()] - a[i]) * (b[i] + b[st.back()])));
		st.push_back(i);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &L[i], &R[i]);
		qry[L[i]].push_back(i);
	}
	for (int i = n; i >= 1; i--) {
		for (auto it : mdy[i]) {
			modify(it.fi, it.se);
		}
		for (auto id : qry[i]) {
			ans[id] = query(R[id]);
		}
	}
	for (int i = 0; i < q; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}