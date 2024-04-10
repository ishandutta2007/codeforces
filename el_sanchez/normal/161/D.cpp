#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <queue>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 50100;
const int MAXM = 510;

int n, k, kk, a, b;
bool used[MAXN];
int64 dp[MAXN], m[MAXN][MAXM], cm[MAXM];
vi w[MAXN];

void dfs(int v) {
	if (used[v]) return;

	used[v] = 1;
	dp[v] = 0;
	m[v][0] = 1;
	forn(i, w[v].size())
		if (!used[w[v][i]]) {
			dfs(w[v][i]);
			dp[v] += dp[w[v][i]];
			forn(j, k + 1) 
				cm[j + 1] = m[w[v][i]][j];
			
			forn(j, kk + 1)
				dp[v] -= (cm[j] * cm[k - j]);
			if (k % 2 == 0)
				dp[v] -= (cm[k / 2] * (cm[k / 2] - 1) / 2);

			forn(j, k + 2)
				m[v][j] += cm[j];
		}

	forn(j, kk + 1)
		dp[v] += (m[v][j] * m[v][k - j]);
	if (k % 2 == 0)
		dp[v] += m[v][k / 2] * (m[v][k / 2] - 1) / 2;
}

int main() {

	cin >> n >> k;
	forn(i, n - 1) {
		cin >> a >> b;
		w[a].push_back(b);
		w[b].push_back(a);
	}
	
	kk = (k % 2) ? (k / 2) : (k / 2 - 1);
	dfs(1);
	cout << dp[1] << endl;

    return 0;
}