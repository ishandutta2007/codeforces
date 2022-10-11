#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag,tree_order_statistics_node_update>;

#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

ll n, m, q, pass, maxa, turn, cval, pt;
ll a[500005], to[500005], ans[500005];
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag,tree_order_statistics_node_update>;

/* ------------------------------------------------------------------------ COMMENTS ------------------------------------------------------------------------ */
/* supports things like k-th smallest element and find index of element in set */
/* all in pretty good O(lgn) */

/* example usage */
ordered_set<int> os;

/* extra functions (in addition to std::set operations):
	find_by_order(k) - returns a pointer to the k-th smallest element in the set (zero-indexed)
	order_of_key(k) - returns the number of elements in the set less than k (if k is in the set, this is the index of it)
*/

/* gfg: https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/ 
	examples:
	set = {1, 5, 6, 17, 88}
	find_by_order(1) - same as set[1] -> pointer to 5
	find_by_order(4) - same as set[4] -> pointer to 88
	order_of_key(6) -> 2
	order_of_key(88) -> 4
	order_of_key(400) -> 5
	order_of_key(0) -> 0
*/

/* implementing a multiset */

template <typename num_t>
struct ordered_multiset {
	ordered_set<pair<num_t, int> > vals;
	set<pair<int, int> > best; /* start at -1 */
	
	/* helper, find the lowest value that represents the element */
	int findbest (int val) {
		return (*best.upper_bound(make_pair(val - 1, 0))).second;
	}
	
	/* is element in set */
	bool has(int val) {
		return vals.find(make_pair(val, -1)) != vals.end();
	}
	
	void insert(int val) {
		if (has(val)) { /* already in, update lowest value and insert a new one */
			int loc = findbest(val);
			best.erase(make_pair(val, loc));
			best.insert(make_pair(val, loc - 1));
			vals.insert(make_pair(val, loc - 1));
		} else { /* make lowest value -1 and insert it */
			best.insert(make_pair(val, -1));
			vals.insert(make_pair(val, -1));
		}
	}
	
	void remove(int val) {
		if (!has(val)) return; /* not in */
		int loc = findbest(val);
		
		/* remove the element and its best */
		best.erase(make_pair(val, loc));
		vals.erase(make_pair(val, loc));
		if (loc != -1) best.insert(make_pair(val, loc + 1)); /* more elements in set, update best */
	}
};
	
ordered_multiset<int> nums;

struct entry {
  ll val, ind;
};
typedef struct entry entry;

entry qu[500005], asort[500005];

bool ecomp(entry &e1, entry &e2) {
  if (e1.val == e2.val) return e1.ind < e2.ind;
  return e1.val < e2.val;
}

int main() {
  io;
  cin >> n >> m >> q;

  ms(a, 0);
  ms(ans, 0);

  f0r(i, n) cin >> to[i];
  f0r(i, n) a[--to[i]]++;

  f0r(i, m) {
    asort[i].ind = i;
    asort[i].val = a[i];
  }

  sort(asort, asort + m, ecomp);

  maxa = 0;
  f0r(i, m) maxa = max(a[i], maxa);
  f0r(i, q) {
    qu[i].ind = i;
    cin >> qu[i].val;
  }

  turn = n; /* already passed */
  cval = asort[0].val;
  pt = 0;
  while (pt < m && asort[pt].val == cval) nums.insert(asort[pt++].ind);

  sort(qu, qu + q, ecomp);
  f0r(pass, q) {
    ll req = qu[pass].val;
    if (req > maxa * m) {
      ll f = maxa * m;
      ans[qu[pass].ind] = ((req - f - 1) % m) + 1;
      continue;
    }

    while (turn < req) {
      if (turn + nums.vals.size() >= req) {
        ans[qu[pass].ind] = (*nums.vals.find_by_order(((req - turn - 1) % m))).first + 1;
        break;
      } 
      cval++;
      turn += nums.vals.size();
      while (pt < m && asort[pt].val == cval) nums.insert(asort[pt++].ind);
    }
  }

  f0r(i, q) cout << ans[i] << endl;
}