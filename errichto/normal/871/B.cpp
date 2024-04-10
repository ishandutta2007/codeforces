#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

int ask(int a, int b) {
	printf("? %d %d\n", a, b);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

bool tmp[50005];

int main() {
	int n;
	scanf("%d", &n);
	vector<int> per(n), b(n);
	for(int i = 0; i < n; ++i)
		per[i] = ask(i, 0);
	for(int i = 0; i < n; ++i)
		b[i] = ask(0, i);
	
	int cnt = 0;
		
	vector<int> so(n), rev(n);
	vector<int> any;
	
	for(int start = 0; start < n; ++start) {
		// start = rev(0)
		bool ok = true;
		for(int i = 0; i < n; ++i) {
			so[i] = per[i] ^ start;
			if(0 <= so[i] && so[i] < n)
				rev[so[i]] = i;
			else {
				ok = false;
				break;
			}
		}
		if(!ok) continue;
		
		for(int i = 0; i < n; ++i) {
			if(tmp[so[i]]) {
				ok = false;
				break;
			}
			tmp[so[i]] = true;
		}
		for(int i = 0; i < n; ++i)
			tmp[i] = false;
		
		for(int i = 0; i < n; ++i)
			if(b[i] != (rev[i] ^ so[0])) {
				ok = false;
				break;
			}
		
		if(ok) {
			++cnt;
			if(any.empty()) any = so;
		}
	}
	puts("!");
	printf("%d\n", cnt);
	assert(!any.empty());
	for(int i = 0; i < (int) any.size(); ++i) {
		printf("%d", any[i]);
		if(i != (int) any.size() - 1) printf(" ");
	}
	puts("");
}