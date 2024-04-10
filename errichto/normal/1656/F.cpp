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

void test_case() {
	int n;
	scanf("%d", &n);
	vector<long long> a(n);
	long long sum = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	sort(a.begin(), a.end());
	long long answer = LONG_LONG_MIN;
	long long worst = LONG_LONG_MIN;
	long long pref = 0;
	
	for(int i = 0; i <= n - 2; ++i) {
		pref += a[i];
		long long tmp = pref * a.back() + (sum - a.back() - pref) * a[0];
		long long linear = pref + (i + 1) * a.back() + (sum - a.back() - pref) + (n - 2 - i) * a[0];
		auto f = [&](long long x) {
			//~ printf("%lld ", tmp - linear * x);
			long long value = tmp - linear * x;
			answer = max(answer, value);
			//~ cout << value << " ";
			return value;
		};
		f(a[i]);
		f(a[i+1]);
		if(i == 0 && f(a[i]-1) > f(a[i])) {
			puts("INF");
			return;
		}
		if(i == n - 2 && f(a[i+1]+1) > f(a[i+1])) {
			puts("INF");
			return;
		}
		//~ if(i == 0) {
			//~ worst = max(worst, f(a[i]-2));
		//~ }
		//~ if(i == n - 2) {
			//~ worst = max(worst, f(a[i+1]+2));
		//~ }
		//~ printf("(%lld, %lld), ", tmp - linear * a[i], tmp - linear * a[i+1]);
	}
	//~ debug() << imie(worst) imie(answer);
	//~ if(worst > answer) {
		//~ puts("INF");
	//~ }
	//~ else {
		printf("%lld\n", answer);
	//~ }
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}

//~ -2 -1 3

//~ -2 * 3 + -1 * -2 = -4 + -2t
// t = 1
//~ -2 * 3 + -1 * 3 = -9 + 3t