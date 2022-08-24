    #include <bits/stdc++.h>
     
    #define itn int
    #define all(x) (x).begin(), (x).end()
    #define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
     
    #define random_shuffle(...) shuffle(__VA_ARGS__, rng)
    #define rand() rng()
     
    #ifdef OLBOEB
    	#define return std::cerr << __FUNCTION__ << "\n"; return
    #endif  // OLBOEB
     
    using namespace std;
     
    inline int nxt() {
    	int x;
    	scanf("%d", &x);
    	return x;
    }
     
    struct Seg {
    	int len;
    	vector<int> guys;
    };
     
    int main() {
    	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
     
    	int n = nxt();
    	string s;
    	cin >> s;
     
    	if (*max_element(all(s)) == '0') {
    		cout << "0\n";
    		return 0;
    	}
     
    	s = "0" + s + "0";
     
    	vector<int> zeroes, ones;
    	{
    		int cur = 0;
    		for (char c : s) {
    			if (c == '0') {
    				++cur;
    			} else if (cur) {
    				zeroes.push_back(cur);
    				cur = 0;
    			}
    		}
    		zeroes.push_back(cur);
    	}
    	{
    		int cur = 0;
    		for (char c : s) {
    			if (c == '1') {
    				++cur;
    			} else if (cur) {
    				ones.push_back(cur);
    				cur = 0;
    			}
    		}
    	}
    	zeroes[0] -= 1;
    	zeroes.back() -= 1;
     
    	long long ans = 1ll * n * (n + 1) * (n + 2) / 6;
     
    	map<int, vector<int>> M;
    	for (int i = 0; i < (int)ones.size(); ++i) {
    		M[ones[i]].push_back(i);
    	}
     
    	const int sz = zeroes.size();
     
    	list<Seg> segs;
    	vector<decltype(segs)::iterator> its(sz);
    	for (int i = 0; i < sz; ++i) {
    		segs.push_back({zeroes[i], {i}});
    		its[i] = prev(segs.end());
    	}
     
    	auto is_border = [&](int pos) {
    		const auto& it = its[pos];
    		return it == segs.begin() || it == prev(segs.end());
    	};
     
    	auto merge = [&](decltype(segs)::iterator l, decltype(segs)::iterator r) {
    		if (l->guys.size() < r->guys.size()) {
    			for (int x : l->guys) {
    				its[x] = r;
    			}
    			r->guys.insert(r->guys.end(), all(l->guys));
    			r->len += l->len;
    			segs.erase(l);
    		} else {
    			for (int x : r->guys) {
    				its[x] = l;
    			}
    			l->guys.insert(l->guys.end(), all(r->guys));
    			l->len += r->len;
    			segs.erase(r);
    		}
    	};
     
    	int cnt = sz - 1;
    	int sum_ones = accumulate(all(ones), 0);
    	int sum_inner = accumulate(1 + all(zeroes) - 1, 0);
    	long long sum_c = 0;
    	for (auto x : zeroes) {
    		sum_c += 1ll * x * (x + 1) / 2;
    	}
     
    	for (int i = 0; sum_ones; ++i) {
    		// for (auto it = segs.begin(); it != segs.end(); ++it) {
    		// 	if (it == segs.begin() || it == prev(segs.end())) {
    		// 		cerr << it->len << " ";
    		// 	} else {
    		// 		cerr << it->len + i << " ";
    		// 	}
    		// }
    		// cerr << ", sum_inner = " << sum_inner << ", sum_c = " << sum_c << "\n";
     
    		ans -= sum_c;
    		sum_ones -= cnt;
    		sum_inner += cnt - 1;
    		sum_c += sum_inner;
    		for (int pos : M[i + 1]) {
    			--cnt;
    			auto lit = its[pos], rit = its[pos + 1];
    			if (is_border(pos) != is_border(pos + 1)) {
    				if (!is_border(pos)) {
    					its[pos]->len += i + 1;
    					sum_inner -= its[pos]->len;
    				} else {
    					its[pos + 1]->len += i + 1;
    					sum_inner -= its[pos + 1]->len;
    				}
    				sum_c += 1ll * lit->len * rit->len;
    				// cerr << "w\n";
    			} else {
    				// cerr << "q\n";
    				if (is_border(pos)) {
    					sum_c += 1ll * lit->len * rit->len;
    				} else {
    					sum_c += 1ll * (lit->len + i + 1) * (rit->len + i + 1);
    				}
    				its[pos]->len += i + 1;
    			}
    			merge(lit, rit);
    		}
     
    		if (!sum_ones) {
    			ans -= 1ll * (n - i - 1) * (n - i) * (n - i + 1) / 6;
    		}
    	}
     
    	cout << ans << "\n";
     
    	return 0;
    }