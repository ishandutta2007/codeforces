#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

struct Query {
	int q_id, pos;
	long long k;
};
struct Rev {
	int L, R;
	long long ways;
};

long long choose(long long a, int b) {
	long long product = 1;
	for(int i = 0; i < b; ++i) {
		product = product * (a - i) / (i + 1);
	}
	return product;
}

void test_case() {
	int n, max_c, q;
	cin >> n >> max_c >> q;
	vector<int> answer(q);
	// 0) compute number of ways to finish the suffix
	vector<vector<long long>> ways(max_c + 1, vector<long long>(n + 1));
	for(int c = 0; c <= max_c; ++c) {
		ways[c][0] = 1;
		for(int len = 1; len <= n; ++len) {
			ways[c][len] = (c == 0 ? 0 : ways[c-1][len]) + choose(len - 1, c);
		}
	}
	
	vector<int> p(n);
	for(int i = 0; i < n; ++i) {
		cin >> p[i];
		// p[i]--; // maybe not necessary
	}
	vector<vector<vector<Query>>> todo(max_c + 1, vector<vector<Query>>(n + 1));
	for(int q_id = 0; q_id < q; ++q_id) {
		int pos;
		long long k;
		cin >> pos >> k;
		if(ways[max_c][n] < k) {
			answer[q_id] = -1;
			continue;
		}
		todo[max_c][0].push_back(Query{q_id, pos - 1, k});
	}
	for(int c = max_c; c >= 0; --c) { // maybe c >= 0
		// 1) build deque, going from right to left
		deque<Rev> d;
		d.push_back(Rev{n, n-1, 1}); // empty reverse
		for(int i = n - 1; i >= 0; --i) {
			vector<vector<int>> intervals;
			for(int j = i + 1; j < n && j - i <= c; ++j) {
				// reverse [i, j]
				vector<int> interval(p.begin() + i, p.begin() + j + 1);
				reverse(interval.begin(), interval.end());
				intervals.push_back(interval);
			}
			sort(intervals.begin(), intervals.end());
			for(int rep = 0; rep < 2; ++rep) {
				for(vector<int> interval : intervals) {
					int len = interval.size();
					int j = i + len - 1;
					Rev rev{i, j, ways[c-(j-i)][n-j-1]};
					assert(interval[0] != p[0]);
					if(rep == 0 && interval[0] > p[i]) { // lexicographically big
						d.push_back(rev);
					}
					if(rep == 1 && interval[0] < p[i]) {
						d.push_front(rev);
					}
				}
				reverse(intervals.begin(), intervals.end());
			}
		}
		// 2) prefix sums
		vector<long long> pref{0};
		for(Rev rev : d) {
			pref.push_back(pref.back() + rev.ways);
		}
		
		int first = 0, last = (int) d.size() - 1;
		long long offset = 0;
		for(Rev rev : d) {
			debug() << imie(rev.L) imie(rev.R) imie(rev.ways);
		}
		// 3) from left to right, answer queries and push them to the right
		for(int i = 0; i < n; ++i) {
			debug() << imie(c) imie(i) imie(first) imie(last);
			for(Query query : todo[c][i]) {
				int low = first, high = last;
				int best = -1;
				while(low <= high) {
					int mid = (low + high) / 2;
					if(pref[mid-1+1] - offset < query.k) {
						best = mid;
						low = mid + 1;
					}
					else {
						high = mid - 1;
					}
				}
				assert(best != -1);
				query.k -= pref[best-1+1] - offset;
				Rev rev = d[best - first];
				if(query.pos < rev.L || rev.R == n) {
					debug() << imie(rev.L) imie(rev.R);
					answer[query.q_id] = p[query.pos];
				}
				else if(query.pos <= rev.R) {
					debug() << imie(rev.L) imie(rev.R);
					answer[query.q_id] = p[rev.L + (rev.R - query.pos)];
				}
				else {
					todo[c - (rev.R - rev.L)][rev.R + 1].push_back(query);
				}
			}
			while(!d.empty() && d.front().L == i) {
				offset += d.front().ways;
				first++;
				d.pop_front();
			}
			while(!d.empty() && d.back().L == i) {
				d.pop_back();
				last--;
			}
		}
	}
	for(int i = 0; i < q; ++i) {
		cout << answer[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		test_case();
	}
}