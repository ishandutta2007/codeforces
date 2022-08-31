#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

typedef long long ll;

struct Node {
	union {
		struct {
			Node *ls, *rs;
		};
		Node* ch[2];
	};

	int cnt;

	int encrypt(int x, int b);
};

const int N = 300010, LGN = 32;

int n;
int a[N];
Node* trie01;

Node* create();

int main() {
	trie01 = create();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		Node* q = trie01;
		for (int j = 29; j >= 0; --j) {
			++q->cnt;
			int bt = (p >> j) & 1;
			if (!q->ch[bt])
				q->ch[bt] = create();
			q = q->ch[bt];
		}
		++q->cnt;
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", trie01->encrypt(a[i], 29));
	}
	return 0;
}

int Node::encrypt(int x, int b) {
	--cnt;
	if (b == -1)
		return 0;
	int bt = (x >> b) & 1;
	if (ch[bt] && ch[bt]->cnt)
		return ch[bt]->encrypt(x, b - 1);
	else
		return ch[!bt]->encrypt(x, b - 1) | (1 << b);
}

Node* create() {
	static Node pool[N * LGN];
	static Node* p = pool;
	return p++;
}