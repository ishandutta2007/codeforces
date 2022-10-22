#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

typedef unsigned long long ull;

int TOTOT;
int ll[100010], rr[100010];
ull pw[200010];
vector <int> all;
int dp[200010][300];
vector <int> be[200010];
vector <int> poi[200010];
map <int, int> id[200010];
int M[200010];
int tot, n;

ostream &operator << (ostream &cout, vector <int> a) {
	cout << "{";
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << "}";
	return cout;
}

ull get_hash(vector <int> &a) {
	ull h = 0;
	for (int i = 0; i < a.size(); i++) {
		h += pw[a[i]];
	}
	return h;
}

int cnt[1024];

int dfs(int now, int mmm) {
	if (now == all.size()) return 0;
	if (now) {
		int MMM = 0;
		for (int i = 0; i < poi[now - 1].size(); i++) {
			if (mmm >> i & 1) {
				if (rr[poi[now - 1][i]] != now) MMM |= 1 << id[now][poi[now - 1][i]];
			}
		}
		mmm = MMM;
	}
	if (dp[now][mmm] != -1) return dp[now][mmm];
	int res = dfs(now + 1, mmm) + (cnt[mmm] & 1) * (all[now + 1] - all[now]), last = -1;
	clock_t S = clock();
	for (int mask = M[now]; mask; mask = M[now] & (mask - 1)) { 
		int old = res;
		res = max(res, dfs(now + 1, mask | mmm) + (cnt[mask | mmm] & 1) * (all[now + 1] - all[now]));
		if (old != res) last = mask;
	}
	TOTOT += clock() - S;
	return dp[now][mmm] = res;
}

int main () {
	memset(dp, -1, sizeof(dp));
	pw[0] = 1;
	for (int i = 1; i < 200010; i++) {
		pw[i] = pw[i - 1] * 3;
	}
	int m, k; scanf("%d%d%d", &n, &m, &k);
	all.push_back(1), all.push_back(m + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &ll[i], &rr[i]);
//		ll[i] = rand(), rr[i] = rand(); if (ll[i] > rr[i]) swap(ll[i], rr[i]);
		all.push_back(ll[i]), all.push_back(rr[i] + 1);
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	for (int i = 0; i < n; i++) {
		ll[i] = lower_bound(all.begin(), all.end(), ll[i]) - all.begin();
		rr[i] = lower_bound(all.begin(), all.end(), rr[i] + 1) - all.begin();
		be[ll[i]].push_back(i);
	}
	for (int i = 1; i < 256; i++) {
		cnt[i] = cnt[i - (i & -i)] + 1;
	}
	vector <int> now;
	for (int i = 0; i < all.size(); i++) {
		for (int j = 0; j < be[i].size(); j++) {
			now.push_back(be[i][j]);
		}
		vector <int> tmp;
		for (int j = 0; j < now.size(); j++) {
			if (rr[now[j]] != i) tmp.push_back(now[j]), id[i][now[j]] = tmp.size() - 1;
		}
		for (int j = 0; j < be[i].size(); j++) {
			M[i] |= 1 << id[i][be[i][j]];
		}
		poi[i] = now = tmp;
	}
	printf("%d\n", dfs(0, 0));
//	if (n == 100000 && k == 7) cout << "    tot:" << tot << endl;
	return 0;
}