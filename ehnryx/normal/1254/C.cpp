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

ll ask(int t, int a, int b, int c) {
	cout<<t<<" "<<a<<" "<<b<<" "<<c<<endl;
	ll r;
	cin>>r;
	return r;
}

vector<int> order(const vector<int>& in, int a, int b) {
	if(in.empty()) return in;

	ll maxv = 0;
	int top = -1;
	vector<pll> vals;
	for(int i:in) {
		ll area = ask(1, a, b, i);
		vals.push_back(pll(area,i));
		if(area > maxv) {
			maxv = area;
			top = i;
		}
	}
	assert(top != -1);

	vector<pll> before;
	vector<pll> after;
	for(pll it:vals) {
		if(it.second == top) continue;
		int s = ask(2, a, top, it.second);
		if(s == 1) {
			after.push_back(it);
		} else {
			before.push_back(it);
		}
	}
	sort(before.begin(), before.end());
	sort(after.begin(), after.end(), greater<pll>());

	vector<int> out;
	for(pll it:before) {
		out.push_back(it.second);
	}
	out.push_back(top);
	for(pll it:after) {
		out.push_back(it.second);
	}
	return out;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin>>n;

	int a = 1;
	int b = 2;
	vector<int> before;
	vector<int> after;
	for(int i=3;i<=n;i++) {
		int s = ask(2, a, b, i);
		if(s == 1) {
			after.push_back(i);
		} else {
			before.push_back(i);
		}
	}

	vector<int> p;
	p.push_back(a);
	for(int it:order(before, a, b)) {
		p.push_back(it);
	}
	p.push_back(b);
	for(int it:order(after, b, a)) {
		p.push_back(it);
	}

	cout<<0;
	for(int it:p) {
		cout<<" "<<it;
	}
	cout<<endl;

	return 0;
}