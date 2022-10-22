#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin>>n;
	int a[n+1],b[n+1],c[n+1];
	map<int,map<int,vector<pii>>> p;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>b[i]>>c[i];
		p[a[i]][b[i]].push_back(pii(c[i],i));
	}

	vector<pii> last;
	for(auto& plane : p) {
		vector<pii> cur;
		for(auto& line : plane.second) {
			auto& v = line.second;
			sort(v.begin(),v.end());
			while(v.size()>=2) {
				cout<<v.back().second<<" ";
				v.pop_back();
				cout<<v.back().second<<nl;
				v.pop_back();
			}
			if(!v.empty()) {
				cur.push_back(pii(line.first,v.back().second));
			}
		}
		sort(cur.begin(),cur.end());
		while(cur.size()>=2) {
			cout<<cur.back().second<<" ";
			cur.pop_back();
			cout<<cur.back().second<<nl;
			cur.pop_back();
		}
		if(!cur.empty()) {
			last.push_back(pii(plane.first,cur.back().second));
		}
	}
	sort(last.begin(),last.end());
	while(last.size()>=2) {
		cout<<last.back().second<<" ";
		last.pop_back();
		cout<<last.back().second<<nl;
		last.pop_back();
	}
	assert(last.empty());

	return 0;
}