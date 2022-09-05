#include <bits/stdc++.h>
using namespace std;

set<int> values; // size is O(sqrt(SUM_LEN))

int get_lcp(const string& a, const string& b) {
	int answer = 0;
	for(int i = 0; i < (int) min(a.length(), b.length()); i++) {
		if(a[i] == b[i]) {
			answer++;
		}
		else {
			break;
		}
	}
	values.insert(answer);
	return answer;
}

#define cerr if(0) cerr

int main() {
	int n, q;
	cin >> n >> q;
	vector<pair<int,int>> query(q);
	vector<vector<pair<int,int>>> updates(q);
	vector<int> answer(q, -1);
	vector<string> s(n);
	vector<int> lcp(n - 1, -1); // lcp[i] = LCP(s[i], s[i+1])
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		if(i >= 1) {
			lcp[i-1] = get_lcp(s[i-1], s[i]);
		}
	}
	vector<int> initial_lcp = lcp;
	// for(int x : lcp) cerr << x << " "; cerr << endl;
	
	int base = 1;
	while(base < n) {
		base *= 2;
	}
	vector<int> big(2 * base);
	for(int i = 0; i < n; ++i) {
		big[base+i] = s[i].length();
	}
	for(int i = base - 1; i >= 1; --i) {
		big[i] = max(big[2*i], big[2*i+1]);
	}
	#define tree big
	for(int id = 0; id < q; id++) {
		int type;
		cin >> type;
		if(type == 1) {
			// query
			int a, b;
			cin >> a >> b; // 1 <= a <= b <= n
			a--;
			b--;
			query[id] = {a, b};
			a += base;
			b += base;
			answer[id] = max({answer[id], tree[a], tree[b]});
			while(a + 1 < b) {
				if(a % 2 == 0) {
					answer[id] = max(answer[id], tree[a+1]);
				}
				if(b % 2 == 1) {
					answer[id] = max(answer[id], tree[b-1]);
				}
				a /= 2;
				b /= 2;
			}
			// for(int i = a; i <= b; i++) {
				// answer[id] = max(answer[id], (int) s[i].length());
			// }
		}
		else {
			query[id] = {-1, -1};
			assert(type == 2);
			// update
			int pos;
			string y;
			cin >> pos >> y;
			pos--;
			s[pos] = y;
			tree[base+pos] = y.length();
			for(int i = (base + pos) / 2; i >= 1; i /= 2) {
				tree[i] = max(tree[2*i], tree[2*i+1]);
			}
			if(pos >= 1) {
				lcp[pos-1] = get_lcp(s[pos-1], s[pos]);
				updates[id].emplace_back(pos - 1, lcp[pos-1]);
			}
			if(pos != n - 1) {
				lcp[pos] = get_lcp(s[pos], s[pos+1]);
				updates[id].emplace_back(pos, lcp[pos]);
			}
			// for(int x : lcp) cerr << x << " "; cerr << endl;
			// for(string x : s) cerr << x << " "; cerr << endl;
		}
	}
	#undef tree
	for(int x : values) {
		// x is candidate for the minimum
		lcp = initial_lcp;
		vector<bool> is_bad(n - 1);
		set<int> bad_positions{-1, n - 1};
		vector<int> dist(n, 0);
		// find bad positions
		for(int i = 0; i < n - 1; i++) {
			is_bad[i] = (lcp[i] < x);
			if(is_bad[i]) {
				bad_positions.insert(i);
			}
		}
		// compute distances
		int prv = n + 5;
		for(int i = n - 2; i >= 0; --i) {
			if(is_bad[i]) {
				dist[i] = prv - i - 1; // distance to next forbidden position
				prv = i;
			}
		}
		// build a segment tree
		vector<int> tree(2 * base);
		for(int i = 0; i < n - 1; ++i) {
			tree[base+i] = dist[i];
		}
		for(int i = base - 1; i >= 1; --i) {
			tree[i] = max(tree[2*i], tree[2*i+1]);
		}
		
		auto tree_update = [&](int i, int new_value) {
			tree[base+i] = new_value;
			for(int j = (base + i) / 2; j >= 1; j /= 2) {
				tree[j] = max(tree[2*j], tree[2*j+1]);
			}
		};
		
		for(int id = 0; id < q; id++) {
			if(query[id].first != -1) {
				int a = query[id].first;
				int b = query[id].second;
				// find longest non-bad interval within [a, b]
				int first = *bad_positions.lower_bound(a);
				int last = *prev(bad_positions.lower_bound(b));
				cerr << "x = " << x << endl;
				cerr << "bad: ";
				// for(int z : bad_positions) cerr << z << ", ";
				cerr << endl;
				cerr << a << " " << b << " " << first << " " << last << endl;
				cerr << first - a << endl;
				cerr << b - 1 - last << endl;
				int longest = min(b - a, max({0, first - a, b - 1 - last}));
				last--;
				if(first <= last) {
					first += base;
					last += base;
					longest = max({longest, tree[first], tree[last]});
					while(first + 1 < last) {
						if(first % 2 == 0) {
							longest = max(longest, tree[first+1]);
						}
						if(last % 2 == 1) {
							longest = max(longest, tree[last-1]);
						}
						first /= 2;
						last /= 2;
					}
				}
				// for(int j = first; j < last; ++j) { // right-exclusive
					// longest = max(longest, dist[j]);
				// }
				if(longest != 0) {
					cerr << "l = " << longest << endl;
					answer[id] = max(answer[id], (longest + 1) * x);
				}
			}
			else {
				for(pair<int,int> upd : updates[id]) {
					int pos = upd.first;
					int new_value = upd.second;
					if((lcp[pos] < x) != (new_value < x)) {
						is_bad[pos] = !is_bad[pos];
						if(is_bad[pos]) {
							auto it = bad_positions.insert(pos).first;
							// cerr << "hack " << *next(it) << " " << pos << endl;
							// dist[pos] = *next(it) - pos - 1;
							tree_update(pos, *next(it) - pos - 1);
							int left = *prev(it);
							if(left != -1) {
								tree_update(left, pos - left - 1);
								// dist[left] = pos - left - 1;
							}
						}
						else {
							auto it = bad_positions.find(pos);
							assert(it != bad_positions.end());
							int left = *prev(it);
							if(left != -1) {
								tree_update(left, *next(it) - left - 1);
								// dist[left] = *next(it) - left - 1;
							}
							tree_update(pos, 0);
							// dist[pos] = 0;
							bad_positions.erase(it);
						}
					}
					lcp[pos] = new_value;
					
					
				}
			}
		}
	}
	for(int id = 0; id < q; ++id) {
		if(answer[id] != -1) {
			cout << answer[id] << "\n";
		}
	}
}