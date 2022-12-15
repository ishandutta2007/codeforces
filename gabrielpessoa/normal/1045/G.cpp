#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> ii;
typedef long long int ll;

typedef tree<ii, null_type, less<ii>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

struct robot {
	int x, r, iq;
	robot(int a = 0, int b = 0, int c = 0) {
		x = a;
		r = b;
		iq = c;
	}
	bool operator < (robot &other) const{
		return x < other.x;
	}
};
	
const int N = 200200; 
const int M = 4100041;
const int inf = 2e9 + 1;

int n, k;
vector<robot> all;
vector<int> comp;
priority_queue<ii, vector<ii>, greater<ii>> pq;
ordered_set magic[M];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x, r, iq;
		scanf("%d %d %d", &x, &r, &iq);
		all.push_back(robot(x, r, iq));
		for (int j = iq - k; j <= iq + k; j++) {
			comp.push_back(j);
		}
	}
	sort(all.begin(), all.end());
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		//cout << i << ":\n";
		while(!pq.empty()) {
			ii cur = pq.top();
			if (cur.first >= all[i].x) break;
			int ret = cur.second;
			int id_ret = lower_bound(comp.begin(), comp.end(), all[ret].iq) - comp.begin();
			magic[id_ret].erase(ii(-all[ret].x, ret));
			//cout << ret << '\n';
			pq.pop();
		}
		int id = lower_bound(comp.begin(), comp.end(), all[i].iq) - comp.begin();
		for (int j = id - k; j <= id + k; j++) {
			if (magic[j].empty()) continue;
			ans += (ll) magic[j].order_of_key(ii(-(all[i].x - all[i].r), inf));
		}
		magic[id].insert(ii(-all[i].x, i));
		pq.push(ii(all[i].x + all[i].r, i));
	}
	cout << ans << '\n';
	return 0;
}