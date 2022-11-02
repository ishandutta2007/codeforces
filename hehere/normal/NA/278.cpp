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
//mt19937 e(2333);
inline int readint() {
//	return e() % 500000 + 1;
	int a = 0; char c = getchar(), p = 0;
	while(isspace(c)) c = getchar();
	if(c == '-') p = 1, c = getchar();
	while(isdigit(c)) a = a*10 + c - '0', c = getchar();
	return p ? -a : a;
}


const int maxN = 500000 + 5;
const int maxA = 1000000 + 5;
const int B = 2000;
const int C = maxN / B + 5;
int n, q, a[maxN];
int lb[C], rb[C], id[maxN], cnt, mx[C], mn[C];
int up[C][B], down[C][B], len[C];
// up = min, down = max, both decreasing

void rebuild(int t) {
	int *a = ::a + lb[t] - 1;
	int n = rb[t] - lb[t] + 1;
	int *up = ::up[t], *down = ::down[t], &len = ::len[t]; len = 0;
	len = 0;
	static int mx[B + 5];
//	mn[0] = maxA + 1;
//	for(int i = 1; i <= n; ++i) mn[i] = min(mn[i - 1], a[i]);
	mx[n + 1] = -1;
	for(int i = n; i >= 1; --i) mx[i] = max(mx[i + 1], a[i]);
	int mn = maxA + 1;
	for(int i = 1; i <= n; chmin(mn, a[i]), ++i) if(mn > mx[i]) {
//		up.push_back(mn[i - 1]);
//		down.push_back(mx[i]);
		up[len] = mn;
		down[len] = mx[i];
		++len;
	}
	::mx[t] = mx[1]; ::mn[t] = mn;
}

int count(int t, int mn, int mx) {
	if(mn < mx) return 0;
	if(mx > up[t][0] || down[t][len[t] - 1] > mn) return 0;
	int i = mn > up[t][0] ? 0 : lower_bound(up[t], up[t] + len[t], mn, greater<int>()) - up[t];
	int j = mx < down[t][len[t] - 1] ? len[t] : lower_bound(down[t], down[t] + len[t], mx, greater<int>()) - down[t];
	--i;
	if(i == j) return 1;
	else if(i < j) return j - i - 1
		+ (i >= 0 ? int(min(up[t][i], mn) > down[t][i]) : 0)
		+ (j < len[t] ? int(up[t][j] > max(down[t][j], mx)) : 0);
	else assert(false);
	return -1;
}

int solve() {
	static int mx[C], mn[C];
	mn[0] = maxA;
	for(int i = 1; i <= cnt; ++i) mn[i] = min(mn[i - 1], ::mn[i]);
	mx[cnt + 1] = 0;
	for(int i = cnt; i >= 1; --i) mx[i] = max(mx[i + 1], ::mx[i]);
	int ans = 0;
	for(int i = 1; i <= cnt; ++i) ans += count(i, mn[i - 1], mx[i + 1]);
	return ans;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	n = readint(); q = readint();
//	n = 500000; q = 500000;
	for(int i = 1; i <= n; ++i) a[i] = readint();
//	for(int i = 1; i <= n; ++i) a[i] = 1000000 - i;
	{
		cnt = 0;
		int rg = 1;
		while(rg <= n) {
			++cnt;
			lb[cnt] = rg; rb[cnt] = min(n, rg + B - 1);
			rg = rb[cnt] + 1;
			for(int i = lb[cnt]; i <= rb[cnt]; ++i)
				id[i] = cnt;
		}
	}
	for(int i = 1; i <= cnt; ++i) rebuild(i);
//	LL ans = 0;
	while(q--) {
		int p = readint(), x = readint();
		a[p] = x; rebuild(id[p]);
		printf("%d\n", solve());
//		rebuild(1);
//		ans ^= solve();
	}
//	display(ans);
	return 0;
}