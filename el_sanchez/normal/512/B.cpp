#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define gcd(a, b) __gcd((a), (b))

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 333;
const int MAXM = 113333;

int dp[MAXN][MAXM]; 

int n;
int a[MAXN], c[MAXN];
ll cur;
vi divisors;
vector<pii> primes;

void gen(int pos) {
	if (pos == primes.size()) { 
		divisors.pb(cur);
		return;
	}
	
	forn(i, primes[pos].Y + 1) {
		gen(pos + 1);
		cur *= primes[pos].X;	
	}
	forn(i, primes[pos].Y + 1)
		cur /= primes[pos].X;
}

int main() {

	cin >> n;
	forn(i, n)
		cin >> a[i];
	forn(i, n) 
		cin >> c[i];
		
	forn(i, n) {
		primes.clear();
		cur = a[i];
		for (ll j = 2; j * j <= cur; j++) {
			if (cur % j == 0) {
				primes.pb({j, 0});
				while (cur % j == 0) {
					cur /= j;
					primes.back().Y++;
				}
			}		
		}
		if (cur > 1)
			primes.pb({cur, 1});
		
		cur = 1;
		gen(0); 			
	}
	
	divisors.pb(0);
	sort(all(divisors));
	int m = unique(all(divisors)) - divisors.begin();
	divisors.resize(m);

	forn(i, n + 1)
		forn(j, m)
			dp[i][j] = INF;
	dp[0][0] = 0;

	forn(i, n) {
		forn(j, m) {
			if (dp[i][j] == INF)
				continue;
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			int g = gcd(a[i], divisors[j]);
			int id = lower_bound(all(divisors), g) - divisors.begin();
			assert(divisors[id] == g);
			dp[i + 1][id] = min(dp[i + 1][id], dp[i][j] + c[i]);	
		}
	}
	
	if (dp[n][1] == INF)
		cout << -1;
	else
		cout << dp[n][1] << '\n';
		
	return 0;
}