// Codeforces 482E - ELCA
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const int maxN = 50000 + 233;
const LL maxA = 1000000 + 233;
int n, q;
LL a[maxN], cnt[maxN];
int p[maxN];
LL ans = 0;

namespace LinkCutTree {
	// We ignore pairs like (u, u) in the LCT
	// Take care : Are tags pushed down timely?
	// Or problems are caused only with huge amount of data
	// "nil" is needed to be checked
	// Caution : long long or int
	struct Node;
	Node *nil;
	int cnt_splice = 0;
	struct Node {
		int size;
		LL slope;
		LL sum_slope;
		int tag_dsize;
		LL dtimes;
		Node *fa, *ch[2];

		Node() : size(0), slope(0), sum_slope(0), tag_dsize(0), dtimes(0), fa(nil) { ch[0] = ch[1] = nil; }

		int id() {
			return (int)(this - nil);
		}

		void pushdown() {
			if(tag_dsize) {
				if(ch[0] != nil) {
#ifdef DEBUG
					assert(ch[0]->id() == 1 || ch[0]->slope % a[p[ch[0]->id()]] == 0);
					//check SLOPE == definition
#endif
					ch[0]->size += tag_dsize;
					ch[0]->tag_dsize += tag_dsize;
					ch[0]->id() == 1 || (ch[0]->dtimes += 2LL * tag_dsize * (ch[0]->slope / a[p[ch[0]->id()]]));
				}
				if(ch[1] != nil) {
#ifdef DEBUG
					assert(ch[1]->id() == 1 || ch[1]->slope % a[p[ch[1]->id()]] == 0);
#endif
					ch[1]->size += tag_dsize;
					ch[1]->tag_dsize += tag_dsize;
					ch[1]->id() == 1 || (ch[1]->dtimes += 2LL * tag_dsize * (ch[1]->slope / a[p[ch[1]->id()]]));
				}
				tag_dsize = 0;
			}
		}

		void maintain() {
			sum_slope = slope + ch[0]->sum_slope + ch[1]->sum_slope;
		}

		int relation() {
			return fa->ch[0] == this ? 0 : fa->ch[1] == this ? 1 : -1;
		}

		void rotate() {
			Node *f = fa, *ff = f->fa;
			int d = relation(), dd = f->relation();
			if(dd != -1) ff->ch[dd] = this; fa = ff;
			f->ch[d] = ch[d^1]; ch[d^1]->fa = f;
			ch[d^1] = f; f->fa = this;
			f->maintain(); maintain();
		}

		void splay() {
			static Node *stk[maxN]; int len = 0;
			stk[len++] = this;
			for(Node *o = fa; stk[len-1]->relation() != -1; o = o->fa) stk[len++] = o;
			while(len) stk[--len]->pushdown();

			while(relation() != -1) {
				Node *f = fa;
				if(f->relation() == -1) rotate();
				else if(relation() == f->relation()) f->rotate(), rotate();
				else rotate(), rotate();
			}
		}

		Node *outer_leftmost() {
			Node *o = this;
			while(o->relation() != -1) o = o->fa;
			o->pushdown();
			while(o->ch[0] != nil) o = o->ch[0], o->pushdown();
			return o;
		}

		Node *leftmost() {
			Node *o = this;
			o->pushdown();
			while(o->ch[0] != nil) o = o->ch[0], o->pushdown();
			return o;
		}

		Node *rightmost() {
			Node *o = this;
			o->pushdown();
			while(o->ch[1] != nil) o = o->ch[1], o->pushdown();
			return o;
		}

		void access() {
			Node *o = this;
			o->splay(); o->lighten_son();
			o->maintain();
			cnt_splice = 0;
			while(1) {
				o = o->outer_leftmost(); o->splay();
				if(o->fa == nil) break;
				++cnt_splice;
				Node *f = o->fa; f->splay();
				f->lighten_son();
				f->strengthen_son(o);
			}
		}

		void lighten_son() {
			splay();
			if(ch[1] == nil) return;
			Node *son = ch[1]->leftmost();
			ch[1] = nil; son->splay();
//			id() == 1 && printf("%d : lighten_son %d : cnt += %lld\n", id(), son->id(), son->dtimes);
			cnt[id()] += son->dtimes; son->dtimes = 0;
			son->slope = 0;
			son->maintain(); maintain();
		}

		void strengthen_son(Node *son) {
			splay();
#ifdef DEBUG
			assert(ch[1] == nil);
			assert(son->fa == this);
#endif
			son->splay();
			ch[1] = son;
			son->slope = (size - son->size) * a[id()];
//			printf("%d : (Strengthen son %d)   slope = %lld\n", id(), son->id(), son->slope);
			son->maintain(); maintain();
		}

		void disconnect_son(Node *son) {
			access(); splay();
#ifdef DEBUG
			assert(ch[1] == nil);
			assert(son->fa == this);
#endif
//			printf("Disconnect (%d, %d) : d_ans = %lld = %lld * %lld doubled\n", id(), son->id(), sum_slope * son->size * 2, sum_slope, (LL)son->size);
			ans -= sum_slope * son->size * 2;
			size -= son->size; tag_dsize -= son->size;
			id() == 1 || (dtimes -= 2LL * son->size * (slope / a[p[id()]]));
//			printf("                          + %lld = %lld * %lld * %lld doubled\n", son->size * (LL)size * a[id()] * 2, sum_slope, (LL)son->size, a[id()]);
			ans -= son->size * (LL)size * a[id()] * 2;
//			id() == 1 && printf("%d : disconnect_son %d : cnt += %lld + %lld\n", id(), son->id(), -son->size * (LL)size * 2LL, son->dtimes);
			cnt[id()] += -son->size * (LL)size * 2LL + son->dtimes;
			son->fa = nil;
		}

		void connect_son(Node *son) {
			access(); splay();
//			printf("Connect (%d, %d) : d_ans = %lld = %lld * %lld doubled\n", id(), son->id(), sum_slope * son->size * 2, sum_slope, (LL)son->size);
			ans += sum_slope * son->size * 2;
//			printf("                       + %lld = %lld * %lld * %lld doubled\n", son->size * (LL)size * a[id()] * 2, sum_slope, (LL)son->size, a[id()]);
			ans += son->size * (LL)size * a[id()] * 2;
//			id() == 1 && printf("%d : connect %d : cnt += %lld\n", id(), son->id(), son->size * (LL)size * 2LL);
			cnt[id()] += son->size * (LL)size * 2LL;
			size += son->size; tag_dsize += son->size;
			id() == 1 || (dtimes += 2LL * son->size * (slope / a[p[id()]]));
			son->fa = this;
		}

	} nodes[maxN];

	void init_lct() {
		nil = nodes;
		*nil = Node();
	}

}
using namespace LinkCutTree;

vector<int> G[maxN];
void dfs(int u) {
	nodes[u].size = 1;
	cnt[u] = 1;
	for(int v : G[u]) {
		dfs(v);
		cnt[u] += nodes[v].size * nodes[u].size;
		nodes[u].size += nodes[v].size;
	}
	cnt[u] = cnt[u] * 2 - 1;
	ans += cnt[u] * a[u];
}

void initialize() {
	scanf("%d", &n);
	init_lct();
	for(int u = 1; u <= n; ++u) nodes[u] = Node();
	p[1] = -maxN; // to cause error
	for(int u = 2; u <= n; ++u) {
		scanf("%d", &p[u]);
		(&nodes[u])->fa = (&nodes[p[u]]);
		G[p[u]].push_back(u);
	}
	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	dfs(1);
//	printf("cnt = {"); for(int i = 1; i <= n; ++i) printf("%lld ", cnt[i]); printf("}\n");
	printf("%.13lf\n", (double)ans / (double)((LL)n * n));
//	printf("%lld\n", ans);
}

void modify_father(int x, int y) { // operate p[u] = v
//	printf("p[%d] = %d\n", x, y);
	Node *u = &nodes[x], *v = &nodes[y];
	// disconnect u and father
	(&nodes[p[x]])->lighten_son();
	(&nodes[p[x]])->disconnect_son(u);
	v->connect_son(u);
	p[x] = y;
}

/*
5
1 2 2 1
1 2 3 4 5
5
P 3 4
P 4 5
V 2 3
P 5 2
P 1 4

1.64 = 41
1.80 = 45
2.28 = 57
2.32 = 58
2.80 = 70
1.84 = 46

5
1 2 2 1
1 2 3 4 5
5
P 3 4
P 4 5
V 2 3
P 5 2
P 1 4

5
1 2 2 1
1 2 3 4 5
5
P 3 4
P 4 5
V 2 3
P 5 2
P 1 4

*/

void P_operation(int x, int y) {
	Node *v = &nodes[x], *u = &nodes[y];
	u->access(); v->access();
	if(cnt_splice) { // u not in subtree of v, p[v] = u
		modify_father(x, y);
//		printf("CASE 1\n");
	} else { // else p[u] = v;
		modify_father(y, x);
//		printf("CASE 2\n");
	}
}

void V_operation(int x, int val) {
	Node *u = &nodes[x];
	u->lighten_son();
	if(u->ch[0] != nil) {
		u->ch[0]->rightmost()->lighten_son();
	}
	ans += (val - a[x]) * cnt[x];
	a[x] = val;
	u->maintain();
}

void solve() {
	scanf("%d", &q);
	for(int kase = 1; kase <= q; ++kase) {
		char opt;
		scanf(" %c", &opt);
		if(opt == 'P') {
			int v, u;
			scanf("%d%d", &v, &u);
			P_operation(v, u);
		} else if(opt == 'V') {
			int u, x;
			scanf("%d%d", &u, &x);
			V_operation(u, x);
		} else {
			assert(false);
		}
		printf("%.13lf\n", (double)ans / (double)((LL)n * n));
//		printf("%lld\n", ans);
	}
}

int main() {
//	printf("%.3lfMB\n", sizeof(nodes) / 1000.0 / 1000.0);
	initialize();
	solve();
	return 0;
}