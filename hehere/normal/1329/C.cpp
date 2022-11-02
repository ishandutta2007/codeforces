#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << (x) << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << ((a)[qwq]);\
		else cerr << ", " << ((a)[qwq]);\
	} cerr << "}" << endl;}
#define displayv(v) displaya(v, 0, (int)(v).size() - 1)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(v) ;
#define eprintf(...) if(0) fprintf(stderr, "...")
#endif
template<typename T> bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }
template<typename A, typename B>
ostream& operator << (ostream& out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
#ifndef LOCAL
char pool[1<<15|1],*it=pool+32768;
#define getchar() (it>=pool+32768?(pool[fread(pool,sizeof(char),\
	1<<15,stdin)]=EOF,*((it=pool)++)):*(it++))
#endif
inline int readint() {
	int a = 0; char c = getchar(), p = 0;
	while(isspace(c)) c = getchar();
	if(c == '-') p = 1, c = getchar();
	while(isdigit(c)) a = a*10 + c - '0', c = getchar();
	return p ? -a : a;
}

const int maxN = (1 << 20) + 5;
int h, g, a[maxN * 2];
int sz[maxN * 2], sg[maxN * 2];

vector<int> seq;
int now;
bool remove(int u, int p) { // p = 0 => now = p
//	eprintf("remove %d %d\n", u, p);
	sz[u]--;
	int t = (a[u * 2 + 1] > a[u * 2]);
	bool r;
	if(sz[u * 2 + t] > sg[u * 2 + t]) {
		r = remove(u * 2 + t, 1);
		if(r && p == 0) {
			assert(now == -1);
			now = u;
		}
		return r;
	} else if(sz[u * 2 + !t] > sg[u * 2 + !t]) {
		r = remove(u * 2 + !t, 0);
		return false;
	} else {
		assert(a[u * 2] == 0);
		assert(a[u * 2 + 1] == 0);
		if(p == 0) {
			assert(now == -1);
			now = u;
		}
		return true;
	}
}

void play(int u) {
	if(a[u * 2] == 0 && a[u * 2 + 1] == 0) a[u] = 0;
	else if(a[u * 2] > a[u * 2 + 1]) {
		a[u] = a[u * 2];
		play(u * 2);
	} else {
		a[u] = a[u * 2 + 1];
		play(u * 2 + 1);
	}
}

void solve() {
	h = readint(), g = readint();
	for(int i = 1; i <= (1 << (h + 1)); ++i) a[i] = 0;
	for(int i = 1; i <= (1 << h) - 1; ++i) a[i] = readint();
	for(int i = (1 << h) - 1; i >= 1; --i) {
		sz[i] = 1;
		if(2 * i <= (1 << h) - 1) sz[i] += sz[2 * i];
		if(2 * i + 1 <= (1 << h) - 1) sz[i] += sz[2 * i + 1];
		sg[i] = 0;
	}
	for(int i = (1 << g) - 1; i >= 1; --i) {
		sg[i] = 1;
		if(2 * i <= (1 << g) - 1) sg[i] += sg[2 * i];
		if(2 * i + 1 <= (1 << g) - 1) sg[i] += sg[2 * i + 1];
	}
	seq.clear();
	while(sz[1] > sg[1]) {
		now = -1;
		bool r = remove(1, 0);
		assert(now != -1);
		play(now);
		seq.push_back(now);
//		displaya(a, 1, (1 << h) - 1);
//		displaya(sz, 1, (1 << h) - 1);
	}
	printf("%lld\n", accumulate(a + 1, a + (1 << g), 0LL));
	for(int i = 0; i < (int)seq.size(); ++i) {
		printf("%d%c", seq[i], " \n"[i + 1 == (int)seq.size()]);
	}
}

int main() {
	int T = readint();
	while(T--) solve();
	return 0;
}