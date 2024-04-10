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

const int MAX_N = 2005;
char line[MAX_N];
int n;
vector<int> out_degree;

bool is_sc() {
	// vector<int> tmp = out_degree;
	vector<int> cnt(n + 1);
	for(int x : out_degree) {
		cnt[x]++;
	}
	vector<int> tmp;
	for(int x = n; x >= 0; --x) {
		for(int rep = 0; rep < cnt[x]; ++rep) {
			tmp.push_back(x);
		}
	}
	// sort(tmp.rbegin(), tmp.rend());
	int sum = 0;
	for(int i = 0; i < n - 1; ++i) {
		sum += tmp[i];
		if(sum == i * (i + 1) / 2 + (i + 1) * (n - i - 1)) {
			
			return false;
		}
	}
	return true;
}

int main() {
	// CF #609, div1-C, Invertation in Tournament   https://codeforces.com/contest/1268/problem/D
	scanf("%d", &n);
	out_degree.resize(n);
	vector<vector<bool>> edge(n, vector<bool>(n));
	for(int i = 0; i < n; ++i) {
		scanf("%s", line);
		for(int j = 0; j < n; ++j) {
			if(line[j] == '1') {
				edge[i][j] = true;
				++out_degree[i];
			}
		}
	}
	debug() << imie(out_degree);
	if(is_sc()) {
		puts("0 1");
		return 0;
	}
	int ways = 0;
	for(int a = 0; a < n; ++a) {
		auto memo = out_degree;
		for(int b = 0; b < n; ++b) {
			if(a != b) {
				if(edge[a][b]) --out_degree[a], ++out_degree[b];
				else ++out_degree[a], --out_degree[b];
			}
		}
		if(is_sc()) {
			ways++;
		}
		out_degree = memo;
	}
	if(ways) {
		printf("1 %d\n", ways);
		return 0;
	}
	if(n > 10) {
		puts("-1");
		return 0;
	}
	// brute force multiple vertices
	pair<int,int> answer{INT_MAX, 0};
	vector<int> factorial(n + 1);
	factorial[0] = 1;
	for(int i = 1; i <= n; ++i) {
		factorial[i] = factorial[i-1] * i;
	}
	for(int mask = 0; mask < (1 << n); ++mask) {
		auto memo = edge;
		for(int a = 0; a < n; ++a) {
			if(mask & (1 << a)) {
				for(int b = 0; b < n; ++b) {
					if(a != b) {
						edge[a][b] = !edge[a][b];
						edge[b][a] = !edge[b][a];
					}
				}
			}
		}
		out_degree = vector<int>(n, 0);
		for(int a = 0; a < n; ++a) {
			for(int b = 0; b < n; ++b) {
				out_degree[a] += edge[a][b];
			}
		}
		if(is_sc()) {
			int changed = __builtin_popcount(mask);
			if(changed < answer.first) {
				answer = {changed, factorial[changed]};
			}
			else if(changed == answer.first) {
				// debug() << imie(changed) imie(mask);
				answer.second += factorial[changed];
			}
		}
		edge = memo;
	}
	if(answer.first == INT_MAX) {
		puts("-1");
	}
	else {
		printf("%d %d\n", answer.first, answer.second);
	}
}

// 123456

// 1 2 4  --> 3 5 6