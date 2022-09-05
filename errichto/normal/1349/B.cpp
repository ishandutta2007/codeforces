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

int n;
bool brute;
set<vector<int>> vis;
void dfs(vector<int> a) {
	if(a == vector<int>(n, 1)) {
		brute = true;
	}
	if(vis.count(a)) {
		return;
	}
	vis.insert(a);
	for(int L = 0; L < n; ++L) {
		for(int R = L + 1; R < n; ++R) {
			vector<int> values;
			for(int i = L; i <= R; ++i) {
				values.push_back(a[i]);
			}
			sort(values.begin(), values.end());
			int s = values.size();
			vector<int> b = a;
			for(int i = L; i <= R; ++i) {
				b[i] = values[(s-1)/2];
			}
			dfs(b);
		}
	}
}


vector<int> a;



void rec(int i) {
	bool any = false;
	if(i + 1 < n) {
		if(a[i] == 1 && a[i+1] == 2) {
			a[i+1] = 1;
			any = true;
		}
		if(a[i] == 2 && a[i+1] == 1) {
			a[i] = 1;
			any = true;
		}
		// if(a[i] == 2 && a[i+1] == 0) {
			// a[i+1] = 2;
			// any = true;
		// }
		// if(a[i] == 0 && a[i+1] == 2) {
			// a[i] = 2;
			// any = true;
		// }
	}
	if(i >= 1 && i + 1 < n) {
		if(set<int>{a[i-1], a[i], a[i+1]} == set<int>{0, 1, 2}) {
			a[i-1] = a[i] = a[i+1] = 1;
			any = true;
		}
		if(a[i-1] == 1 && a[i+1] == 1 && a[i] != 1) {
			a[i] = 1;
			any = true;
		}
		if(a[i-1] == 1 && a[i] == 1 && a[i+1] != 1) {
			a[i+1] = 1;
			any = true;
		}
		if(a[i+1] == 1 && a[i] == 1 && a[i-1] != 1) {
			a[i-1] = 1;
			any = true;
		}
		if(a[i-1] == 2 && a[i] == 2 && a[i+1] == 0) {
			a[i+1] = 2;
			any = true;
		}
		if(a[i+1] == 2 && a[i] == 2 && a[i-1] == 0) {
			a[i-1] = 2;
			any = true;
		}
	}
	if(i >= 1 && i + 1 < n) {
		if(a[i-1] == 2 && a[i+1] == 2 && a[i] == 0) {
			a[i] = 2;
			any = true;
		}
	}
	if(any) {
		for(int j = i - 2; j <= i + 2; ++j) {
			if(0 <= j && j < n) {
				rec(j);
			}
		}
	}
}

void test_case() {
	scanf("%d", &n);
	int k;
	scanf("%d", &k);
	a.clear();
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if(a[i] < k) {
			a[i] = 0;
		}
		else if(a[i] == k) {
			a[i] = 1;
		}
		else {
			a[i] = 2;
		}
	}
	vis.clear();
	// brute = false;
	// dfs(a);
	for(int i = 0; i < n; ++i) {
		rec(i);
	}
	debug() << imie(a);
	// assert(brute == (a == vector<int>(n, 1)));
	if(a == vector<int>(n, 1)) {
		puts("yes");
	}
	else {
		puts("no");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}