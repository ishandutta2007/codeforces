#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct line {
	int a, id;
	ll b;
	line(int aa, ll bb, int idd) : a(aa), id(idd), b(bb) {}
	// does (this,B) intersect before (B,C)
	bool before(const line & B, const line & C) {
		// a*x + b = B.a*x + B.b
		// x * (a-B.a) = B.b-b
		// x * q1 = p1
		ll p1 = B.b - b, p2 = C.b - b;
		int q1 = a - B.a, q2 = a - C.a;
		if(q1 < 0) { p1 *= -1; q1 *= -1; }
		if(q2 < 0) { p2 *= -1; q2 *= -1; }
		// x1 = p1/q1, x2 = p2/q2
		return p1*q2 <= p2*q1;
	}
	ll f(int x) { return (ll) a * x + b; }
};

struct hull {
	vector<int> a; // numbers from input
	vector<bool> taken;
	vector<line> w; // hull
	vector<int> order;
	int n;
	int pointer;
	int count; // number of taken elements
	ll sum; // sum of taken elements
	hull(){}
	hull(vector<int> aa) : a(aa) {
		count = sum = 0;
		n = (int) a.size();
		taken.resize(n, false);
		for(int i = 0; i < n; ++i)
			order.push_back(i);
		// we find order only once, in constructor
		sort(order.begin(), order.end(), [&](int i, int j){ return a[i] < a[j]; });
		build();
	}
	void build() { // build hull
		pointer = 0;
		vector<ll> val(n);
		ll suf = sum;
		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			if(taken[i]) {
				suf -= a[i];
				++cnt;
			}
			else val[i] = suf + (ll) a[i] * (cnt + 1);
		}
		vector<line> sorted;
		// linear sort using vector<int> order
		for(int i : order) if(!taken[i])
			sorted.push_back(line(a[i], val[i], i));
		w.clear();
		for(line & C : sorted) {
			if(!w.empty() && w.back().a == C.a) {
				if(C.b <= w.back().b) continue;
				else w.pop_back();
			}
			while((int) w.size() >= 2) {
				line & A = w[(int)w.size()-2];
				line & B = w[(int)w.size()-1];
				if(A.before(B, C)) break;
				w.pop_back();
			}
			w.push_back(C);
		}
	}
	pair<ll, int> best(int before) { // find the best candidate, move pointer
		if(w.empty()) return make_pair(42LL, -1);
		while(pointer <= (int) w.size()-2 && w[pointer].f(before) < w[pointer+1].f(before))
			++pointer;
		assert(pointer < (int) w.size());
		return make_pair(w[pointer].f(before), w[pointer].id);
	}
	void remove(int i) { // mark as taken
		assert(!taken[i]);
		taken[i] = true;
		sum += a[i];
		++count;
		build();
	}
} h[1005];

int a[1005*1005];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	// divide into Parts with size sqrt(n)
	int s = max(1, int(sqrt(n)));
	for(int i = 0; i < n; i += s) {
		vector<int> w;
		for(int j = i; j < min(n, i+s); ++j)
			w.push_back(a[j]);
		h[i/s] = hull(w);
	}
	ll output = 0; // max(score)
	ll score = 0; // score for current set/subsequence
	while(true) {
		pair<ll,int> m = make_pair(42LL, -1);
		ll suf = 0; // sum of elements on the right
		int cnt = 0; // how many on the left
		for(int i = 0; i < n; i += s)
			suf += h[i/s].sum;
		for(int i = 0; i < n; i += s) {
			suf -= h[i/s].sum;
			// we ask this Part about max(ax+b) where x = cnt
			pair<ll, int> p = h[i/s].best(cnt);
			p.first += suf; // extra constant
			if(p.second != -1)
				if(m.second == -1 || p.first > m.first)
					m = make_pair(p.first, i+p.second);
			cnt += h[i/s].count;
		}
		if(m.second == -1) break;
		score += m.first;
		output = max(output, score);
		int i = m.second;
		h[i/s].remove(i-i/s*s);
	}
	printf("%lld\n", output);
	return 0;
}