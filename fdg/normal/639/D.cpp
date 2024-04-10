#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b;--i)
#define REP(i, n) FOR(i, 0, n)
#define forn(i,n) REP(i,n)
#define rfor(i,a,b) RFOR(i,a,b)
#define x first
#define y second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define sz(f) (int)f.size()
#define vi vector < int > 
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define y1 jaksflkajsf
#define pii pair<int,int>
#define pli pair<ll,int>
#define ld long double
const int INF = 1e9;
const int inf = 1e9;
const double PI = acos(-1.0);
const int MOD = 500000003;
const int N = 4e5;
int n, k;
long long b2, c;
long long cost[N];
long long sb[N];
long long S[N];
long long b[N];
pair < ll, ll > f[N];
int a[N];
int main() {
//	freopen("input.txt","r",stdin);
	ios :: sync_with_stdio(false);
	int n;
	cin >> n >> k >> b2 >> c;
	REP(i, n) {
		cin >> a[i];
	}
	if (c * 5 < b2)
		b2 = c * 5;
	sort(a, a + n);
	long long ans = 1LL * INF * INF;
	REP(ch, 5) {
		REP(i, n) {
			b[i] = a[i];
			cost[i] = 0;
			while ((b[i] % 5 + 5) % 5 != ch) {
				cost[i] += c;
				b[i]++;
			}
		}
		REP(i, n) f[i] = mp(b[i], cost[i]);
		sort(f, f + n);
		long long sum = 0;
		REP(i, k) sum += f[i].first;
		set < pair < long long, int > > S;
		long long res = (1LL * f[k - 1].first * k - sum) / 5 * b2;
		REP(i, k) res += f[i].second;
		REP(i, k) {
			S.insert(mp((f[k - 1].first - f[i].first) / 5 * b2 + f[i].second, i));
		}
		long long curMax = f[k - 1].first;
		ans = min(ans, res);
		FOR(i, k, n) {
			auto it = S.end(); --it;
			long long cost = f[i].second - (f[i].first - f[k - 1].first) / 5 * b2;
			if (cost < it->first) {
				res -= (curMax - f[it->second].first) / 5 * b2;
				res -= f[it->second].second;
				res += 1LL * (f[i].first - curMax) / 5 * b2 * (k - 1);
				res += f[i].second;
				S.erase(it);
				S.insert(mp(cost, i));
			} else {
				res += (f[i].first - curMax) / 5 * k * b2;
			}
			ans = min(ans, res);
			curMax = f[i].first;
		}
	}
	cout << ans << endl;
	return 0;	
}