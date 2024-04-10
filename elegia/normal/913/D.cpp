#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct node {
	int a, t, id;

	node() {}

	node(int a, int t, int id) : a(a), t(t), id(id) {}

	bool operator<(const node& x) const { return t < x.t; }
};

const int N = 200010;

int n;

node p[N];
int cnt[N];
ll fw[N];
int fw2[N];
vector<int> inds[N];

int lowbit(int x);
void change(int k, int x);
void change2(int k);
int query2(int k);
ll query(int k);
int kth(ll x);

int main() {
	int t, ans = 0, aa, ak;
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; ++i) {
		p[i].id = i;
		scanf("%d%d", &p[i].a, &p[i].t);
	}
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; ++i)
		inds[p[i].a].push_back(i);
	for (int i = n; i; --i) {
		for (int j = 0; j < inds[i].size(); ++j) {
			change(inds[i][j], p[inds[i][j]].t);
			change2(inds[i][j]);
		}
		int ck, sc = min(i, query2(ck = kth(t)));
		if (ans < sc) {
			ak = ck;
			ans = sc;
			aa = i;
		}
	}
	printf("%d\n%d\n", ans, ans);
	for (int i = ak; ans; --i) {
		if (p[i].a >= aa) {
			--ans;
			if (ans == 0)
				printf("%d\n", p[i].id);
			else
				printf("%d ", p[i].id);
		}
	}
	if (ans == 0)
		printf("\n");
	return 0;
}

int lowbit(int x) {
	return x & -x;
}

void change2(int k) {
	for (; k <= n; k += lowbit(k))
		++fw2[k];
}

int query2(int k) {
	int ret = 0;
	for (; k; k -= lowbit(k))
		ret += fw2[k];
	return ret;
}

void change(int k, int x) {
	for (; k <= n; k += lowbit(k))
		fw[k] += x;
}

ll query(int k) {
	ll ret = 0;
	for (; k; k -= lowbit(k))
		ret += fw[k];
	return ret;
}

int kth(ll x) {
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (query(mid) > x)
			r = mid - 1;
		else
			l = mid;
	}
	return l;
}