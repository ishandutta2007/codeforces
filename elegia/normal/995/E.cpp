#include <cstdio>

#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long ll;

int u, v;
int p;
unordered_map<int, int> gu, gv;

void out(int x);

void tp(queue<int>& q, unordered_map<int, int>& g, int w, int t);

void exGcd(int a, int b, int& x, int& y);
int inv(int a);

int main() {
	scanf("%d%d%d", &u, &v, &p);
	queue<int> qu, qv;
	gu[u] = -1;
	gv[v] = -1;
	qu.push(u);
	qv.push(v);
	while (!qu.empty() || !qv.empty()) {
		queue<int> tmp;
		unordered_map<int, int>::iterator it;
		swap(qu, tmp);
		while (!tmp.empty()) {
			int w = tmp.front();
			tmp.pop();
			it = gv.find(w);
			if (it != gv.end()) {
				out(w);
				return 0;
			}
			tp(qu, gu, (w + 1) % p, 1);
			tp(qu, gu, (w + p - 1) % p, 2);
//			fprintf(stderr, "%d\n", w);
			if (w)
				tp(qu, gu, inv(w), 3);
//			fprintf(stderr, "haha");
		}
//		fprintf(stderr, "done u\n");
		swap(qv, tmp);
		while (!tmp.empty()) {
			int w = tmp.front();
			tmp.pop();
			it = gu.find(w);
			if (it != gu.end()) {
				out(w);
				return 0;
			}
			tp(qv, gv, (w + 1) % p, 2);
			tp(qv, gv, (w + p - 1) % p, 1);
			if (w)
				tp(qv, gv, inv(w), 3);
		}
	}
	return 0;
} 

void out(int x) {
	vector<int> ans;
	int t = x;
	while (t != u) {
		int op;
		ans.push_back(op = gu[t]);
		if (op == 1) {
			if (--t < 0)
				t = p - 1;
		} else if (op == 2) {
			if (++t == p)
				t = 0;
		} else
			t = inv(t);
	}
	reverse(ans.begin(), ans.end());
	t = x;
	while (t != v) {
		int op;
		ans.push_back(op = gv[t]);
		if (op == 2) {
			if (--t < 0)
				t = p - 1;
		} else if (op == 1) {
			if (++t == p)
				t = 0;
		} else
			t = inv(t);
	}
	printf("%d\n", ans.size());
	for (int o : ans)
		printf("%d ", o);
}

void exGcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1;
		y = 0;
		return;
	}
	exGcd(b, a % b, y, x);
	y -= a / b * x;
}

int inv(int a) {
	int x, y;
	exGcd(a, p, x, y);
//	fprintf(stderr, "ha\n");
	if (x < 0)
		x += p;
	return x;
}

void tp(queue<int>& q, unordered_map<int, int>& g, int w, int t) {
//	fprintf(stderr, "INS %d\n", w);
	unordered_map<int, int>::iterator it = g.find(w);
	if (it == g.end()) {
		g[w] = t;
		q.push(w);
	}
}