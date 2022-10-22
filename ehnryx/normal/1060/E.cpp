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

const int N = 2e5+1;
ll odd[N], numst[N][2], sum[N], sumst[N];
vector<int> adj[N];

void solve(int u, int p) {
	if (sum[u] != -1) return;

	odd[u] = sum[u] = sumst[u] = 0;
	numst[u][0] = numst[u][1] = 0;
	for (int x : adj[u]) {
		if (x != p) {
			solve(x, u);
			sum[u] += sum[x];
			sumst[u] += (numst[x][0]+numst[x][1]) + 1 + sumst[x];
			odd[u] += odd[x];
			numst[u][0] += numst[x][1];
			numst[u][1] += 1 + numst[x][0];
		}
	}

	sum[u] += sumst[u];
	odd[u] += numst[u][1];
	ll totnum = numst[u][0] + numst[u][1];
	//cerr << " @ " << u << " : " << numst[u][1] << " " << odd[u] << nl;
	for (int x : adj[u]) {
		if (x != p) {
			ll totx = numst[x][0] + numst[x][1] + 1;
			sum[u] += (totx + sumst[x]) * (totnum - totx);
			////cerr << "paths " << totnum - totx << " * " << totx+sumst[x] << nl;
			odd[u] += (1+numst[x][0]) * (numst[u][0] - numst[x][1]);
		}
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

	int n, a, b;
	cin >> n;

	for (int i=1; i<n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(sum, -1, sizeof sum);
	solve(1, 0);
//#define DEBUG n
#ifdef DEBUG
	for (int i=1; i<=DEBUG; i++) {
		cout << i << " ------- " << nl;
		cout << "  sum: " << sum[i] << nl;
		cout << "  odd: " << odd[i] << nl;
		cout << "  sumst: " << sumst[i] << nl;
		cout << "  numst0: " << numst[i][0] << nl;
		cout << "  numst1: " << numst[i][1] << nl;
	}
#endif
	cout << (sum[1] + odd[1])/2 << nl;

	return 0;
}