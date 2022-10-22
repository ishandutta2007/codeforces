#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;

int a[100010];
char b[100010];
string op;
vector <int> seq;
int pre[100010], suc[100010], be[100010];

void solve(int l, int r) {
	if (l > r) return ;
	long long val = 1;
	for (int i = l; i <= r; i++) {
		pre[i] = val;
		if (seq[i] > 0) val = min(val * seq[i], (long long)INF);
	}
	val = 1;
	for (int i = r; i >= l; i--) {
		suc[i] = val;
		if (seq[i] > 0) val = min(val * seq[i], (long long)INF);
	}
	vector <int> pos; pos.push_back(l - 1);
	for (int i = l; i <= r; i++) {
		if (seq[i] < 0 && 1ll * (pre[i] - 1) * (suc[i] - 1) - 1 <= -seq[i]) {
			pos.push_back(i);
			if (be[i]) b[be[i] - 1] = '+';
			for (int j = be[i]; j < be[i] - seq[i]; j++) {
				b[j] = '+';
			}
		}
	}
	pos.push_back(r + 1);
	if (pos.size() == 2) return ;
	for (int i = 1; i < pos.size(); i++) {
		solve(pos[i - 1] + 1, pos[i] - 1);
	}
}

int dp[100010], lst[100010];

int main () {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> op;
	int ADD = 0, MUL = 0, SUB = 0;
	if (op.size() == 1) {
		memset(b, op[0], sizeof(b));
		goto END;
	}
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '+') ADD = 1;
		if (op[i] == '*') MUL = 1;
		if (op[i] == '-') SUB = 1;
	}
	if (!MUL) {
		memset(b, '+', sizeof(b));
		goto END;
	}
	memset(b, '*', sizeof(b));
	for (int i = 0; i < n; i++) {
		if (!a[i]) {
			if (i) b[i - 1] = ADD ? '+' : '-';
			b[i] = ADD ? '+' : '*';
		}
	}
	if (!ADD) goto END;
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j + 1 < n && b[j] == '*') j++;
		int cur = 1;
		seq.clear();
		for (int k = i; k <= j; k++) {
			if (a[k] == 1) {
				if (cur != 1) seq.push_back(cur);
				cur = 1;
				if (!seq.size()) {
					b[k] = '+';
					continue;
				}
				if (seq.back() > 0) be[seq.size()] = k, seq.push_back(-1);
				else seq.back()--;
			} else cur = min(cur * a[k], INF);
		}
		if (cur != 1) seq.push_back(cur);
		if (seq.size() && seq.back() < 0) {
			for (int k = be[(int)seq.size() - 1]; k < be[(int)seq.size() - 1] - seq.back(); k++) {
				b[k - 1] = '+';
			}
			seq.pop_back();
		}
		if (!seq.size()) {
			i = j;
			continue;
		}
		long long tot = 1;
		for (int i = 0; i < seq.size(); i++) {
			if (seq[i] > 0) tot = min(tot * seq[i], (long long)INF);
		}
		if (tot == INF) {
			i = j;
			continue;
		}
		for (int i = 0; i < seq.size(); i += 2) {
			dp[i] = -0x3f3f3f3f;
			int cur = seq[i];
			for (int j = i - 2; j >= 0; j -= 2) {
				if (dp[i] < dp[j] + cur - seq[j + 1]) {
					dp[i] = dp[j] + cur - seq[j + 1];
					lst[i] = j;
				}
				cur *= seq[j];
			}
			if (dp[i] < cur) {
				dp[i] = cur, lst[i] = -1;
			}
		}
		int x = (int)seq.size() - 1;
		while (lst[x] >= 0) {
			int y = lst[x] + 1;
			if (be[y]) b[be[y] - 1] = '+';
			for (int k = be[y]; k < be[y] - seq[y]; k++) {
				b[k] = '+';
			}
			x = y - 1;
		}
		i = j;
	}
	END:;
	cout << a[0];
	for (int i = 1; i < n; i++) {
		cout << b[i - 1] << a[i];
	}
	cout << endl;
	return 0;
}