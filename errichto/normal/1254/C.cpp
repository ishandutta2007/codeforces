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

int queries = 0;

struct P {
	int x, y;
	P operator -(const P& he) const {
		return P{x - he.x, y - he.y};
	}
	int operator *(const P& he) const {
		return x * he.y - y * he.x;
	}
};

vector<P> hidden;
int n;

int sign(int i, int j, int k) {
	assert(++queries <= 3 * n);
	assert(i != j && i != k && j != k && 1 <= min({i, j, k}) && max({i, j, k}) <= n);
	printf("2 %d %d %d\n", i, j, k);
	fflush(stdout);
	if(!hidden.empty()) {
		return ((hidden[j] - hidden[i]) * (hidden[k] - hidden[i]) > 0) ? 1 : -1;
	}
	int r;
	scanf("%d", &r);
	return r;
}
ll area(int i, int j, int k) {
	assert(++queries <= 3 * n);
	assert(i != j && i != k && j != k && 1 <= min({i, j, k}) && max({i, j, k}) <= n);
	printf("1 %d %d %d\n", i, j, k);
	fflush(stdout);
	if(!hidden.empty()) {
		return abs((hidden[j] - hidden[i]) * (hidden[k] - hidden[i]));
	}
	ll r;
	scanf("%lld", &r);
	return r;
}

int main() {
	
	//~ {
		//~ P A = P{3, -1};
		//~ P B = P{-2, 1};
		//~ P C = P{1, -2};
		//~ debug() << imie((B - A) * (C - A));
	//~ }
	
	
	//~ hidden.push_back(P{-1, -1}); // fake
	//~ hidden.push_back(P{-5, 0});
	//~ hidden.push_back(P{-4, 3});
	//~ hidden.push_back(P{-3, 4});
	//~ hidden.push_back(P{0, 5});
	//~ hidden.push_back(P{3, 4});
	//~ hidden.push_back(P{4, 3});
	//~ hidden.push_back(P{5, 0});
	//~ hidden.push_back(P{4, -3});
	//~ hidden.push_back(P{3, -4});
	//~ hidden.push_back(P{0, -5});
	//~ hidden.push_back(P{-3, -4});
	//~ hidden.push_back(P{-4, -3});
	//~ hidden.push_back(P{-1, -1});
	//~ hidden.push_back(P{-2, 1});
	//~ hidden.push_back(P{3, -1});
	//~ hidden.push_back(P{-2, -1});
	//~ hidden.push_back(P{1, -2});
	//~ hidden.push_back(P{0, 3});
	//~ hidden.push_back(P{2, 2});
	//~ n = (int) hidden.size() - 1;
	//~ srand(2);
	//~ random_shuffle(hidden.begin() + 1, hidden.end());
	
	if(hidden.empty()) {
		scanf("%d", &n);
	}
	
	int A = 1;
	int B = 2;
	for(int i = 3; i <= n; ++i) {
		if(sign(A, B, i) == 1) {
			B = i;
		}
	}
	debug() << imie(B);
	vector<ll> dist(n + 1);
	int furthest = -1;
	for(int i = 2; i <= n; ++i) {
		if(i == B) {
			dist[i] = 0;
		}
		else {
			dist[i] = area(A, B, i);
			if(furthest == -1 || dist[furthest] < dist[i]) {
				furthest = i;
			}
		}
	}
	vector<int> L, R;
	for(int i = 2; i <= n; ++i) {
		if(i != furthest) {
			if(sign(A, furthest, i) == -1) {
				R.push_back(i);
			}
			else {
				L.push_back(i);
			}
		}
	}
	sort(L.begin(), L.end(), [&](int i, int j) {
		return dist[i] < dist[j];
	});
	sort(R.begin(), R.end(), [&](int i, int j) {
		return dist[i] > dist[j];
	});
	vector<int> all{A};
	for(int x : L) {
		all.push_back(x);
	}
	all.push_back(furthest);
	debug() << imie(A) imie(L) imie(furthest) imie(R);
	for(int x : R) {
		all.push_back(x);
	}
	reverse(all.begin(), all.end());
	while(all[0] != 1) {
		vector<int> tmp{all.back()};
		for(int i = 0; i < (int) all.size() - 1; ++i) {
			tmp.push_back(all[i]);
		}
		all = tmp;
	}
	printf("%d", 0);
	for(int x : all) {
		printf(" %d", x);
	}
	puts("");
	fflush(stdout);
	if(!hidden.empty()) {
		for(int i : all) {
			debug() << imie(hidden[i].x) imie(hidden[i].y);
		}
	}
	debug() << imie(n) imie(queries);
}