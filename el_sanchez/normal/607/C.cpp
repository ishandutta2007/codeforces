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
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 1000500;

ll MOD[4], P[4];

int n;
string s, t;
int a[2][MAXN];
ll pw[4][MAXN], h[4][2][MAXN], h1, h2;
int l[333];

bool eq(int L1, int R1, int L2, int R2) {
	bool ok = 1;
	forn(id, 4) {
		h1 = h[id][0][R1] - h[id][0][L1 - 1] * pw[id][R1 - L1 + 1];
		h1 %= MOD[id];
		h1 += MOD[id];
		h1 %= MOD[id];

		h2 = h[id][1][R2] - h[id][1][L2 - 1] * pw[id][R2 - L2 + 1];
		h2 %= MOD[id];
		h2 += MOD[id];
		h2 %= MOD[id];
		
		if (h1 != h2) {
			ok = 0;
			break;
		}
	}                     	
		
	return ok;
}

int main() {

	time_t timer;
	struct tm y2k = {0};
	
	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&timer);  /* get current time; same as: timer = time(NULL)  */

	ll seconds = ll(difftime(timer,mktime(&y2k)));
	
	MOD[0] = (ll)1E9 + 7;
	MOD[1] = (ll)1E9 + 9;
	MOD[2] = (ll)1E9 + seconds % 1000000;
	MOD[3] = (ll)1E9 + (seconds + 239) % 1000000;
	
	P[0] = 31;
	P[1] = 37;
	P[2] = 41;
	P[3] = 43;
	
	cin >> n;
	n--;
	cin >> s;
	cin >> t;
	reverse(all(t));
	
	l['N'] = 1;
	l['W'] = 2;
	l['E'] = 3;
	l['S'] = 4;  	
	
	a[0][0] = 0;
	a[1][0] = 0;
	for (int i = 0; i < n; i++) {
		a[0][i + 1] = l[(int)s[i]];
		a[1][i + 1] = 5 - l[(int)t[i]];		
	}
	
	for (int id = 0; id < 4; id++) {
		pw[id][0] = 1;
		for (int i = 1; i < MAXN; i++)
			pw[id][i] = (pw[id][i - 1] * P[id]) % MOD[id];

		for (int i = 0; i < 2; i++) {
			h[id][i][0] = a[i][0];
			for (int j = 1; j <= n; j++)
				h[id][i][j] = (h[id][i][j - 1] * P[id] + a[i][j]) % MOD[id];
		}
	}
	
	bool ok = 1;
	
	for (int len = 1; len <= n; len++)
		if (eq(len, n, 1, n - len + 1))
			ok = 0;                  	
	
	cout << (ok ? "YES\n" : "NO\n");
	
	return 0;
}