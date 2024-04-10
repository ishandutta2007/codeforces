#ifdef DEBUG
	#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class PriorityQueue {
private:
	vector< pair<int, int> > d1, d2;
	int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
	
	inline bool takeFirst() {
		return l1 != r1 && (l2 == r2 || d1[l1] < d2[l2]);
	}
public:
	inline void prepare() {
		swap(d1, d2);
		swap(l1, l2);
		swap(r1, r2);
	}
	
	inline void push(const pair<int, int> &p) {
		d1.push_back(p);
		r1++;
	}
	
	inline void repush(const pair<int, int> &p) {
		if (l1) {
			d1[--l1] = p;
		} else {
			d2[--l2] = p;
		}
	}
	
	inline bool empty() {
		return l1 == r1 && l2 == r2;
	}
	
	inline pair<int, int> top() {
		return takeFirst() ? d1[l1] : d2[l2];
	}
	
	inline void pop() {
		(takeFirst() ? l1 : l2)++;
	}
};

static const int heavyLim = 500;

struct FreqAnalyzer {
	int n, m;
	vector<int> items;
	vector<int> freqs;
	vector<int> heavy;
	
	inline void add(int v, int sign) {
		if (items[v]) {
			freqs[items[v]]--;
		}
		items[v] += sign;
		if (items[v]) {
			freqs[items[v]]++;
		}
	}
	
	inline int64_t huffmanSum() {
		PriorityQueue pq;
		
		for (int i = 0; i < min(n+1, heavyLim); i++) {
			if (freqs[i]) {
				pq.push({i, freqs[i]});
			}
		}
		
		vector< pair<int, int> > heavies;
		for (int i: heavy) {
			if (items[i] >= heavyLim) {
				heavies.emplace_back(items[i], 1);
			}
		}
		sort(heavies.begin(), heavies.end());
		for (auto it: heavies) {
			pq.push(it);
		}
		
		pq.prepare();
		int64_t ans = 0;
		while (!pq.empty()) {
			auto it = pq.top(); pq.pop();
			while (!pq.empty() && pq.top().first == it.first) {
				it.second += pq.top().second;
				pq.pop();
			}
			if (it.second == 1) {
				if (pq.empty()) {
					break;
				} else {
					auto jt = pq.top();
					int q = jt.first;
					jt.second--;
					pq.pop();
					if (jt.second) {
						pq.repush(jt);
					}
					ans += it.first + q;
					pq.push({it.first + q, 1});
				}
			} else {
				int64_t a = it.first * 2, b = it.second / 2;
				ans += a*b;
				pq.push({a, b});
				if (it.second & 1) {
					pq.repush({it.first, 1});
				}
			}
		}
		
		return ans;
	}
	
	FreqAnalyzer(int n, int m, const vector<int> &heavy)
		: n(n), m(m), items(m), freqs(n+1), heavy(heavy) {
	}
};

const int moBlock = 300;

struct Query {
	int l, r, idx;
	
	inline pair<int, int> toPair() const {
		auto res = make_pair(l / moBlock, r);
		if (res.first & 1) {
			res.second *= -1;
		}
		return res;
	}
};

inline bool operator<(const Query &a, const Query &b) {
	return a.toPair() < b.toPair();
}

int main() {
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	vector<int> a(n);
	int m = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; m = max(m, a[i]); a[i]--;
	}
	
	vector<int> knt(m);
	vector<int> heavy;
	for (int i = 0; i < n; i++) {
		knt[a[i]]++;
	}
	for (int i = 0; i < m; i++) {
		if (knt[i] >= heavyLim) {
			heavy.push_back(i);
		}
	}
	
	int q; cin >> q;
	vector<Query> qry(q);
	for (int i = 0; i < q; i++) {
		cin >> qry[i].l >> qry[i].r; qry[i].l--; qry[i].r--;
		qry[i].idx = i;
	}
	sort(qry.begin(), qry.end());
	
	FreqAnalyzer fa(n, m, heavy);
	int l = 0, r = -1;
	vector<int64_t> ans(q);
	for (Query q: qry) {
		while (l > q.l) {
			fa.add(a[--l], +1);
		}
		while (r < q.r) {
			fa.add(a[++r], +1);
		}
		while (l < q.l) {
			fa.add(a[l++], -1);
		}
		while (r > q.r) {
			fa.add(a[r--], -1);
		}
		ans[q.idx] = fa.huffmanSum();
	}
	
	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}