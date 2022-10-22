#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5+1;
int a[2*N];
int x[N], y[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	int maxv = -1;
	int id = -1;
	For(i,n) {
		cin >> a[i];
		if (a[i] > maxv) {
			maxv = a[i];
			id = i;
		}
	}

	int cur = a[0];
	For(i,id) {
		x[i] = cur;
		y[i] = a[i+1];
		if (a[i+1] > cur) {
			a[n+i] = cur;
			cur = a[i+1];
		} else {
			a[n+i] = a[i+1];
		}
	}

	while (m--) {
		ll v;
		cin >> v;
		if (v <= id) {
			cout << x[v-1] << " " << y[v-1] << nl;
		} else {
			v -= id;
			cout << a[id] << " " << a[id+1+(v-1)%(n-1)] << nl;
		}
	}

	return 0;
}