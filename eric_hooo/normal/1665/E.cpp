#include <bits/stdc++.h>
using namespace std;

struct Node {
	int sum;
	Node *ch[2];
	Node() {sum = 0, ch[0] = ch[1] = NULL;}
	void pushup() {
		sum = (ch[0] ? ch[0]->sum : 0) + (ch[1] ? ch[1]->sum : 0);
	}
}POOL[4000010], *CUR = POOL;

int n;
int a[100010];
Node *rt[100010];

void Update(Node *&T, int d, int x, int w) {
	if (!T) T = CUR++;
	else *CUR = *T, T = CUR++;
	if (d == -1) {
		T->sum += w;
		return ;
	}
	Update(T->ch[x >> d & 1], d - 1, x, w);
	T->pushup();
}

int oth[100], N;

void GetAll(Node *L, Node *R, int d, int x) {
	if ((R ? R->sum : 0) - (L ? L->sum : 0) == 0) return ;
	if (d == -1) {
		for (int i = (L ? L->sum : 0); i < (R ? R->sum : 0); i++) {
			oth[N++] = x;
		}
		return ;
	}
	GetAll(L ? L->ch[0] : NULL, R ? R->ch[0] : NULL, d - 1, x);
	GetAll(L ? L->ch[1] : NULL, R ? R->ch[1] : NULL, d - 1, x | 1 << d);
}

int Query(Node *L, Node *R, int d) {
	if (d == -1) return 0;
	int cnt = (R && R->ch[0] ? R->ch[0]->sum : 0) - (L && L->ch[0] ? L->ch[0]->sum : 0);
	for (int i = 0; i < N; i++) {
		cnt += (oth[i] >> d & 1) == 0;
	}
	int cho = cnt > 1 ? 0 : 1;
	if (cho == 0) {
		int NN = 0;
		for (int i = 0; i < N; i++) {
			if ((oth[i] >> d & 1) == cho) oth[NN++] = oth[i];
		}
		N = NN;
	}
	if (cho == 1) GetAll(L ? L->ch[0] : NULL, R ? R->ch[0] : NULL, d - 1, 0);
	return Query(L ? L->ch[cho] : NULL, R ? R->ch[cho] : NULL, d - 1) | cho << d;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		rt[0] = NULL;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			Update(rt[i] = rt[i - 1], 29, a[i], 1);
		}
		int q; scanf("%d", &q);
		while (q--) {
			int l, r; scanf("%d%d", &l, &r);
			N = 0;
			printf("%d\n", Query(rt[l - 1], rt[r], 29));
		}
	}
	return 0;
}