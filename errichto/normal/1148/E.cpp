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

typedef long long ll;

const int nax = 3e5 + 5;
ll a[nax], b[nax], a_pref[nax], b_pref[nax];
ll diff[nax];
int inv[nax];

void NO() {
	puts("NO");
	exit(0);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &b[i]);
	}
	vector<pair<int,int>> ss;
	for(int i = 1; i <= n; ++i) {
		ss.emplace_back(a[i], i);
	}
	sort(ss.begin(), ss.end());
	for(int i = 0; i < n; ++i) {
		a[i+1] = ss[i].first;
		inv[i+1] = ss[i].second;
	}
	
	// sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; ++i) {
		a_pref[i] = a_pref[i-1] + a[i];
		b_pref[i] = b_pref[i-1] + b[i];
	}
	
	if(a_pref[n] != b_pref[n]) {
		NO();
	}
	// for(int i = 1; i < n; ++i) {
		// if(a_pref[i] > b_pref[i]) {
			// NO();
		// }
	// }
	for(int i = 1; i < n; ++i) {
		diff[i] = b_pref[i] - a_pref[i];
		// debug() << imie(i);
		if(diff[i] < 0) {
			NO();
		}
	}
	debug() << range(diff + 1, diff + n + 1);
	vector<pair<ll, int>> sorted;
	for(int i = 1; i < n; ++i) {
		sorted.emplace_back(diff[i], i);
	}
	sort(sorted.begin(), sorted.end());
	set<int> used{0, n};
	vector<vector<int>> moves;
	for(pair<ll, int> p : sorted) {
		int i = p.second;
		auto it = used.lower_bound(i);
		int nxt = *it;
		--it;
		int prv = *it;
		ll bigger = max(diff[prv], diff[nxt]);
		used.insert(i);
		ll x = diff[i] - bigger;
		assert(x >= 0);
		if(x == 0) {
			continue;
		}
		debug() << "move" imie(prv + 1) imie(nxt) imie(x);
		if(2 * x > a[nxt] - a[prv+1]) {
			debug() << "o-ho!";
			NO();
		}
		a[prv+1] += x;
		a[nxt] -= x;
		moves.push_back({prv + 1, nxt, (int) x});
	}
	puts("YES");
	printf("%d\n", (int) moves.size());
	for(vector<int> v : moves) {
		printf("%d %d %d\n", inv[v[0]], inv[v[1]], v[2]);
	}
	
	// ll moved = 0;
	
	// int A = 1, B = n - 1;
	// while(A < B) {
		// if(diff[A] == moved) {
			// ++A;
			// continue;
		// }
		// if(diff[B] == moved) {
			// --B;
			// continue;
		// }
		// ll x = min(diff[A], diff[B]) - moved;
		
	// }
	
	// puts("YES");
	// operations
}