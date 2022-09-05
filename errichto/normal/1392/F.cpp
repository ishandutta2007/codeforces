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

// 2, 3, 3, 4, 10
// 2, 3, 3, 7, 7
// 2, 3, 5, 5, 7
// 2, 4, 4, 6, 6
// 3, 3, 5, 5, 6
// 3, 4, 4, 5, 6

// 2, 3, 3, 4, 9
// 2, 3, 3, 6, 7
// 2, 3, 4, 5, 7
// 2, 3, 4, 6, 6
// 2, 3, 5, 5, 6
// 2, 4, 4, 5, 6
// 3, 3, 4, 5, 6

void relax(vector<int>& a) {
	int n = a.size();
	while(true) {
		bool any = false;
		for(int i = 0; i < n - 1; ++i) {
			if(a[i] + 2 <= a[i+1]) {
				a[i]++;
				a[i+1]--;
				any = true;
			}
		}
		if(!any) break;
	}
}

using ll = long long;

ll sum_ari(ll start, int len) {
	ll end = start + len - 1;
	return len * (start + end) / 2;
}

struct Interval {
	ll start, end;
	ll len() const {
		return end - start + 1;
	}
	ll sum_ari() const {
		return ::sum_ari(start, len());
	}
	void print(debug& dd) {
		dd << "( " imie(start) imie(end) "), ";
	}
};
debug & operator << (debug & dd, Interval in) { in.print(dd); return dd; }



int main() {
	// vector<int> a{2, 3, 3, 3, 4, 5, 5, 5, 6, 7, 8, 8};
	// for(int x = 9; x <= 100; ++x) {
		// vector<int> b = a;
		// b.push_back(x);
		// relax(b);
		// debug() << imie(b);
	// }
	int n;
	scanf("%d", &n);
	vector<Interval> a;
	vector<int> for_brute;
	for(int rep = 0; rep < n; ++rep) {
		long long my_sum;
		scanf("%lld", &my_sum);
		for_brute.push_back(my_sum);
		long long memo_ai = my_sum;
		int my_len = 1;
		while(true) {
			if(a.empty()) {
				break;
			}
			ll first = a.back().end;
			if(my_sum <= sum_ari(first, my_len)) {
				break;
			}
			my_sum += a.back().sum_ari();
			// debug() << "+" imie(a.back().len());
			my_len += a.back().len();
			a.pop_back();
		}
		ll low = 0, high = memo_ai;
		ll first = 0;
		while(low <= high) {
			ll mid = (low + high) / 2;
			if(sum_ari(mid, my_len) < my_sum) {
				low = mid + 1;
			}
			else {
				first = mid;
				high = mid - 1;
			}
		}
		// while(sum_ari(first, my_len) < my_sum) {
			// ++first;
		// }
		// debug() << imie(memo_ai) imie(first) imie(my_sum);
		long long diff = sum_ari(first, my_len) - my_sum;
		if(rep == n - 1) {
			// debug() << imie(my_sum) imie(first) imie(sum_ari(first, my_len)) imie(my_len) imie(diff) imie(a.size());
		}
		assert(diff < my_len);
		if(diff >= 1) {
			int other = my_len - diff;
			a.push_back(Interval{first, first + other - 1});
			a.push_back(Interval{first + other - 1, first + my_len - 2});
		}
		else {
			a.push_back(Interval{first, first + my_len - 1});
		}
		// debug() << imie(a);
		// debug();
	}
	#ifdef LOCAL
		relax(for_brute);
		debug() << imie(for_brute);
	#endif
	for(Interval inte : a) {
		for(ll x = inte.start; x <= inte.end; ++x) {
			printf("%lld ", x);
		}
	}
	puts("");
	// debug() << imie(a);
}