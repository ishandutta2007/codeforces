#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 200005;

long long arb[maxn * 4], maxt[maxn * 4], s[maxn], d[maxn];
vector< pair<int, int> > E[maxn];

void update(int nod, int left, int right, int start, int finish, long long value) {
	if (start <= left && right <= finish) {
		arb[nod] += value;
		maxt[nod] += value;
		return;
	}
	
	int mid = (left + right) / 2;
	if (start <= mid)
		update(nod * 2, left, mid, start, finish, value);
	if (mid < finish)
		update(nod * 2 + 1, mid + 1, right, start, finish, value);
	
	maxt[nod] = max(maxt[nod * 2], maxt[nod * 2 + 1]) + arb[nod];
}

long long query() {
	return maxt[1];
}

int main() {
	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; ++i)
		cin >> s[i], s[i] += s[i - 1];
	
	for (int i = 1; i <= M; ++i) {
		int x, y, z; cin >> x >> y >> z;
		E[y].push_back(make_pair(x, z));
	}

	d[0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (vector<pair<int, int> >::iterator it = E[i].begin(); it != E[i].end(); ++it)
			update(1, 1, N, 1, it -> first, it -> second);
		update(1, 1, N, i, i, s[i - 1] + d[i - 1]);
		d[i] = d[i - 1];
		d[i] = max(d[i], -s[i] + query());
	}

	cout << d[N];
}