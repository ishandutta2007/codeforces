#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(A) (int)A.size()
#define RFOR(i,a,b) for (int (i) = (a); (i) >= (b); --(i))
#define ll long long
#define sz(A) (int)A.size()

#define FREIN(FILE) freopen(FILE,"rt",stdin)
#define FREOUT(FILE) freopen(FILE,"wt",stdout)

typedef vector < int > vi;
typedef pair <int, int> pii;
const int MOD = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1000000000; //1e9
const int inf = 1e9+1;
const double eps = 1e-9;
int cnt[5005];
int a[5005];
int ans[5005];
bool used[1005];
int main() {
	//FREIN("input.txt");	
	int n, k, a, b, c, d;
	cin >> n >> k >> a >> b >> c >> d;
	a--; b--; c--; d--;
	used[a] = used[b] = used[c] = used[d] = true;
	vi f;
	REP(i, n) {
		if (!used[i]) {
			f.pb(i);
		}
	}
	if (n == 4) {
		cout << -1 << endl;
		return 0;
	}
	int need = n - 5 + 6;
	if (k < need) {
		cout << -1 << endl;
		return 0;
	}
	cout << a + 1 << " " << c + 1 << " ";
	for (auto e : f) cout << e + 1 << " ";
	cout << d + 1 << " " << b + 1 << endl;
	cout << c + 1 << " " << a + 1 << " ";
	for (auto e : f) cout << e + 1 << " ";
	cout << b + 1 << " " << d + 1 << endl;
	return 0;
}