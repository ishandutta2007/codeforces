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

const int N = 5e5+1;
vector<int> root(N,-1);
vector<int> sz(N,1);
int find(int i) {
	if (root[i] == -1) return i;
	return root[i] = find(root[i]);
}
void link(int i, int j) {
	if ((i=find(i)) != (j=find(j))) {
		root[i] = j;
		sz[j] += sz[i];
	}
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	for (int i=0; i<m; i++) {
		int k;
		cin >> k;
		for (int r,j=0; j<k; j++) {
			int a;
			cin >> a;
			if (j == 0) r = a;
			else link(a,r);
		}
	}

	for (int i=1; i<=n; i++) {
		cout << sz[find(i)] << " ";
	}
	cout << nl;

	return 0;
}