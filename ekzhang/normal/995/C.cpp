#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
#define THRES 1000000000000LL
int N;
struct node {
	int x, y;
	int l, r;
	int ls = 1, rs = 1;
} vals[2 * MAXN];
int t;
int sgn[MAXN];

bool add(int i, int j, int s=1, LL k=THRES) {
	LL x = vals[i].x + s * vals[j].x;
	LL y = vals[i].y + s * vals[j].y;
	return x * x + y * y <= k;
}

void dfs(int x, int s=1) {
	vals[x].ls *= s, vals[x].rs *= s;
	if (vals[x].r == -1) {
		sgn[vals[x].l] = vals[x].ls;
		return;
	}
	dfs(vals[x].l, vals[x].ls);
	dfs(vals[x].r, vals[x].rs);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> vals[i].x >> vals[i].y;
		vals[i].l = i;
		vals[i].r = -1;
		v.push_back(i);
	}

	t = N;
	while (v.size() >= 3) {
		vector<int> idx;
		for (int i = 0; i < 3; i++) {
			idx.push_back(v.back());
			v.pop_back();
		}
		bool done = false;
		for (int i = 0; i < 3 && !done; i++) {
			for (int j = i + 1; j < 3 && !done; j++) {
				int a = idx[i], b = idx[j];
				if (add(a, b)) {
					vals[t].x = vals[a].x + vals[b].x;
					vals[t].y = vals[a].y + vals[b].y;
					vals[t].l = a;
					vals[t].r = b;
				}
				else if (add(a, b, -1)) {
					vals[t].x = vals[a].x - vals[b].x;
					vals[t].y = vals[a].y - vals[b].y;
					vals[t].l = a;
					vals[t].r = b;
					vals[t].rs = -1;
				}
				else
					continue;

				v.push_back(t++);
				v.push_back(idx[3 - i - j]);
				done = true;
			}
		}
	}

	if (v.size() == 2 && !add(v[0], v[1], 1, 2 * THRES)) {
		vals[v[1]].ls *= -1;
		vals[v[1]].rs *= -1;
	}

	for (int x : v)
		dfs(x);

	for (int i = 0; i < N; i++)
		cout << sgn[i] << ' ';

	cout << endl;
	return 0;
}