#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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

using ll = long long;

int k;
int all_cnt;
vector<int> in;
int pre[125][125];
long long answer;
using ull = unsigned long long;

map<pair<ull,ull>, pair<ull,ull>> mapka[125];

struct S {
	vector<bool> taken;
	vector<int> kol;
	pair<ull,ull> m;
	bool is_on(int x) {
		if(x < 64) {
			return m.first & (1ULL << x);
		}
		return m.second & (1ULL << (x - 64));
	}
	void turn_on(int x) {
		taken[x] = true;
		if(x < 64) {
			m.first |= 1ULL << x;
		}
		else {
			m.second |= 1ULL << (x - 64);
		}
	}
	S() {
		taken.resize(all_cnt);
		kol.push_back(0);
		m = {0ULL, 0ULL};
		turn_on(0);
	}
	bool add(int x, bool force = false) {
		if(taken[x]) {
			return false;
		}
		if(mapka[x].count(m)) {
			m = mapka[x][m];
			kol.clear();
			for(int i = 0; i < all_cnt; ++i) {
				if(is_on(i)) {
					kol.push_back(i);
					taken[i] = true;
				}
			}
			return true;
		}
		auto memo = m;
		turn_on(x);
		kol.push_back(x);
		for(int i = (int) kol.size() - 1; i < (int) kol.size(); ++i) {
			for(int j = 0; j <= i; ++j) {
				for(int b : {pre[kol[i]][kol[j]], pre[kol[j]][kol[i]]}) {
					if(!taken[b]) {
						turn_on(b);
						kol.push_back(b);
					}
				}
			}
		}
		mapka[x][memo] = m;
		// if(taken[x] && !force) {
			// return false;
		// }
		// for(int i = 0; i < (int) kol.size(); ++i) {
			// int y = kol[i];
			// for(int b : {pre[x][y], pre[y][x]}) {
				// if(!taken[b]) {
					// taken[b] = true;
					// kol.push_back(b);
					// add(b, true);
				// }
			// }
		// }
		return true;
	}
};

vector<S> tree;
int B;

void rec(int L, int R) {
	if(L == R) {
		int cur = 0;
		set<int> secik{cur};
		while(true) {
			cur = pre[cur][in[L]];
			if(secik.count(cur)) {
				break;
			}
			secik.insert(cur);
		}
		answer += secik.size();
		return;
	}
	int mid = (L + R) / 2;
	rec(L, mid);
	rec(mid + 1, R);
	
	S left = S();
	S right = S();
	vector<int> they_left, they_right;
	for(int i = mid; i >= L; --i) {
		if(left.add(in[i]) || i == mid) {
			they_left.push_back(i);
		}
	}
	for(int i = mid + 1; i <= R; ++i) {
		if(right.add(in[i]) || i == mid + 1) {
			they_right.push_back(i);
		}
	}
	they_left.push_back(L - 1);
	they_right.push_back(R + 1);
	for(int i = 0; i < (int) they_left.size() - 1; ++i) {
		S total = S();
		for(int j = 0; j <= i; ++j) {
			assert(total.add(in[they_left[j]]) || j == 0);
		}
		for(int j = 0; j < (int) they_right.size() - 1; ++j) {
			total.add(in[they_right[j]]);
			answer += (long long) (they_left[i] - they_left[i+1])
				* (they_right[j+1] - they_right[j])
				* total.kol.size();
		}
	}
}

int main() {
	int n;
	scanf("%d%d", &n, &k);
	// tree.resize(2 * B);
	// assert(tree[0].taken[0]);
	// for(int i = 0; i < 2 * B; ++i) {
		// tree[i] = S();
	// }
	vector<vector<int>> all;
	vector<int> ONE;
	for(int i = 0; i < k; ++i) {
		ONE.push_back(i);
	}
	do {
		all.push_back(ONE);
	} while(next_permutation(ONE.begin(), ONE.end()));
	all_cnt = all.size();
	debug() << imie(ONE);
	debug() << imie(all);
	map<vector<int>, int> mapka;
	for(int i = 0; i < (int) all.size(); ++i) {
		mapka[all[i]] = i;
	}
	for(int i = 0; i < (int) all.size(); ++i) {
		for(int j = 0; j < (int) all.size(); ++j) {
			vector<int> nowe(k);
			for(int z = 0; z < k; ++z) {
				nowe[z] = all[i][all[j][z]];
			}
			pre[i][j] = mapka[nowe];
			// debug() << imie(i) imie(j) imie(mapka[nowe]) imie(all[i]) imie(all[j]) imie(nowe);
		}
	}
	
	// B = 1;
	// while(B <= n) {
		// B *= 2;
	// }
	// tree.resize(2 * B);
	// assert(tree[0].taken[0]);
	// S tmp = S();
	// return 0;
	// for(int i = 0; i < 2 * B; ++i) {
		// tree.push_back(tmp);
	// }
	
	in.resize(n);
	for(int& value : in) {
		vector<int> perm(k);
		for(int& x : perm) {
			scanf("%d", &x);
			x--;
		}
		// vector<int> hack(k);
		// for(int i = 0; i < k; ++i) {
			// hack[perm[i]] = i;
		// }
		// perm = hack;
		value = mapka[perm];
	}
	// for(int i = 0; i < n; ++i) {
		// tree[B+i].add(in[i]);
	// }
	// for(int i = B - 1; i >= 0; --i) {
		// tree[i] = tree[2*i];
		// for(int x : tree[2*i+1].kol) {
			// tree[i].add(x);
		// }
	// }
	// for(int i = 1; i <= 10; ++i) {
		// cout << tree[i].kol.size() << endl;
	// }
	// return 0;
	debug() << imie(in);
	/*for(int i = 0; i < n; ++i) {
		S nowy = S();
		for(int j = i; j < n; ++j) {
			nowy.add(in[j]);
			// nowy.add(pre[in[j]][in[j]]);
			// nowy.add(pre[in[j]][pre[in[j]][in[j]]]);
			answer += nowy.kol.size();
			debug() << imie(i) imie(j) imie(nowy.kol.size());
			if((int) nowy.kol.size() == 20) {
				// debug() << imie(nowy.kol);
				set<int> secik;
				for(int x : nowy.kol) {
					secik.insert(x);
				}
				debug() << imie(secik);
				for(int z = 0; z < all_cnt; ++z) {
					if(!secik.count(z)) {
						debug() << imie(all[z]);
					}
				}
				for(int x : secik) {
					for(int y : secik) {
						if(!secik.count(pre[x][y])) {
							debug() << "nie ma" imie(x) imie(y) imie(all[x]) imie(all[y]);
						}
						// assert(secik.count(pre[x][y]));
					}
				}
			}
			// if(i == j) {
				// debug() << imie(nowy.kol);
			// }
		}
	}*/
	vector<int> prv(all_cnt, -1);
	for(int i = 0; i < n; ++i) {
		S s = S();
		s.add(in[i]);
		int where = i;
		while(true) {
			int big = -1;
			for(int x = 0; x < all_cnt; ++x) {
				if(!s.taken[x]) {
					big = max(big, prv[x]);
				}
			}
			answer += (long long) (where - big) * s.kol.size();
			if(big == -1) {
				break;
			}
			else {
				where = big;
				s.add(in[where]);
			}
		}
		prv[in[i]] = i;
	}
	printf("%lld\n", answer);
	return 0;
	rec(0, n - 1);
	printf("%lld\n", answer);
}