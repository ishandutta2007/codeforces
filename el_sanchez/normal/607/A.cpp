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
const int MAXN = 100500;

int n;
int ans[MAXN], res;
pii a[MAXN];

int main() {

	scanf("%d", &n);
	forn(i, n) {
		scanf("%d%d", &a[i].X, &a[i].Y);
	}
	
	sort(a, a + n);
	
	ans[0] = 1;
	for (int i = 1; i < n; i++) {
		int L = -1, R = i, M;
		while (R - L > 1) {
			M = (L + R) >> 1;
			if (abs(a[i].X - a[M].X) <= a[i].Y)
				R = M;
			else
				L = M;
		}
		
		if (L == -1)
			ans[i] = 1;
		else
			ans[i] = ans[L] + 1;
	}

	res = 0;
	forn(i, n)
		res = max(res, ans[i] + 1);
	res = n + 1 - res;
	cout << res << '\n';
	return 0;
}