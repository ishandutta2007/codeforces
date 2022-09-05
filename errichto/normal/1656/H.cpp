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

using LL = __int128;

LL read_LL() {
	static char s[1005];
	scanf("%s", s);
	int n = strlen(s);
	LL x = 0;
	for(int i = 0; i < n; ++i) {
		x = 10 * x + (s[i] - '0');
	}
	return x;
}
void print(LL x) {
	string s;
	while(x > 0) {
		int digit = x % 10;
		x /= 10;
		s += ('0' + digit);
	}
	reverse(s.begin(), s.end());
	printf("%s ", s.c_str());
}

void read(int n, vector<LL>& a) {
	for(int i = 0; i < n; ++i) {
		a.push_back(read_LL());
	}
}


LL lcm(LL a, LL b) {
	return a / __gcd(a, b) * b;
}

int base;
struct Tree {
	vector<LL> tree;
	void init(vector<LL> a) {
		tree.resize(2 * base, 1);
		for(int i = 0; i < (int) a.size(); ++i) {
			tree[base+i] = a[i];
		}
		for(int i = base - 1; i >= 0; --i) {
			tree[i] = lcm(tree[2*i], tree[2*i+1]);
		}
	}
	void remove(int i) {
		tree[base+i] = 1;
		for(int x = (base + i) / 2; x >= 1; x /= 2) {
			tree[x] = lcm(tree[2*x], tree[2*x+1]);
		}
	}
};

void test_case() {
	int n[2];
	scanf("%d%d", &n[0], &n[1]);
	vector<LL> a[2];
	read(n[0], a[0]);
	read(n[1], a[1]);
	vector<vector<LL>> edges[2];
	for(int x = 0; x < 2; ++x) {
		edges[x].resize(n[x], vector<LL>(n[x^1]));
		for(int i = 0; i < n[x]; ++i) {
			for(int j = 0; j < n[x^1]; ++j) {
				edges[x][i][j] = __gcd(a[x][i], a[x^1][j]);
			}
		}
	}
	vector<vector<bool>> vis(2, vector<bool>(max(n[0], n[1])));
	base = 1;
	while(base <= max(n[0], n[1])) {
		base *= 2;
	}
	vector<Tree> trees[2];
	for(int x = 0; x < 2; ++x) {
		trees[x].resize(n[x]);
		for(int i = 0; i < n[x]; ++i) {
			trees[x][i].init(edges[x][i]);
		}
	}
	
	auto good = [&](int x, int i) {
		return a[x][i] == trees[x][i].tree[1];
	};
	
	vector<pair<int,int>> q;
	for(int x = 0; x < 2; ++x) {
		for(int i = 0; i < n[x]; ++i) {
			if(!good(x, i)) {
				q.emplace_back(x, i);
				vis[x][i] = true;
			}
		}
	}
	for(int z = 0; z < (int) q.size(); ++z) {
		int x = q[z].first;
		int i = q[z].second;
		for(int j = 0; j < n[x^1]; ++j) {
			trees[x^1][j].remove(i);
			if(!vis[x^1][j] && !good(x^1, j)) {
				vis[x^1][j] = true;
				q.emplace_back(x^1, j);
			}
		}
	}
	
	vector<LL> ans[2];
	for(int x = 0; x < 2; ++x) {
		for(int i = 0; i < n[x]; ++i) {
			if(!vis[x][i]) {
				ans[x].push_back(a[x][i]);
			}
		}
	}
	
	#define a ans[0]
	#define b ans[1]
	if(a.empty() || b.empty()) {
		puts("NO");
	}
	else {
		puts("YES");
		printf("%d %d\n", (int) a.size(), (int) b.size());
		for(auto vec : {a, b}) {
			for(auto x : vec) {
				print(x);
				//~ printf("%lld ", x);
			}
			puts("");
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}