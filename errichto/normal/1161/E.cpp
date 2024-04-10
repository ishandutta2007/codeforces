#include "bits/stdc++.h"
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

vector<int> hidden{1, 1, 1};

vector<bool> query(vector<pair<int,int>> w) {
	if(w.empty()) {
		return {};
	}
	printf("Q %d", (int) w.size());
	for(pair<int,int> p : w) {
		printf(" %d %d", p.first, p.second);
	}
	puts("");
	fflush(stdout);
	
	//~ vector<bool> ple;
	//~ for(pair<int,int> p : w) {
		//~ ple.push_back(hidden[p.first-1] == hidden[p.second-1]);
	//~ }
	//~ return ple;
	
	
	static char sl[200123];
	scanf("%s", sl);
	vector<bool> r(w.size());
	for(int i = 0; i < (int) r.size(); ++i) {
		r[i] = (sl[i] == '1');
	}
	return r;
}

void test_case() {
	int n;
	scanf("%d", &n);
	//~ n = hidden.size();
	if(n == 1) {
		puts("A 1 0 0");
		puts("1");
		puts("");
		puts("");
		fflush(stdout);
		return;
	}
	vector<pair<int,int>> one, two;
	for(int i = 1; i <= n - 1; i += 2) {
		one.push_back({i, i + 1});
	}
	vector<bool> A = query(one);
	for(int i = 2; i <= n - 1; i += 2) {
		two.push_back({i, i + 1});
	}
	vector<bool> B = query(two);
	vector<bool> eq_to_next(n - 1);
	for(int i = 0; i < (int) A.size(); ++i) {
		eq_to_next[2*i] = A[i];
	}
	for(int i = 0; i < (int) B.size(); ++i) {
		eq_to_next[2*i+1] = B[i];
	}
	
	vector<pair<int,int>> segs;
	for(int i = 0; i < n; ++i) {
		int j = i;
		while(j < n - 1 && eq_to_next[j]) {
			++j;
		}
		segs.emplace_back(i + 1, j + 1);
		i = j;
	}
	debug() << imie(segs);
	
	one.clear();
	for(int i = 0; i + 2 < (int) segs.size(); i += 4) {
		one.push_back({segs[i].second, segs[i+2].first});
		if(i + 3 < (int) segs.size())
		one.push_back({segs[i+1].second, segs[i+3].first});
	}
	A = query(one);
	
	two.clear();
	for(int i = 2; i + 2 < (int) segs.size(); i += 4) {
		
		two.push_back({segs[i].second, segs[i+2].first});
		if(i + 3 < (int) segs.size())
		two.push_back({segs[i+1].second, segs[i+3].first});
	}
	B = query(two);
	
	vector<int> type(segs.size());
	if((int) segs.size() >= 2) {
		type[1] = 1;
	}
	for(int i = 2; i < (int) segs.size(); ++i) {
		bool bit;
		int j = i - 2;
		if((j / 2) % 2 == 0) {
			bit = A[j / 2 + j % 2];
		}
		else {
			bit = B[(j - 2) / 2 + j % 2];
		}
		//~ if(i % 2 == 0) {
			//~ bit = A[(i-2)/2];
		//~ }
		//~ else {
			//~ bit = B[(i-3)/2];
		//~ }
		if(bit) {
			type[i] = type[i-2];
		}
		else {
			type[i] = 0 + 1 + 2 - type[i-1] - type[i-2];
		}
	}
	vector<vector<int>> division(3);
	for(int i = 0; i < (int) segs.size(); ++i) {
		pair<int,int> seg = segs[i];
		for(int x = seg.first; x <= seg.second; ++x) {
			division[type[i]].push_back(x);
		}
	}
	printf("A %d %d %d\n", (int) division[0].size(), (int) division[1].size(), (int) division[2].size());
	for(vector<int> vec : division) {
		for(int i = 0; i < (int) vec.size(); ++i) {
			printf("%d", vec[i]);
			if(i != (int) vec.size() - 1) {
				printf(" ");
			}
		}
		puts("");
	}
	fflush(stdout);
}

int main() {
	int T;
	//~ T = 1;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}