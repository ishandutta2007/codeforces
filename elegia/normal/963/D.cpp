#include <cstdio>
#include <cstring>

#include <deque>
#include <queue>

using namespace std;

struct Node {
	int v;
	Node* ch[26];
	Node *fail, *lst;
};

const int N = 100010;

int len, n;
int k[N], l[N], ans[N];
deque<int> tail[N];
char s[N], str[N];
Node* ac;

Node* create();
void build();

int main() {
	scanf("%s%d", str + 1, &n);
	len = strlen(str + 1);
	ac = create();
	for (int i = 1; i <= n; ++i) {
		scanf("%d%s", &k[i], s + 1);
		l[i] = strlen(s + 1);
		Node* p = ac;
		for (char* c = s + 1; *c; ++c) {
			if (!p->ch[*c - 'a'])
				p->ch[*c - 'a'] = create();
			p = p->ch[*c - 'a'];
		}
		p->v = i;
	}
	build();
	memset(ans, -1, sizeof(ans));
	Node* p = ac;
	for (char* c = str + 1; *c; ++c) {
		p = p->ch[*c - 'a'];
		Node* q = p->v ? p : p->lst;
		while (q) {
			int id = q->v;
			tail[id].push_back(c - str);
			if (tail[id].size() > k[id])
				tail[id].pop_front();
			if (tail[id].size() == k[id]) {
				if (ans[id] == -1 || ans[id] > (tail[id].back() - tail[id].front() + l[id]))
					ans[id] = tail[id].back() - tail[id].front() + l[id];
			}
			q = q->lst;
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}

Node* create() {
	static Node pool[N];
	static Node* p = pool;
	return p++;
}

void build() {
	queue<Node*> q;
	q.push(ac);
	ac->fail = ac;
	while (!q.empty()) {
		Node* p = q.front();
		q.pop();
		if (p->fail->v)
			p->lst = p->fail;
		else
			p->lst = p->fail->lst;
		for (int i = 0; i < 26; ++i)
			if (!p->ch[i]) {
				if (p == ac)
					p->ch[i] = p;
				else
					p->ch[i] = p->fail->ch[i];
			} else {
				if (p == ac)
					p->ch[i]->fail = ac;
				else
					p->ch[i]->fail = p->fail->ch[i];
				q.push(p->ch[i]);
			}
	}
}