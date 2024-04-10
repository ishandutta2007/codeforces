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



int main() {
	int n;
	long long k;
	scanf("%d%lld", &n, &k);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		// a[i] = rand() % 1000000000;
		scanf("%d", &a[i]);
	}
	vector<int> answer(n);
	auto consider = [&](long long B, bool print = false) {
		// accept B or bigger
		long long cnt = 0;
		for(int i = 0; i < n; ++i) {
			// a[i] - 3x^2 - 3x - 1
			int low = -1, high = a[i] - 1;
			while(low < high) {
				int mid = (low + high + 1) / 2;
				if(a[i] - 3LL * mid * mid - 3LL * mid - 1 >= B) {
					low = mid;
				}
				else {
					high = mid - 1;
				}
			}
			if(print) {
				answer[i] = low + 1;
			}
			// last true
			cnt += low + 1;
		}
		if(print) {
			debug() << imie(cnt) imie(answer);
			for(int i = 0; i < n; ++i) {
				// a[i] - 3x^2 - 3x - 1
				int low = -1, high = a[i] - 1;
				while(low < high) {
					int mid = (low + high + 1) / 2;
					if(a[i] - 3LL * mid * mid - 3LL * mid - 1 >= B - 1) {
						low = mid;
					}
					else {
						high = mid - 1;
					}
				}
				while(answer[i] < low + 1 && cnt < k) {
					answer[i]++;
					cnt++;
				}
				// last true
			}
			debug() << imie(cnt) imie(answer);
			
		}
		return cnt;
	};
	long long INF = 4e18L * 1.01;
	long long low = -INF, high = INF;
	while(low < high) {
		long long mid = low + (high - low) / 2;
		long long cnt = consider(mid);
		if(cnt <= k) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	consider(low, true);
	for(int x : answer) {
		printf("%d ", x);
	}
	debug() << imie(low) imie(consider(low)) imie(consider(low-1));
	#ifdef LOCAL
	long long total = 0;
	for(int i = 0; i < n; ++i) {
		total += (long long) answer[i] * (a[i] - (long long) answer[i] * answer[i]);
	}
	debug() << imie(total);
	#endif
}