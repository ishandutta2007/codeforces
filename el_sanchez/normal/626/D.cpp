#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 5010;

int n;
int a[MAXN];
int cnt[MAXN];
ll pref[MAXN];
ll ans, cur;
ld res;

int main() {        
	
	cin >> n;
	forn(i, n)
		cin >> a[i];
		
	sort(a, a + n);
	
	forn(i, n)
		for (int j = i + 1; j < n; j++)
			cnt[a[j] - a[i]]++;

	ans = 0;
	
	for (int c = 2; c < MAXN; c++) {
		for (int i = 1; i < c; i++)
			pref[i] += cnt[c - 1 - i];

		cur = 0;
		for (int i = 1; i < c; i++)
			cur += cnt[i] * pref[i];	
		cur *= cnt[c];
		
		ans += cur;
	}
	
	//cout << ans << '\n';
	
	res = ans;
	forn(i, 3)
		res /= 1.0 * n * (n - 1) / 2;
		
	cout.precision(30);
	cout << res << '\n';
	
	return 0;
}