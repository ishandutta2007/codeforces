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

const int N = 1<<18;
int val[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, r;
	cin >> n >> r;
	int tot = 1<<n;

	ld expected = 0;
	for (int i=0; i<tot; i++) {
		cin >> val[i];
		expected += (ld) val[i] / tot;
	}

	cout << expected << nl;
	while (r--) {
		int id, x;
		cin >> id >> x;
		expected += (ld) (x - val[id]) / tot;
		val[id] = x;
		cout << expected << nl;
	}

	return 0;
}