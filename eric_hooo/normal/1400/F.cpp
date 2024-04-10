#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > all;
vector <int> cur;

int prime[11000];
int dp[11000], ndp[11000];
int nxt[11000][10];

bool is_prime(vector <int> &v, int x) {
	for (int i = 0; i < v.size(); i++) {
		int sum = 0;
		for (int j = i; j < v.size(); j++) {
			sum += v[j];
			if (x % sum == 0 && sum != x) return 0;
		}
	}
	return 1;
}

struct Tire {
	int son[100000][10], id[100000];
	int tot;
	Trie() {tot = 1, memset(son, -1, sizeof(son));}
	void init() {tot = 1, memset(son, -1, sizeof(son));}
	void add(const vector <int> &a, int I) {
		int now = 0;
		for (int i = 0; i < a.size(); i++) {
			if (son[now][a[i] - 1] == -1) son[now][a[i] - 1] = tot++;
			now = son[now][a[i] - 1];
		}
		id[now] = I;
	}
	int get_id(const vector <int> &a) {
		int now = 0;
		for (int i = 0; i < a.size(); i++) {
			now = son[now][a[i] - 1];
		}
		return id[now];
	}
}T;

void dfs(int n, vector <vector <int> > &all) {
	if (n == 0) {
		all.push_back(cur);
		return ;
	}
	for (int i = 2; i <= 9; i++) {
		if (i > n) break;
		cur.push_back(i);
		dfs(n - i, all);
		cur.pop_back();
	}
}

int SUM(const vector <int> &a) {
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
	}
	return sum;
}

int main () {
	string s; cin >> s; int n = s.length();
	int x; cin >> x;
	if (x == 1) {
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') cnt++;
		}
		cout << cnt << endl;
		return 0;
	}
	dfs(x, all);
	for (int i = 0; i < all.size(); i++) {
		prime[i] = is_prime(all[i], x);
	}
	T.init();
	for (int i = 0; i < x; i++) {
		dfs(i, all);
	}
	for (int i = 0; i < all.size(); i++) {
		T.add(all[i], i);
	}
	for (int i = 0; i < all.size(); i++) {
		for (int j = 1; j <= 9; j++) {
			vector <int> tmp = all[i];
			int sum = SUM(tmp);
			tmp.push_back(j), sum += j;
			while (sum > x) sum -= tmp[0], tmp.erase(tmp.begin());
			if (j == 1) tmp = {};
			nxt[i][j] = T.get_id(tmp);
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[T.get_id({})] = 0;
	for (int i = 0; i < n; i++) {
		memset(ndp, 0x3f, sizeof(ndp));
		for (int j = 0; j < all.size(); j++) {
			if (dp[j] == 0x3f3f3f3f) continue;
			ndp[j] = min(ndp[j], dp[j] + 1);
			int nj = nxt[j][s[i] - '0'];
			if (!prime[nj]) ndp[nj] = min(ndp[nj], dp[j]);
		}
		swap(ndp, dp);
	}
	int minj = 0x3f3f3f3f;
	for (int i = 0; i < all.size(); i++) {
		minj = min(minj, dp[i]);
	}
	cout << minj << endl;
	return 0;
}