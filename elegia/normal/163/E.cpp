#include <cstdio>

#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int N = 1000010;

int m, n, tcnt = 1;
int trie[N][26];
int fail[N], pos[N], l[N], r[N], fw[N];
bool inc[N];
vector<int> failch[N];
char s[N];

void build();
void dfs(int u);
int lowBit(int x);
void change(int k, int x);
int query(int k);

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s);
		int u = 1;
		for (char* p = s; *p; ++p) {
			if (!trie[u][*p - 'a'])
				trie[u][*p - 'a'] = ++tcnt;
			u = trie[u][*p - 'a'];
		}
		pos[i] = u;
	}
	build();
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		change(l[pos[i]], 1);
		change(r[pos[i]] + 1, -1);
		inc[i] = true;
	}
	while (m--) {
		char opt;
		int u;
		ll ans = 0;
		scanf(" %c", &opt);
		switch (opt) {
			case '-':
				scanf("%d", &u);
				if (!inc[u])
					break;
				change(l[pos[u]], -1);
				change(r[pos[u]] + 1, 1);
				inc[u] = false;
				break;
			case '+':
				scanf("%d", &u);
				if (inc[u])
					break;
				change(l[pos[u]], 1);
				change(r[pos[u]] + 1, -1);
				inc[u] = true;
				break;
			case '?':
				scanf("%s", s);
				u = 1;
				for (char* p = s; *p; ++p) {
					while (!trie[u][*p - 'a'] && u != 1)
						u = fail[u];
					if (trie[u][*p - 'a'])
						u = trie[u][*p - 'a'];
					ans += query(l[u]);
				}
				printf("%lld\n", ans);
				break;
		}
	}
	return 0;
}

void dfs(int u) {
	static int t;
	l[u] = ++t;
	for (int v : failch[u])
		dfs(v);
	r[u] = t;
}

int lowBit(int x) {
	return x & -x;
}

void change(int k, int x) {
	for (; k <= tcnt; k += lowBit(k))
		fw[k] += x;
}

int query(int k) {
	int ret = 0;
	for (; k; k -= lowBit(k))
		ret += fw[k];
	return ret;
}

void build() {
	fail[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front(), v;
		q.pop();
		for (int i = 0; i < 26; ++i)
			if ((v = trie[u][i])) {
				q.push(v);
				fail[v] = fail[u];
				while (!trie[fail[v]][i] && fail[v] != 1)
					fail[v] = fail[fail[v]];
				if (trie[fail[v]][i] && u != 1)
					fail[v] = trie[fail[v]][i];
				failch[fail[v]].push_back(v);
			}
	}
}