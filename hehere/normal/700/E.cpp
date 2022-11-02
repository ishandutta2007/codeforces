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
#include <sstream>
#include <string>
#include <utility>
#include <vector>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
using std::cin; using std::cout;
using std::endl;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::stringstream; using std::vector;
using std::pair; using std::make_pair;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
#ifdef DEBUG
using std::cerr;
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)                      \
	{                                           \
		cerr << #a << " = {";                   \
		for (int qwq = (st); qwq <= (n); ++qwq) \
			if (qwq == (st))                    \
				cerr << a[qwq];                 \
			else                                \
				cerr << ", " << a[qwq];         \
		cerr << "}" << endl;                    \
	}
#define displayv(a) displaya(a, 0, (int)(a.size() - 1))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#include <ctime>
class MyTimer {
	clock_t st;
public:
	MyTimer() { cerr << std::fixed << std::setprecision(0); reset(); }
	~MyTimer() { report(); }
	void reset() { st = clock_t(); }
	void report() {  cerr << "Time consumed: " << (clock() - st) * \
		1e3 / CLOCKS_PER_SEC << "ms" << endl; }
} myTimer;
#else
#define cerr if(false) std::cout
#define pass ;
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(a) ;
#define eprintf(...) if(0) fprintf(stderr, __VA_ARGS__)
class MyTimer {
public: void reset() {} void report() {}
} myTimer;
#endif

template<typename A, typename B>
std::ostream& operator << (std::ostream &cout, const pair<A, B> &x) {
	return cout << "(" << x.first << ", " << x.second << ")";
}
template<typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) { return a > b ? a = b, true : false; }
template<typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) { return a < b ? a = b, true : false; }

const int maxN = 200000 + 233;
int n;
char s[maxN];

struct Tree {
	int sz;
	Tree *lson, *rson;
	Tree() : sz(0), lson(nullptr), rson(nullptr) {}
};
Tree *create() {
	static Tree *pool; static int len = 0;
	if(len == 0) pool = new Tree[65536], len = 65536;
	return pool + (--len);
}
void insert(Tree* &t, int L, int R, int val) {
	if(t == nullptr) t = create();
	t->sz += 1;
	if(L < R) {
		int M = (L + R) >> 1;
		if(val <= M) insert(t->lson, L, M, val);
		else insert(t->rson, M + 1, R, val);
	}
}
Tree *merge(Tree *x, Tree *y, int L, int R) {
	if(x == nullptr) return y;
	else if(y == nullptr) return x;
	Tree *u = create(); *u = *x; u->sz += y->sz;
	if(L < R) {
		int M = (L + R) >> 1;
		u->lson = merge(x->lson, y->lson, L, M);
		u->rson = merge(x->rson, y->rson, M + 1, R);
	}
	return u;
}
bool query(Tree *o, int L, int R, int ql, int qr) {
	if(o == nullptr || o->sz == 0) return false;
	if(ql <= L && R <= qr) return true;
	else {
		int M = (L + R) >> 1;
		bool flag = false;
		if(ql <= M) flag = flag || query(o->lson, L, M, ql, qr);
		if(qr > M) flag = flag || query(o->rson, M + 1, R, ql, qr);
		return flag;
	}
}

struct SuffixAutomaton {
	struct Node {
		Node *last, *ch[26];
		int len;
		int endpos;
		int f; Node *top;
		Tree *t;
		Node(int len = 0) : len(len) {
			last = nullptr;
			memset(ch, 0, sizeof(ch));
			endpos = -1;
			f = 0; top = nullptr;
			t = nullptr;
		}
	} *root, *now, *newnode, pool[maxN * 2];
	
	void init() {
		newnode = pool;
		root = now = newnode++;
		*root = Node(0);
	}
	
	void extend(int c, int l) {
		Node *p = newnode++; *p = Node(l); std::swap(p, now);
		for(; p && p->ch[c] == nullptr; p = p->last) p->ch[c] = now;
		if(p == nullptr) { now->last = root; return; }
		
		Node *q = p->ch[c];
		if(q->len == p->len + 1) {
			now->last = q;
		} else {
			Node *clone = newnode++;
			*clone = *q;
			clone->len = p->len + 1;
			q->last = clone; now->last = clone;
			for(; p && p->ch[c] == q; p = p->last) p->ch[c] = clone;
		}
	}
	
	void print() {
		for(Node *u = root; u < newnode; ++u) {
			printf("%lld: len = %d, last = %lld\n", u - pool, u->len, u->last - pool);
		}
	}
	
	int cnt;
	Node *p[maxN * 2];
	void build() {
		Node *u = root;
		for(int i = 0; i < n; ++i) {
			int c = s[i] - 'a';
			u = u->ch[c];
			insert(u->t, 0, n - 1, i);
			u->endpos = i;
		}
		// Let me practice this radix sort!
		static int buc[maxN]; memset(buc, 0, sizeof(buc));
		cnt = newnode - root - 1;
		for(Node *u = root + 1; u < newnode; ++u) buc[u->len]++;
		for(int i = 1; i <= n; ++i) buc[i] += buc[i - 1];
		assert(buc[n] == cnt);
		for(Node *u = root + 1; u < newnode; ++u) p[--buc[u->len]] = u;
		for(int i = cnt - 1; i >= 0; --i) {
			Node *u = p[i];
			u->last->t = merge(u->last->t, u->t, 0, n - 1),
			u->last->endpos = u->endpos,
			u->top = root, u->f = 0;
//			printf("%lld -> go[%c] = %lld\n", u->last - pool, s[u->endpos - u->last->len], u - pool);
			// Maybe this part can be slightly optimized...
		}
		root->top = root; root->f = 0;
	}
	
	int DP() {
		int ans = 0;
		for(int i = 0; i < cnt; ++i) {
			Node *u = p[i]; u->top = u->last->top;
			int e = u->endpos;
			if(u->top == root) u->top = u, u->f = 1;
			else if(query(u->top->t, 0, n - 1, e - u->len + u->top->len, e - 1)) u->f = u->top->f + 1, u->top = u;
			else u->f = u->top->f;
			chmax(ans, u->f);
		}
		return ans;
	}
	
} sam;

int main() {
	cerr << sizeof(sam) / 1e6 << "MB\n";
	scanf("%d", &n);
	scanf("%s", s);
	sam.init();
	for(int i = 0; i < n; ++i) sam.extend(s[i] - 'a', i + 1);
//	sam.print();
	sam.build();
	printf("%d\n", sam.DP());
	return 0;
}