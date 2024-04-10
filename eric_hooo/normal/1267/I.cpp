#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int A[210][210];
int in[210], vis[210];
vector <int> all[210];

bool cmp(int x, int y) {
	if (~A[x][y]) return A[x][y];
	cout << "? " << x << " " << y << endl;
	char tmp; cin >> tmp;
	assert(tmp == '<' || tmp == '>');
	return A[x][y] = tmp == '<' ? 1 : 0;
}

bool cmps(pii a, pii b) {
	return cmp(a.fi, b.fi);
}

int main () {
	int T; cin >> T;
	while (T--) {
		memset(A, -1, sizeof(A));
		int n; cin >> n;
		for (int i = 1; i <= 2 * n; i++) {
			all[i].clear();
		}
		vector <pii> a;
		for (int i = 1; i <= n; i++) {
			a.push_back(cmp(2 * i - 1, 2 * i) ? mp(2 * i - 1, 2 * i) : mp(2 * i, 2 * i - 1));
		}
		sort(a.begin(), a.end(), cmps);
		memset(in, 0, sizeof(in));
		for (int i = 0; i < a.size(); i++) {
			if (i) all[a[i - 1].fi].push_back(a[i].fi), in[a[i].fi]++;
			all[a[i].fi].push_back(a[i].se), in[a[i].se]++;
		}
		vector <int> cur;
		for (int i = 1; i <= 2 * n; i++) {
			if (!in[i]) cur.push_back(i);
		}
		int TOT = n;
		memset(vis, 0, sizeof(vis));
		while (TOT--) {
			int minj = -1;
			for (int i = 0; i < cur.size(); i++) {
				if (minj == -1 || cmp(cur[i], minj)) minj = cur[i];
			}
			for (int i = 0; i < cur.size(); i++) {
				if (cur[i] == minj) {
					cur.erase(cur.begin() + i);
					break;
				}
			}
			vis[minj] = 1;
			for (int i = 0; i < all[minj].size(); i++) {
				int x = all[minj][i];
				in[x]--;
				if (in[x] == 0) cur.push_back(x);
			}
		}
		cout << "!" << endl;
	}
	return 0;
}