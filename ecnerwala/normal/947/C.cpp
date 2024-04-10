#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;
int N;

int A[MAXN];
int P[MAXN];

const int D = 30;
const int MAXV = MAXN * D;
int V = 1;
struct trie {
	int cnt;
	trie* ch[2];
} nodes[MAXV];

trie * const ROOT = &nodes[0];

void insert_node(int a) {
	trie *cur = ROOT;
	cur->cnt ++;
	for (int i = D-1; i >= 0; i--) {
		int b = (a >> i) & 1;
		if (cur->ch[b] == nullptr) {
			cur->ch[b] = &nodes[V++];
		}
		cur = cur->ch[b];
		cur->cnt ++;
	}
}

int find_and_delete(int a) {
	trie *cur = ROOT;
	assert(cur->cnt > 0);
	cur->cnt --;
	for (int i = D-1; i >= 0; i--) {
		int b = (a >> i) & 1;
		if (cur->ch[b] != nullptr && cur->ch[b]->cnt > 0) {
			cur = cur->ch[b];
			a ^= b << i;
		} else {
			a ^= (!b) << i;
			cur = cur->ch[!b];
		}
		assert(cur->cnt > 0);
		cur->cnt --;
	}
	return a;
}

int main() {
	memset(nodes, 0, sizeof(nodes));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
		insert_node(P[i]);
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", find_and_delete(A[i]));
	}
	return 0;
}