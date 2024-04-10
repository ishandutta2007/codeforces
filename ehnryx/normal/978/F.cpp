#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;

	int skill[n+1];
	vector<pii> order;
	for (int i = 1; i <= n; i++) {
		cin >> skill[i];
		order.push_back(pii(skill[i],i));
	}
	sort(order.begin(), order.end());

	vector<int> bad(n+1, 0);
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		if (skill[a] > skill[b]) {
			bad[a]++;
		} else if (skill[b] > skill[a]) {
			bad[b]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << (lower_bound(order.begin(), order.end(), pii(skill[i],-INF)) - order.begin()) - bad[i] << " ";
	}
	cout << nl;

	return 0;
}