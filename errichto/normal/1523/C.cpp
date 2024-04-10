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

void print(vector<int> v) {
	printf("%d", v[0]);
	for(int i = 1; i < (int) v.size(); ++i) {
		printf(".%d", v[i]);
	}
	puts("");
}

void test_case() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> s;
	s.push_back({});
	while(n--) {
		int x;
		scanf("%d", &x);
		if(x == 1) {
			vector<int> v = s.back();
			v.push_back(1);
			print(v);
			s.push_back(v);
		}
		else {
			while(s.back().back() != x - 1) {
				s.pop_back();
			}
			s.back().back()++;
			print(s.back());
			// vector<int> v = s.back();
			// v.back()++;
			// print(v);
			// s.back() 
			// s.push_back(v);
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