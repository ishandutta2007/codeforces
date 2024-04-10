#include <cstdio>

#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

struct Node {
	int v;
	Node* ch[2];
	Node* fail;
};

const int N = 2e5 + 10;

int n, m;
char s[N], t[N];
int mto[N][26];
bool f[N];

Node* ac;

Node* create();
void build();

int main() {
	scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
	for (int i = 1; i <= n; ++i)
		s[i] -= 'a';
	for (int i = 1; i <= m; ++i)
		t[i] -= 'a';
	ac = create();
	for (int c = 0; c < 26; ++c) {
		if (count(t + 1, t + m + 1, c) == 0)
			continue;
		Node* p = ac;
		for (int i = 1; i <= m; ++i) {
			int k = t[i] == c;
			if (!p->ch[k])
				p->ch[k] = create();
			p = p->ch[k];
		}
		p->v = c;
	}
	build();
	fill(f + m, f + n + 1, true);
	for (int c = 0; c < 26; ++c) {
		Node* p = ac;
		int cnt = 0;
		for (int i = 1; i < m; ++i) {
			p = p->ch[s[i] == c];
			cnt += s[i] == c;
		}
		for (int i = m; i <= n; ++i) {
			p = p->ch[s[i] == c];
			mto[i][c] = p->v;
			cnt += s[i] == c;
			if (p->v == -1 && cnt != 0)
				f[i] = false;
			cnt -= s[i - m + 1] == c;
		}
	}
	for (int i = m; i <= n; ++i)
		for (int c = 0; c < 26; ++c)
			if (mto[i][c] != -1)
				f[i] &= mto[i][mto[i][c]] == c || mto[i][mto[i][c]] == -1;
	printf("%lu\n", count(f + m, f + n + 1, true));
	for (int i = m; i <= n; ++i)
		if (f[i])
			printf("%d ", i - m + 1);
	return 0;
}

Node* create() {
	static Node pool[N * 26];
	static Node* p = pool;
	p->v = -1;
	return p++;
}

void build() {
	queue<Node*> q;
	ac->fail = ac;
	q.push(ac);
	while (!q.empty()) {
		Node* p = q.front();
		q.pop();
		for (int i = 0; i < 2; ++i)
			if (!p->ch[i]) {
				if (p == ac)
					p->ch[i] = ac;
				else
					p->ch[i] = p->fail->ch[i];
			} else {
				if (p == ac)
					p->ch[i]->fail = ac;
				else {
					p->ch[i]->fail = p->fail->ch[i];
				}
				q.push(p->ch[i]);
			}
	}
}