#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int Block = 547;

struct Trie {
	int son[300010][26], val[300010], TOT;
	void clear() {memset(son, -1, sizeof(son)), memset(val, 0, sizeof(val)), TOT = 1;}
	void Update(char *s, int x) {
		int now = 0;
		while (*s != '\0') {
			int &v = son[now][*s - 'a'];
			if (v == -1) v = TOT++;
			now = v, s++;
		}
		val[now] += x;
	}
	long long Query(char *s) {
		long long ans = 0;
		int now = 0;
		while (*s != '\0') {
			int v = son[now][*s - 'a'];
			if (v == -1) break;
			now = v, ans += val[now], s++;
		}
		return ans;
	}
}T;

vector <pair <string, vector <int> > > S;

char s[300010];

vector <int> GetFail(char *s, int n, int coef) {
	vector <int> nxt; nxt.push_back(-1);
	for (int i = 1; i <= n; i++) {
		nxt.push_back(nxt.back());
		while (~nxt.back() && s[nxt.back() + 1] != s[i]) nxt.back() = nxt[nxt.back()];
		nxt.back()++;
	}
	nxt.push_back(coef);
	return nxt;
} 

int main() {
	T.clear();
	int Q; scanf("%d", &Q);
	while (Q--) {
		int op; scanf("%d%s", &op, s + 1);
		int n = strlen(s + 1);
		if (op == 1 || op == 2) {
			if (n <= Block) T.Update(s + 1, op == 1 ? 1 : -1);
			else S.push_back(mp(s + 1, GetFail(s, n, op == 1 ? 1 : -1)));
		} else {
			long long ans = 0;
			for (int i = 1; i <= n; i++) {
				ans += T.Query(s + i);
			}
			for (auto &it : S) {
				auto &t = it.fi; auto &nxt = it.se;
				int coef = nxt.back(), m = t.size(), j = 0;
				for (int i = 1; i <= n; i++) {
					while (~j && (j == m || s[i] != t[j])) j = nxt[j];
					ans += ((++j) == m) * coef;
				}
			}
			printf("%lld\n", ans);
			fflush(stdout);
		}
	}
	return 0;
}