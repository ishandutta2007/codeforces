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


int brute(string s) {
	int n = s.length();
	set<string> possible;
	for(int mask = 0; mask < (1 << n); ++mask) {
		int big = 0;
		string current;
		for(int i = 0; i < n; ++i) {
			if(i == 0 || (mask & (1 << i))) {
				if(i != 0) {
					current += (big ? '1' : '0');
					big = 0;
				}
			}
			if(s[i] == '1') big = 1;
		}
		current += (big ? '1' : '0');
		possible.insert(current);
	}
	debug() << imie(possible);
	return possible.size();
}

const int nax = 1e6 + 5;
char s[nax];
const int mod = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if(a >= mod) {
		a -= mod;
	}
	return a;
}
void add_self(int& a, int b) {
	a = add(a, b);
}
struct Node {
	int sum, size;
	int lazy_add;
	bool do_zero;
	void merge(const Node& a, const Node& b) {
		assert(!do_zero);
		assert(lazy_add == 0);
		size = a.size + b.size;
		sum = add(a.sum, b.sum);
	}
	void add_me(int a) {
		add_self(lazy_add, a);
		sum = (sum + (long long) size * a) % mod;
	}
	void make_zero() {
		lazy_add = sum = 0;
		do_zero = true;
	}
	void push(Node& a, Node& b) {
		if(do_zero) {
			do_zero = false;
			a.make_zero();
			b.make_zero();
		}
		a.add_me(lazy_add);
		b.add_me(lazy_add);
		lazy_add = 0;
	}
};
vector<Node> tree;

int gather;
void rec(int id, int low, int high, int q_low, int q_high, int by) {
	if(high < q_low || q_high < low) {
		return;
	}
	if(q_low <= low && high <= q_high) {
		if(by == -1) {
			add_self(gather, tree[id].sum);
			tree[id].make_zero();
		}
		else {
			tree[id].add_me(by);
		}
		return;
	}
	tree[id].push(tree[2*id], tree[2*id+1]);
	int last_left = (low + high) / 2;
	rec(2 * id, low, last_left, q_low, q_high, by);
	rec(2 * id + 1, last_left + 1, high, q_low, q_high, by);
	tree[id].merge(tree[2*id], tree[2*id+1]);
}

int main() {
	scanf("%s", s);
	
	int n = strlen(s);
	// int n = 1000000;
	// for(int i = 0; i < n; ++i) {
		// s[i] = (rand() % 2 ? '0' : '1');
	// }
	
	// debug() << imie(brute(string(s)));
	int start = 0, end = n - 1;
	while(start < n && s[start] == '0') {
		++start;
	}
	while(end >= 0 && s[end] == '0') {
		--end;
	}
	if(start == n) {
		printf("%d\n", n);
		return 0;
	}
	assert(start <= end);
	assert(s[start] == s[end] && s[end] == '1');
	vector<int> dp(n);
	dp[start] = 1;
	debug() << imie(start) imie(end);
	vector<int> value(n);
	for(int i = 0; i < n - 1; ++i) {
		if(s[i] == '0') {
			value[i+1] = value[i] + 1;
		}
	}
	debug() << imie(value);
	int answer = 0;
	// vector<int> tree(n + 2);
	int B = 1;
	while(B <= n + 1) B *= 2;
	tree.resize(2*B);
	// vector<Node> tree(2*B);
	for(int i = 0; i < B; ++i) {
		tree[B+i].size = 1;
	}
	for(int i = B - 1; i >= 1; --i) {
		tree[i].merge(tree[2*i], tree[2*i+1]);
	}
	for(int i = start; i <= end; ++i) {
		if(s[i] == '1') {
			gather = 0;
			rec(1, 0, B - 1, 0, value[i], -1);
			add_self(dp[i], gather);
			// for(int j = 0; j <= value[i]; ++j) {
				// dp[i] += tree[j];
				// tree[j] = 0;
			// }
			answer = (answer + dp[i]) % mod;
			rec(1, 0, B - 1, 0, B - 1, dp[i]);
			// for(int j = 0; j <= n; ++j) {
				// tree[j] += dp[i];
			// }
			
			// int big = -1;
			// for(int j = i + 1; j <= end; ++j) {
				// if(s[j] == '1') {
					// if(value[j] > big) {
						// dp[j] += (value[j] - big) * dp[i];
						// big = value[j];
					// }
				// }
			// }
		}
	}
	/*
			for(int j = i + 1; j < end; ++j) {
				if(s[j] == '1') {
					dp[j] += dp[i];
					break;
				}
			}
			for(int cnt = 1; cnt <= n; ++cnt) {
		for(char want = '0'; want <= '1'; ++want) {
			if(s[i] == '0' && want == '0' && s[i+1] == '1') {
				continue;
			}
			for(int j = i + 1; j <= end; ++j) {
				if(s[j] == want) {
					dp[j] += dp[i];
					break;
				}
			}
		}
	}*/
	debug() << imie(dp);
	// int answer = 0;
	// for(int i = start; i <= end; ++i) {
		// if(s[i] == '1') {
			// answer = (answer + dp[i]) % mod;
		// }
	// }
	debug() << imie(answer);
	answer = (long long) answer * (start + 1) % mod * (n - end) % mod;
	printf("%d\n", answer);
}