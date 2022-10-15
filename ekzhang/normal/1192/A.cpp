#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

const LL D = 2e9 + 13;
#define MAXN 150013
int N, T;
LL P[MAXN];
map<LL, int> to_idx;
set<LL> near, vis;
map<LL, int> cpt;
priority_queue<int> pq;
bool inpq[MAXN];

void addpq(int n) {
	if (!inpq[n]) {
		pq.push(n);
		inpq[n] = true;
	}
}

int poppq() {
	int ret = pq.top();
	pq.pop();
	inpq[ret] = false;
	return ret;
}

void flood(LL p) {
	if (!to_idx.count(p) || vis.count(p))
		return;
	vis.insert(p);
	flood(p - D - 1);
	flood(p - D);
	flood(p - D + 1);
	flood(p + D - 1);
	flood(p + D);
	flood(p + D + 1);
	flood(p - 1);
	flood(p + 1);
}

void dfs(LL p) {
	if (!near.count(p) || vis.count(p))
		return;
	if (to_idx.count(p)) {
		addpq(to_idx[p]);
		return;
	}
	cpt[p] = 0;
	vis.insert(p);
	dfs(p - D);
	dfs(p - 1);
	dfs(p + 1);
	dfs(p + D);
}

void flood2(LL p, int c) {
	if (!near.count(p) || cpt.count(p))
		return;
	cpt[p] = c;
	flood2(p - D, c);
	flood2(p + D, c);
	flood2(p - 1, c);
	flood2(p + 1, c);
}

bool check(int k) {
	int c[8];
	LL p = P[k];
	c[0] = cpt[p - D - 1];
	c[1] = cpt[p - D];
	c[2] = cpt[p - D + 1];
	c[3] = cpt[p + 1];
	c[4] = cpt[p + D + 1];
	c[5] = cpt[p + D];
	c[6] = cpt[p + D - 1];
	c[7] = cpt[p - 1];
	int cnt = 0;
	for (int i = 0; i < 8; i++)
		cnt += (c[i] == -1);
	if (cnt <= 1)
		return true;
	if (c[1] >= 0 && c[1] == c[3] && c[2] == -1)
		return false;
	if (c[3] >= 0 && c[3] == c[5] && c[4] == -1)
		return false;
	if (c[5] >= 0 && c[5] == c[7] && c[6] == -1)
		return false;
	if (c[7] >= 0 && c[7] == c[1] && c[0] == -1)
		return false;

	if (c[1] >= 0 && c[1] == c[5] && (c[2] == -1 || c[3] == -1 || c[4] == -1) && (c[0] == -1 || c[7] == -1 || c[6] == -1))
		return false;
	if (c[3] >= 0 && c[3] == c[7] && (c[0] == -1 || c[1] == -1 || c[2] == -1) && (c[6] == -1 || c[5] == -1 || c[4] == -1))
		return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		LL p = P[i] = D * r + c;
		to_idx[p] = i;
		cpt[p] = -1;
		near.insert(p);
		near.insert(p - D - 1);
		near.insert(p - D);
		near.insert(p - D + 1);
		near.insert(p + D - 1);
		near.insert(p + D);
		near.insert(p + D + 1);
		near.insert(p - 1);
		near.insert(p + 1);
	}

	int c = 1;
	for (LL p : near) {
		if (!cpt.count(p)) {
			flood2(p, c++);
		}
	}

	LL p = to_idx.begin()->first;
	flood(p);
	if (vis.size() < N) {
		cout << "NO" << endl;
		return 0;
	}
	vis.clear();

	p = *near.begin();
	dfs(p);

	vector<int> ans;
	while (pq.size()) {
		int k = poppq();
		if (check(k)) {
			ans.push_back(k);
			to_idx.erase(P[k]);
			vis.erase(P[k] - D);
			vis.erase(P[k] + D);
			vis.erase(P[k] - 1);
			vis.erase(P[k] + 1);
			dfs(P[k]);
		}
	}

	reverse(ans.begin(), ans.end());
	cout << "YES\n";
	for (int x : ans)
		cout << x + 1 << '\n';
	cout.flush();
	return 0;
}