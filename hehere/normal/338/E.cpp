#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using U = unsigned int;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using std::cin; using std::cout;
using std::endl; using std::cerr;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::vector;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;
#ifdef LOCAL
#include <ctime>
void displayTime() { cout << "Current time = " << clock() * 1e3 / CLOCKS_PER_SEC << "ms" << endl; }
#else
void displayTime() {}
#endif
#ifdef DEBUG
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n) { cerr << #a << " = {"; \
      for(int qwq = (st); qwq <= (n); ++qwq) cerr << a[i] << (qwq == n ? ' ' : '\n'); }
#else
#define pass ;
#define display(x) ;
#define displaya(a, st, n) {}
#endif

template<typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) { return a > b ? a = b, true : false; }
template<typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) { return a < b ? a = b, true : false; }
#ifdef QUICK_READ
char pool[1<<15|1],*it=pool+32768;
#define getchar() (it>=pool+32768?(pool[fread(pool,sizeof(char),1<<15,stdin)]=EOF,*((it=pool)++)):*(it++))
#endif
inline int readint() {
  int a = 0; char c = getchar(), p = 0;
  while(isspace(c)) c = getchar();
  if(c == '-') p = 1, c = getchar();
  while(isdigit(c)) a = a*10 + c - '0', c = getchar();
  return p ? -a : a;
}
inline LL readLL() {
  LL a = 0; char c = getchar(), p = 0;
  while(isspace(c)) c = getchar();
  if(c == '-') p = 1, c = getchar();
  while(isdigit(c)) a = a*10 + c - '0', c = getchar();
  return p ? -a : a;
}

const int maxN = 150000 + 5;
const int INF = 0x3f3f3f3f;
int n, len, h;
int a[maxN], b[maxN];

static U seed = 233333333;
static U up_seed = 12333333;


struct Node;
static Node *nil;

struct Node {
	pii pos; // {pos, rank - pos}
	int tag, min, size;
	U r;
	Node *ch[2];
	Node(pii p = pii(0, INF)) : pos(p), tag(0), min(p.second), size(1), r(seed *= up_seed) { ch[0] = ch[1] = nil; }
	void maintain() {
		size = 1 + ch[0]->size + ch[1]->size;
		min = pos.second; chmin(min, ch[0]->min); chmin(min, ch[1]->min);
	}
	void apply(int t) {
		if(this != nil) { pos.second += t; min += t; tag += t; }
	}
	void pushdown() {
		if(tag) {
			ch[0]->apply(tag);
			ch[1]->apply(tag);
			tag = 0;
		}
	}

	void print(int d, const char *s = "") {
		if(d == 0) printf("=====%5s=====\n", s);
		for(int i = 0; i < d; ++i) printf("  ");
		if(this == nil) {
			printf("nil\n");
		} else {
//			pushdown();
//			assert(size == ch[0]->size + ch[1]->size + 1);
//			assert(min == std::min({pos.second, ch[0]->min, ch[1]->min}));
			printf("pos = %d, rk - pos = %d, tag = %d, min = %d, size = %d, ch = {%lld, %lld}\n",
			pos.first, pos.second, tag, min, size, (LL)(ch[0L] - nil), (LL)(ch[1L] - nil));
			ch[0]->print(d + 1);
			ch[1]->print(d + 1);
		}
		if(d == 0) printf("===============\n");
	}
};
template<int NODE>
struct Treap {

	Node *root;
	Node nodes[NODE];
	int cnt;

	void init() {
		nil = root = nodes;
		*nil = Node(); nil->size = 0;
		cnt = 1;
	}

	void rotate(Node *&o, int d) {
		Node *k = o->ch[d^1];
		o->ch[d^1] = k->ch[d]; k->ch[d] = o;
		o->maintain(); k->maintain();
		o = k;
	}

	void insert(Node *&o, const pii &pos) {
		if(o == nil) {
			o = &nodes[cnt++];
			*o = Node(pos);
		} else {
			o->pushdown();
			int d = pos <= o->pos ? 0 : 1;
			insert(o->ch[d], pos);
			if(o->ch[d]->r < o->r) rotate(o, d^1);
			o->maintain();
		}
	}

	void insert(int pos, int dif) {
		insert(root, pii(pos, dif));
	}

	void split(Node *o, const pii &pos, Node *&L, Node *&R) {
		if(o == nil) L = R = nil;
		else if(o->pos <= pos) {
			o->pushdown();
			L = o;
			split(o->ch[1], pos, L->ch[1], R);
			L->maintain();
		} else {
			o->pushdown();
			R = o;
			split(o->ch[0], pos, L, R->ch[0]);
			R->maintain();
		}
	}

	Node *splitone(Node *&o) {
#ifdef DEBUG
		assert(o != nil);
#endif
		if(o->size == 1) {
			Node *r = o;
			o = nil;
			return r;
		} else {
			o->pushdown();
			Node *ret;
			if(o->ch[0]->size) {
				ret = splitone(o->ch[0]);
			} else {
				ret = o;
				o = o->ch[1];
				o->pushdown();
			}
			o->maintain();
			return ret;
		}
	}

	Node *merge(Node *L, Node *R) {
		if(L == nil) return R;
		else if(R == nil) return L;
		else if(L->r < R->r) {
			L->pushdown();
			L->ch[1] = merge(L->ch[1], R);
			L->maintain();
			return L;
		} else {
			R->pushdown();
			R->ch[0] = merge(L, R->ch[0]);
			R->maintain();
			return R;
		}
	}

};
Treap<maxN> treap;
int ans = 0;

int get_first(int x) {
//	printf("first[%d] = %d\n", x,
//		(int)(std::lower_bound(b + 1, b + len + 1, h - x) - b));
	return std::lower_bound(b + 1, b + len + 1, h - x) - b;
}

void init_treap() {
	static int t[maxN];
	for(int i = 1; i <= len; ++i) t[i] = a[i];
	std::sort(t + 1, t + len + 1);
	std::reverse(t + 1, t + len + 1);
	treap.init();
	for(int i = 1; i <= len; ++i) {
		treap.insert(get_first(t[i]), i - get_first(t[i]));
	}
	bool f = treap.root->min >= 0;
	ans += f;
//	printf("%d\n", treap.root->min);
}

/*
10 5 10
8 4 6 3 6
2 8 5 6 4 7 5 8 6 7
*/

bool judge(int st) {
	static int t[maxN];
	for(int i = 1; i <= len; ++i) t[i] = a[st + i - 1];
	std::sort(t + 1, t + len + 1);
	for(int i = 1, j = len; i <= len && j >= 1; ++i, --j) if(t[i] + b[j] < h) return false;
	return true;
}

int sol() {
	int ans = 0;
	for(int i = 1; i <= n - len + 1; ++i) ans += judge(i);
	return ans;
}


int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> len >> h;
	for(int i = 1; i <= len; ++i) cin >> b[i];
	for(int i = 1; i <= n; ++i) cin >> a[i];
//	for(int i = 1; i <= len; ++i) b[i] = rand() % (h / 3) + rand() % h + 1;
//	for(int i = 1; i <= n; ++i) a[i] = rand() % (h / 3) + rand() % h + 1;
	std::sort(b + 1, b + len + 1);

	init_treap();
	for(int i = 2; i <= n - len + 1; ++i) {
//		char st[100]; sprintf(st, "Round.%d", i);
//		treap.root->print(0, st);
		int x = a[i - 1], y = a[i + len - 1];
		x = get_first(x); y = get_first(y);
		if(x == y) {
			// :P
		} else if(x < y) {
			Node *L, *M, *R;
			treap.split(treap.root, pii(x - 1, INF), L, M);
			treap.split(M, pii(y - 1, INF), M, R);
			Node *t = treap.splitone(M); assert(t->pos.first == x);
			M->apply(-1);
			treap.insert(M, pii(y, L->size + M->size + 1 - y));
			treap.root = treap.merge(L, treap.merge(M, R));
		} else {
			Node *L, *M, *R;
			treap.split(treap.root, pii(y - 1, INF), L, M);
			treap.split(M, pii(x - 1, INF), M, R);
			Node *t = treap.splitone(R); assert(t->pos.first == x);
			M->apply(+1);
			treap.insert(M, pii(y, L->size + 1 - y));
			treap.root = treap.merge(L, treap.merge(M, R));
		}
		ans += (treap.root->min >= 0);
	}
	cout << ans << endl;
	return 0;
}