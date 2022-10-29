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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 1000500;
const int MAXK = 21;
    
int lg2[MAXN];
int n, k;
int a[2][MAXN];
int sparse[2][MAXK][MAXN];
int ans[MAXN];
pii t[MAXN];
ld res;

int getMax(int id, int L, int R) {
	int len = R - L + 1;
	return max(sparse[id][lg2[len]][L], sparse[id][lg2[len]][R - (1 << lg2[len]) + 1]);	
}

int main() {

	lg2[0] = 0;
	lg2[1] = 0;
	for (int i = 2; i < MAXN; i++)
		lg2[i] = lg2[i >> 1] + 1;
		
	scanf("%d%d", &n, &k);
	forn(id, 2) {
		forn(i, n)
			scanf("%d", &a[id][i]);
			
		if (id == 1) {
			forn(i, n)
				a[id][i] *= -1;	
		}
		
		forn(i, n)
			sparse[id][0][i] = a[id][i];
			
		for (int L = 1; L < MAXK; L++)
			for (int i = 0; i + (1 << L) - 1 < n; i++)
				sparse[id][L][i] = max(sparse[id][L - 1][i], sparse[id][L - 1][i + (1 << (L - 1))]);
		
	}
	
	for (int i = 0; i < n; i++) {
		int L = i, R = n, M;
		while (R - L > 1) {
			M = (L + R) >> 1;
			if (100 * getMax(0, i, M) <= -getMax(1, i, M))
				L = M;
			else
				R = M;
		}
		ans[i] = min(100 * getMax(0, i, L), -getMax(1, i, L));
		if (R < n)
			ans[i] = max(ans[i], min(100 * getMax(0, i, R), -getMax(1, i, R)));
	}

	sort(ans, ans + n);
	reverse(ans, ans + n);
	
	cout.precision(15);
	
	res = 0;
	ld cnk = 1.0 * k / n;
	for (int i = n - 1; i >= 0; i--) {
		res += cnk * ans[i];
		if (i != 0)
			cnk *= 1.0 * (i + 1 - k) / i;	
		
		//cout << cnk << ' ' << ans[i] << '\n';	
	}
	
	cout << res << '\n';
	
	return 0;	
}