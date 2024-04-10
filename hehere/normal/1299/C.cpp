#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << a[qwq];\
		else cerr << ", " << a[qwq];\
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

const int maxN = 1000000 + 233;
int n;
LL s[maxN];
vector<int> stk;

bool cross(int i, int j, int k) {
	LL x1 = j - i, x2 = k - j;
	LL y1 = s[j] - s[i], y2 = s[k] - s[j];
	return x1 * y2 - x2 * y1 < 0;
}

int main() {
	n = readint();
	s[0] = 0;
	for(int i = 1; i <= n; ++i) {
		int x = readint();
		s[i] = s[i - 1] + x;
	}
	stk.push_back(0);
	for(int i = 1; i <= n; ++i) {
		while(stk.size() >= 2 && cross(stk[stk.size() - 2], stk.back(), i))
			stk.pop_back();
		stk.push_back(i);
	}
	int last = 0;
	for(int p : stk) if(p) {
		display(p)
//		LL tot = s[p] - s[last];
		double ave = (double)(s[p] - s[last]) / (p - last);
		for(int i = last + 1; i <= p; ++i)
			printf("%.10lf\n", ave);
		last = p;
	}
	return 0;
}