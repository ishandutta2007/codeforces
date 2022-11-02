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
#include <map>
using std::map;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

inline int readint() {
	int a = 0, po = 1; char c = getchar();
	while(isspace(c)) c = getchar();
	if(c == '-') c = getchar(), po = -1;
	while(isdigit(c))a = a*10 + c - '0', c = getchar();
	return a * po;
}

const int maxN = 200000 + 233;
const int maxQ = 200000 + 233;
const LL P = 998244353;
int n, q;

template<int NODE>
struct SegmentTree {
	#define lson (o<<1)
	#define rson (o<<1|1)
private:
	int n;
	LL sum[NODE], k[NODE], b[NODE];
public:
	void init(int n) {
		this->n = n;
		for(int i = 0; i <= 4*n + 5; ++i) sum[i] = b[i] = 0, k[i] = 1;
	}
private:
	void maintain(int o, int L, int R) {
		if(L < R) {
			sum[o] = (sum[lson] + sum[rson]) % P;
		}
	}

	void apply(int o, int L, int R, LL K, LL B) {
		sum[o] = (K * sum[o] + B * (R - L + 1)) % P;
		k[o] = K * k[o] % P;
		b[o] = (K * b[o] + B) % P;
	}

	void pushdown(int o, int L, int R) {
		if(L < R && (k[o] != 1 || b[o] != 0)) {
			int M = (L + R) >> 1;
			apply(lson, L, M, k[o], b[o]);
			apply(rson, M+1, R, k[o], b[o]);
			k[o] = 1; b[o] = 0;
		}
	}

	int ql, qr;
	LL ans, qk, qb;
	void modify(int o, int L, int R) {
		if(ql <= L && R <= qr) {
			apply(o, L, R, qk, qb);
		} else {
			pushdown(o, L, R);
			int M = (L + R) >> 1;
			if(ql <= M) modify(lson, L, M);
			if(qr > M) modify(rson, M + 1, R);
			maintain(o, L, R);
		}
	}

	void query(int o, int L, int R) {
		if(ql <= L && R <= qr) {
			ans = (ans + sum[o]) % P;
		} else {
			pushdown(o, L, R);
			int M = (L + R) >> 1;
			if(ql <= M) query(lson, L, M);
			if(qr > M) query(rson, M + 1, R);
		}
	}
public:
	void modify(int l, int r, LL k, LL b) {
		ql = l; qr = r; qk = k; qb = b;
		modify(1, 1, n);
	}

	LL query(int l, int r) {
		ans = 0; ql = l; qr = r;
		query(1, 1, n);
		return ans;
	}

	#undef lson
	#undef rson
};
SegmentTree<maxN*4> st;
template<int maxN>
struct bf {
	LL a[maxN];
	void init(int n) {
		n = n;
		memset(a, 0, sizeof(a));
	}
	void modify(int l, int r, LL k, LL b) {
		for(int i = l; i <= r; ++i) {
			a[i] = (a[i] * k + b) % P;
		}
	}
	LL query(int l, int r) {
		LL ans = 0;
		for(int i = l; i <= r; ++i) {
			ans = (ans + a[i]) % P;
		}
		return ans;
	}
};
//bf<maxN*4> st;

map <int, set<pii> > M;

void initialize() {
	st.init(n);
	M.clear();
}

/*
10 10
1 7 10 9
1 5 9 9
1 1 5 9
1 1 9 9
*/

void operationM() {
	static vector<pii> adds, muls;
	adds.clear(); muls.clear();
	int l = readint(), r = readint(), x = readint();
	int ml = l, mr = r;
	if(!M.count(x)) { M.insert(std::make_pair(x, set<pii>({pii(-1, -1), pii(maxN, maxN)}))); };
	set<pii> &S = M[x];
	set<pii>::iterator f = S.upper_bound(pii(l, maxN));
	set<pii>::iterator ef = f, er = f; // printf("init = (%d, %d)\n", ef->first, ef->second);
//	printf("set : "); for(pii p : S) printf("(%d, %d) ", p.first, p.second); printf("\n");
	if(f != S.begin()) {
		--f;
		if(l <= f->second) {
			if(r <= f->second) {
				muls.push_back(pii(l, r));
				ml = maxN; mr = -1;
				goto FINAL;
			} else {
				muls.push_back(pii(l, f->second));
				ml = f->first; l = f->second + 1;
				ef = f;
			}
//			printf("ef = (%d, %d)\n", ef->first, ef->second);
		}
		++f;
	}
	while(1) {
//		printf("while 1 : f = (%d, %d) %s\n", f->first, f->second, f == S.begin() ? "begin" : f == S.end() ? "end" : "trival");
		if(r < f->first) {
			adds.push_back(pii(l, r));
			break;
		} else if(r <= f->second) {
			adds.push_back(pii(l, f->first - 1));
			muls.push_back(pii(f->first, r));
			++er;
			mr = f->second;
			break;
		} else {
			adds.push_back(pii(l, f->first - 1));
			++er;
			muls.push_back(pii(f->first, f->second));
			l = f->second + 1;
			++f;
		}
	}
	FINAL:
	
//	printf("erased (%d, %d) to (%d, %d)\n", ef->first, ef->second, er->first, er->second);
	S.erase(ef, er);
	
	if(ml <= mr) S.insert(pii(ml, mr));
	for(pii &p : adds) if(p.first <= p.second) st.modify(p.first, p.second, 1, 1);
	for(pii &p : muls) if(p.first <= p.second) st.modify(p.first, p.second, 2, 0);
//	printf("adds : "); for(const pii &p : adds) printf("(%d, %d) ", p.first, p.second); printf("\n");
//	printf("muls : "); for(const pii &p : muls) printf("(%d, %d) ", p.first, p.second); printf("\n");
}

LL operationQ() {
	int l = readint(), r = readint();
	return st.query(l, r);
}

int main() {
	n = readint(); q = readint();
	initialize();
	for(int kase = 1; kase <= q; ++kase) {
		int opt = readint();
		if(opt == 1) operationM();
		else if(opt == 2) printf("%lld\n", operationQ());
		else assert(false);
	}
	return 0;
}