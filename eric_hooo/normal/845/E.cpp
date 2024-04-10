#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> piii;

int a[510], b[510];
int n, m, k;
vector <int> allx, ally;
vector <piii> all[1010];
int cnt[1010];

int get_idx(int x) {
	return lower_bound(allx.begin(), allx.end(), x) - allx.begin();
}

int get_idy(int y) {
	return lower_bound(ally.begin(), ally.end(), y) - ally.begin();
}

bool check(int mid) {
	allx.clear(), ally.clear();
	ally.push_back(1), ally.push_back(m + 1), allx.push_back(1), allx.push_back(n + 1);
	for (int i = 0; i < k; i++) {
		allx.push_back(max(1, a[i] - mid)), allx.push_back(min(n + 1, a[i] + mid + 1));
		ally.push_back(max(1, b[i] - mid)), ally.push_back(min(m + 1, b[i] + mid + 1));
	}
	sort(allx.begin(), allx.end()), allx.resize(unique(allx.begin(), allx.end()) - allx.begin());
	sort(ally.begin(), ally.end()), ally.resize(unique(ally.begin(), ally.end()) - ally.begin());
	for (int i = 0; i < allx.size(); i++) {
		all[i].clear();
	}
	for (int i = 0; i < k; i++) {
		int l = get_idy(max(1, b[i] - mid)), r = get_idy(min(m + 1, b[i] + mid + 1));
		all[get_idx(max(1, a[i] - mid))].push_back(mp(mp(l, r), 1));
		all[get_idx(min(n + 1, a[i] + mid + 1))].push_back(mp(mp(l, r), -1));
	}
	memset(cnt, 0, sizeof(cnt));
	int xmin = 0x3f3f3f3f, xmax = -1, ymin = 0x3f3f3f3f, ymax = -1;
	int pd = 0;
	for (int i = 0; i < allx.size() - 1; i++) {
		for (int j = 0; j < all[i].size(); j++) {
			int l = all[i][j].fi.fi, r = all[i][j].fi.se, val = all[i][j].se;
			for (int k = l; k < r; k++) {
				cnt[k] += val;
			}
		}
		for (int j = 0; j < ally.size() - 1; j++) {
			if (!cnt[j]) xmax = max(xmax, allx[i + 1] - 1), xmin = min(xmin, allx[i]), 
						 ymax = max(ymax, ally[j + 1] - 1), ymin = min(ymin, ally[j]), pd = 1;
		}
	}
	return !pd || max(xmax - xmin + 1 >> 1, ymax - ymin + 1 >> 1) <= mid;
}

int main () {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	long long l = 0, r = n + m;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%I64d\n", l);
	return 0;
}