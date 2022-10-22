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
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	map<int,int> cnt;
	for(int i=1; i<=n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}

	vector<pii> order;
	for(const auto& [k,v] : cnt) {
		order.push_back(make_pair(v,k));
	}
	sort(order.begin(), order.end());

	int m = order.size();
	int psum[m+1];
	psum[0] = 0;
	for(int i=1; i<=m; i++) {
		psum[i] = psum[i-1] + order[i-1].first;
	}

	int area = -1;
	int best = -1;
	int s = sqrt(n);
	for(int i=s, j=m; i>0; i--) {
		while(j>0 && order[j-1].first>i) {
			j--;
		}
		int cur = psum[j] + i*(m-j);
		int olen = cur/i;
		if(olen >= i &&	i*olen > area) {
			area = i*olen;
			best = i;
		}
	}
	assert(best != -1);

	int olen = area / best;
	int g[best][olen];
	for(int i=0, j=0, k=m-1; k>=0; k--) {
		for(int t=0; t<min(best,order[k].first); t++) {
			//cerr<<"put "<<order[k].second<<" @ "<<i<<" "<<j<<nl;
			g[i++][j++] = order[k].second;
			if(i == best) {
				i = 0;
				j = (j+olen-(best-1)) % olen;
			}
			if(j == olen) {
				j = 0;
			}
		}
	}

	cout << area << nl;
	cout << best << " " << olen << nl;
	for(int i=0; i<best; i++) {
		for(int j=0; j<olen; j++) {
			cout << g[i][j] << " ";
		}
		cout << nl;
	}

	return 0;
}