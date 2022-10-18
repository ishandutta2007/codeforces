#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b;--i)
#define REP(i, n) FOR(i, 0, n)
#define pii pair<int,int>
#define vi vector < int >
#define sz(a) (int)a.size()
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define y1 jaksflkajsf
#define pii pair<int,int>
#define pli pair<ll,int>
#define ld long double
#define pb push_back
#define mp make_pair

const int INF = 1e9+5;
const int inf = 1e9;
const int N = 4e5;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int MOD = 1e9 + 7;
int a[N];
int n, m, s, d;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, s, d;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	REP(i, n) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	if (d == 1) {
		puts("IMPOSSIBLE");
		return 0;
	}
	int now = 0;
	vector < pair < string, int > > ans;
	int i = 0;
	while (i < n) {
		if ((a[i] - 1) - now < s) {
			puts("IMPOSSIBLE");
			return 0;
		}
		int j = i;
		while (j < n - 1 && a[j + 1] - a[j] - 2 < s) j++;
		if ((a[j] - a[i] + 2) > d) {
			puts("IMPOSSIBLE");
			return 0;
		}
		ans.pb(mp("RUN", a[i] - 1 - now));
		ans.pb(mp("JUMP", a[j] - a[i] + 2));
		now = a[j] + 1;
		i = j + 1;
	}
	if (now != m)
		ans.pb(mp("RUN", m - now));
	REP(i, sz(ans)) {
		printf("%s %d\n", ans[i].first.c_str(), ans[i].second);
	}
	return 0;
}