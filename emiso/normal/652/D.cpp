#include <bits/stdc++.h>
using namespace std;

struct seg {
	int l, r, id;
	bool operator <(const seg &o) const {
		return r < o.r;
	}
};
vector<seg> v;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int n, l, r, ans[200020], co;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &l, &r);
		v.push_back(seg{l, r, i});
	}
	sort(v.begin(), v.end());
	

	oset t;
	for(seg s : v) {
		ans[s.id] = co - t.order_of_key(s.l);
		t.insert(s.l);
		co++;
	}
	
	for(int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}
}