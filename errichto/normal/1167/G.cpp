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

const double PI = 2 * acosl(0);

double get_angle(int distance) {
	return asinl(1.L /
		sqrt((long double) distance * distance + 1));
}

int main() {
	debug() << imie(PI);
	int n, magic_d;
	scanf("%d%d", &n, &magic_d);
	vector<int> a(n);
	vector<int> s;
	//~ set<int> s;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		s.push_back(a[i]);
		s.push_back(a[i]+1);
		//~ s.insert(a[i]);
		//~ s.insert(a[i] + 1);
	}
	
	sort(s.begin(), s.end());
	s.resize( unique(s.begin(), s.end()) - s.begin() );
	
	int a_i = 0, s_i = 0;
	
	int q;
	scanf("%d", &q);
	while(q--) {
		int x;
		scanf("%d", &x);
		while(a_i < n && a[a_i] < x) {
			++a_i;
		}
		while(s_i < (int) s.size() && s[s_i] < x) {
			++s_i;
		}
		// a_i is the first building that is
		// on the right from x
		if(a_i == n || a_i == 0) {
			printf("%.10lf\n", PI / 2);
			continue;
		}
		assert(1 <= a_i && a_i <= n - 1);
		assert(a[a_i] >= x);
		if(x == a[a_i] && x == a[a_i-1] + 1) {
			printf("%.10lf\n", PI);
			continue;
		}
		int distance = min(a[a_i] - x, x - a[a_i-1] - 1);
		double answer = get_angle(distance);
		
		// two pointers
		int A = s_i - 1;
		for(int B = s_i; B < (int) s.size(); ++B) {
			if(s[B] - x >= 2 * distance + 2) {
				break;
			}
			while(A >= 0 && s[B] - x > x - s[A]) {
				--A;
			}
			if(A < 0) {
				break;
			}
			if(s[B] - x == x - s[A]) {
				answer = max(answer, 2 * get_angle(x - s[A]));
				break;
			}
		}
		
		//~ for(int d = 1; d <= magic_d * 2; ++d) {
			//~ if(s.count(x + d) && s.count(x - d)) {
				//~ answer = max(answer, 2 * get_angle(d));
			//~ }
		//~ }
		printf("%.10lf\n", answer);
	}
}