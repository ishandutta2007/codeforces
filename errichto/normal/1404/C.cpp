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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef
tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

int main() {
	ordered_set test;
	// test.insert(2);
	// test.insert(2);
	// assert((int) test.size() == 2);
	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n + 1);
	vector<int> L_at_most(n + 1);
	// blue[5]=2 means that element at position 5
		// gets remove iff L <= 2
	ordered_set pref;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(a[i] == i) {
			L_at_most[i] = i;
		}
		else if(a[i] < i) {
			int diff = i - a[i];
			if(diff <= (int) pref.size()) {
				// sort(pref.rbegin(), pref.rend());
				L_at_most[i] = pref.find_by_order((int)pref.size()-1-(diff-1))->first;
			}
		}
		pref.insert(make_pair(L_at_most[i],i));
	}
	debug() << imie(L_at_most);
	vector<vector<pair<int,int>>> queries(n + 1);
	for(int id = 1; id <= q; ++id) {
		int L, R;
		scanf("%d%d", &L, &R);
		L++;
		R = n - R;
		queries[R].emplace_back(id, L);
	}
	vector<int> answer(q + 1);
	pref.clear();
	for(int R = 1; R <= n; ++R) {
		pref.insert(make_pair(L_at_most[R], R));
		for(pair<int,int> pp : queries[R]) {
			int id = pp.first;
			int L = pp.second;
			answer[id] = pref.size() - pref.order_of_key(make_pair(L, -1));
// the number of items in a set that are strictly smaller than our item
				// if(L_at_most[i] >= L) {
					// ans++;
			// answer[id] = ans;
		}
	}
	for(int id = 1; id <= q; ++id) {
		printf("%d\n", answer[id]);
	}
}