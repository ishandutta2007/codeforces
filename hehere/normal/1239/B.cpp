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

const int maxN = 2 * 300000 + 5;
int n, a[maxN], s[maxN];
int p1[maxN], p2[maxN];

void solve() {
	int min = *min_element(s + 1, s + n + 1);
	int ans = 0, ax = 1, ay = 1;
	for(int i = 1; i <= n; ++i) ans += (s[i] == min);
	int acnt = ans;
	p1[n * 2 + 1] = p2[n * 2 + 1] = 0;
	for(int i = n * 2; i >= 1; --i) {
		p1[i] = p1[i + 1] + (s[i] == min + 1);
		p2[i] = p2[i + 1] + (s[i] == min + 2);
	}
	displaya(s, 1, 2 * n);
	displaya(p1, 1, 2 * n);
	displaya(p2, 1, 2 * n);
	int c1 = 0, c2 = 0;
	for(int i = 1; i <= n; ++i) c1 += (s[i] == min), c2 += (s[i] == min + 1);
	priority_queue<pii> q1, q2;
	for(int i = 1; i < n; ++i) if(a[i] == 1) q1.emplace(p1[i], i), q2.emplace(p2[i], i);
	for(int i = 1, l = 0, r = 0; i <= n; c1 += (s[i] == min), c2 += (s[i] == min + 1), ++i) {
		
		
		
		if(a[i + n - 1] == +1) {
			q1.emplace(p1[i + n - 1], i + n - 1);
			q2.emplace(p2[i + n - 1], i + n - 1);
		}
		
		if(a[i] != -1) continue;
		
		while(c1) {
			++l, c1 -= (s[l] == min);
		}
		while(c2) {
			++r, c2 -= (s[r] == min + 1);
		}
		eprintf("%d %d %d\n", i, l, r);
		while(q1.size() && q1.top().second <= l) q1.pop();
		while(q2.size() && q2.top().second <= r) q2.pop();
		if(q1.size()) {
			int t = q1.top().second;
			if(chmax(ans, p1[t] - p1[i + n])) ax = i, ay = t;
			display(t);
			display(p1[t]);
			display(p1[t] - p1[i + n]);
		}
		if(q2.size()) {
			int t = q2.top().second;
			if(chmax(ans, acnt + p2[t] - p2[i + n])) ax = i, ay = t;
			display(t);
			display(acnt + p2[t] - p2[i + n]);
		}
	}
	cout << ans << endl << ax << ' ' << ((ay - 1) % n + 1) << endl;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	string str;
	cin >> str;
	s[0] = 0;
	for(int i = 1; i <= n; ++i) {
		if(str[i - 1] == '(') a[i] = 1;
		else if(str[i - 1] == ')') a[i] = -1;
		else assert(false);
		a[i + n] = a[i];
	}
	for(int i = 1; i <= n * 2; ++i) s[i] = s[i - 1] + a[i];
	if(s[n] != 0) {
		cout << "0\n1 1\n";
		return 0;
	}
	solve();
	return 0;
}