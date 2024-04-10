#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
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

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main() {
	// CF #609, div1-C, K Integers   https://codeforces.com/contest/1268/problem/C
	int n;
	scanf("%d", &n);
	
	int B = 1;
	while(B < n) {
		B *= 2;
	}
	vector<long long> tree(2 * B);
	
	auto get_sum = [&](int L, int R) {
		if(L > R) {
			return 0LL;
		}
		L += B;
		R += B;
		long long s = tree[L];
		if(L != R) {
			s += tree[R];
		}
		while(L < R - 1) {
			if(L % 2 == 0) {
				s += tree[L+1];
			}
			if(R % 2 == 1) {
				s += tree[R-1];
			}
			L /= 2;
			R /= 2;
		}
		return s;
	};
	
	vector<int> in(n), where(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
		// in[i] = i + 1;
		--in[i]; // values from 0 to N-1
		where[in[i]] = i;
	}
	ordered_set positions;
	long long inversions = 0;
	// vector<int> positions; // ordered_set
	for(int value = 0; value < n; ++value) {
		int pos = where[value];
		inversions += (int) positions.size() - positions.order_of_key(pos);
		positions.insert(pos);
		
		for(int i = B + pos; i >= 1; i /= 2) {
			tree[i] += pos;
		}
		
		// 4 8 10 12       pos=11
		// sort(positions.begin(), positions.end());
		int im = positions.size() / 2;
		int pos_im = *positions.find_by_order(im);
		long long answer = get_sum(pos_im + 1, n - 1);
		answer -= get_sum(0, pos_im - 1);
		// int L = positions[im];
		int first = pos_im + 1;
		int last = pos_im + (int) positions.size() - im - 1;
		answer -= (long long) (first + last) * (last - first + 1) / 2;
		// pos_im+1 pos_im+2 ...
		// for(int i = im + 1; i < (int) positions.size(); ++i) {
			// answer += /* *positions.find_by_order(i) */ - ( pos_im + (i-im));
		// }
		first = pos_im - 1;
		last = pos_im - im;
		swap(first, last);
		answer += (long long) (first + last) * (last - first + 1) / 2;
		// for(int i = im - 1; i >= 0; --i) {
			// answer += (pos_im - (im - i)) /* - *positions.find_by_order(i) */ ;
		// }
		// for(int i = 0; i < (int) positions.size(); ++i) {
			// for(int j = i + 1; j < (int) positions.size(); ++j) {
				// if(in[*positions.find_by_order(i)] > in[*positions.find_by_order(j)]) {
					// answer++;
				// }
			// }
		// }
		printf("%lld ", answer + inversions);
	}
	puts("");
}
        // m
        // v
// _ 2 _ 5 1 _ 4 _ _ 3 _ _ 6 _
// _ _ 2 5 1 4 3 6 _ _ _ _ _ _
       

// 5 2 1 4 6 3
  // ===
  // =========