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

int ask(int n, int b) {
	string s;
	for(int i=0; i<n; i++) {
		s.push_back(i==b ? 'b' : 'a');
	}
	cout << s << endl;
	int res;
	cin >> res;
	if(res == 0) exit(0);
	return res;
}

void answer(const vector<bool>& b) {
	int n = b.size();
	string s;
	for(int i=0; i<n; i++) {
		s.push_back(b[i] ? 'b' : 'a');
	}
	cout << s << endl;
	int res;
	cin >> res;
	assert(res == 0);
	exit(0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int len = ask(1, -1) + 1;
	if(len > 300) {
		answer(vector<bool>(len-1, true));
	}
	int res = ask(len, -1);
	if(res == len) {
		answer(vector<bool>(len-1, true));
	} else {
		assert(res < len);
	}

	vector<bool> b(len, false);
	int cnt = 0;
	for(int i=1; i<len; i++) {
		b[i] = (ask(len, i) < res);
		if(b[i]) cnt++;
	}
	b[0] = (cnt < res);
	answer(b);

	return 0;
}