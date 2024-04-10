#include <cstdio>
#include <cstring>

#include <queue>
#include <vector>

#define LOG(FMT...) // fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

struct Node {
	int v;
	int cnt;
	Node* ch[26];
	Node* fail;
};

const int N = 300010, LGN = 20;

int m;
char s[N * 2];
vector<char*> sad[LGN], sdel[LGN];
Node *ad[LGN], *del[LGN];

void build(Node* t);
ll qry(Node* t, char s[]);
void ins(Node* clust[], vector<char*> ss[], char s[]);
void ins(Node* t, char s[]);
ll qry(Node* clust[], char s[]);
Node* create();

int main() {
	char* curs = s;
	scanf("%d", &m);
	while (m--) {
		int t;
		scanf("%d%s", &t, curs);
		switch (t) {
		case 1:
			ins(ad, sad, curs);
			break;
		case 2:
			ins(del, sdel, curs);
			break;
		case 3:
			printf("%lld\n", qry(ad, curs) - qry(del, curs));
			fflush(stdout);
			break;
		}
		curs = curs + strlen(curs) + 1;
	}
	return 0;
}

ll qry(Node* t, char s[]) {
	ll ret = 0;
	for (char* c = s; *c; ++c) {
		t = t->ch[*c - 'a'];
		ret += t->cnt;
	}
	return ret;
}

ll qry(Node* clust[], char s[]) {
	ll ret = 0;
	for (int i = 0; i < LGN; ++i)
		if (clust[i])
			ret += qry(clust[i], s);
	return ret;
}

void build(Node* t) {
	queue<Node*> q;
	q.push(t);
	t->fail = t;
	t->cnt = 0;
	while (!q.empty()) {
		Node* p = q.front();
		q.pop();
		p->cnt = p->v + p->fail->cnt;
		LOG("BD %d(%d)\n", p->cnt, p->v);
		for (int i = 0; i < 26; ++i)
			if (p->ch[i]) {
				if (p == t)
					p->ch[i]->fail = t;
				else
					p->ch[i]->fail = p->fail->ch[i];
				q.push(p->ch[i]);
			} else {
				if (p == t)
					p->ch[i] = t;
				else
					p->ch[i] = p->fail->ch[i];
			}
	}
}

void ins(Node* clust[], vector<char*> ss[], char s[]) {
	int i = 0;
	while (clust[i]) {
		clust[i] = NULL;
		++i;
	}
	LOG("INS BIN %d\n", i);
	for (int j = 0; j < i; ++j) {
		ss[i].insert(ss[i].end(), ss[j].begin(), ss[j].end());
		ss[j].clear();
	}
	ss[i].push_back(s);
	clust[i] = create();
	for (int j = 0; j < (1 << i); ++j)
		ins(clust[i], ss[i][j]);
	build(clust[i]);
}

Node* create() {
	static Node pool[N * LGN];
	static Node* p = pool;
	return p++;
}

void ins(Node* t, char s[]) {
	for (; *s; ++s) {
		if (!t->ch[*s - 'a'])
			t->ch[*s - 'a'] = create();
		t = t->ch[*s - 'a'];
	}
	++t->v;
}