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
#ifdef FastInput
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

bool solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i], a[i] = ((a[i] % n + n) % n + i) % n;
	displayv(a);
	return (int) (set<int>(a.begin(), a.end()).size()) == n;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	int T; cin >> T;
	while(T--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}
	return 0;
}