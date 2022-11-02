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

const int maxN = 100000 + 5;
int n;
LL per, t[maxN], ans[maxN];
int C[maxN];
vector<int> p;
void add(int p, int x) {
	for(; p <= n; p += p & -p) C[p] += x;
}
int sum(int p) {
	int r = 0;
	for(; p > 0; p -= p & -p) r += C[p];
	return r;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n >> per;
	for(int i = 1; i <= n; ++i) cin >> t[i], p.push_back(i);
	for(int i = 1; i <= n; ++i) add(i, 1);
	sort(p.begin(), p.end(), [&](int x, int y) {
		return make_pair(t[x], x) > make_pair(t[y], y);
	});
	LL now = 0;
	priority_queue<int, vector<int>, greater<int> > q;
	queue<int> que;
	while(p.size() || q.size() || que.size()) {
		if(que.empty() && q.empty()) chmax(now, t[p.back()]);
		while(p.size() && t[p.back()] <= now) q.push(p.back()), p.pop_back(); // ready but waiting
		if(q.size() && sum(q.top()) == q.top()) add(q.top(), -1), que.push(q.top()), q.pop(); // up for queue
		if(que.size()) {
			while(p.size() && t[p.back()] <= now + per) {
				display(p.back());
				q.push(p.back()), p.pop_back(); // ready but waiting
				if(q.size() && sum(q.top()) == q.top()) add(q.top(), -1), que.push(q.top()), q.pop(); // up for queue
			}
			now += per;
			ans[que.front()] = now;
			add(que.front(), 1);
			que.pop();
		}
	}
	for(int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
	return 0;
}