#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000100;

ll sum[2][4 * N]; //0 to quantity - 1 to quantity * price

void update(int id, int l, int r, int at, ll c, ll pc) {
	if (l == r) {
		sum[0][id] += c;
		sum[1][id] += pc;
	} else {
		int mid = (l + r) / 2;
		if (at <= mid)
			update(2 * id + 1, l, mid, at, c, pc);
		else
			update(2 * id + 2, mid + 1, r, at, c, pc);
		sum[0][id] = sum[0][2 * id + 1] + sum[0][2 * id + 2];
		sum[1][id] = sum[1][2 * id + 1] + sum[1][2 * id + 2];
	}
}

ll query(int id, int l, int r, int i, int j, int w) {
	if (r < i or l > j)
		return 0;
	if (l >= i and r <= j) 
		return sum[w][id];
	int mid = (l + r) / 2;
	return query(2 * id + 1, l, mid, i, j, w) + query(2 * id + 2, mid + 1, r, i, j, w);
}

struct provider {
	int l, r, index; ll c, p;
	bool operator < (const provider &other) {
		return p < other.p;
	}
};

struct event {
	//-1 to remove and 1 to add
	int tp, index;
	bool operator < (const event &other) {
		return tp > other.tp;
	}
};

vector<event> E[N];

int main() {
	int n, m; ll k;
	scanf("%d %lld %d", &n, &k, &m);
	vector<provider> P;
	for (int i = 0; i < m; ++i) {
		int l, r; ll c, p;
		scanf("%d %d %lld %lld", &l, &r, &c, &p);
		P.push_back((provider) {l, r, i, c, p});
	}
	sort(P.begin(), P.end());
	for (int i = 0; i < m; ++i) {
		E[P[i].l].push_back((event) { 1, i});
		E[P[i].r].push_back((event) {-1, i});
	}
	ll min_cost = 0;
	for (int i = 1; i <= n; ++i) {
		sort(E[i].begin(), E[i].end());
		int j = 0;
		for (; j < (int) E[i].size(); ++j) {
			if (E[i][j].tp == -1)
				break;
			int index = E[i][j].index;
			update(0, 0, m - 1, index,  P[index].c,  P[index].c * P[index].p); 
		}
		int l = 0, r = m - 1, index = m - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (query(0, 0, m - 1, 0, mid, 0) > k) {
				index = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ll cost = 0;
		if (query(0, 0, m - 1, 0, index, 0) < k) {
			cost = query(0, 0, m - 1, 0, index, 1);
		} else {
			if (index > 0) {
				ll rem = k - query(0, 0, m - 1, 0, index - 1, 0);
				cost += query(0, 0, m - 1, 0, index - 1, 1) + min(P[index].c, rem) * P[index].p;
			} else {
				cost += min(P[index].c, k) * P[index].p;
			}
		}
		min_cost += cost;
		for (; j < (int) E[i].size(); ++j) {
			int index = E[i][j].index;
			update(0, 0, m - 1, index, -P[index].c, -P[index].c * P[index].p); 
		}
	}
	printf("%lld\n", min_cost);
	return 0;
}