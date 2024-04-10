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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 200500;

int n;
int a[MAXN];
ll p[MAXN];
int sz, c;
int curSz, curC;

ll sum(ll L, ll R) {
	ll res = p[R];
	if (L > 0)
		res -= p[L - 1];
	return res;	
}

ld calc(int len, int med) {
	if (len < 0)	
		return -INF;
		
	ld res = a[med];
	res += sum(n - len, n - 1);
	res += sum(med - len, med - 1);
	res /= (2.0 * len + 1);
	res -= a[med];
	
	return res;
}

int main() {        

	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
	
	sort(a, a + n);
	
	p[0] = a[0];
	forab(i, 1, n)
		p[i] = p[i - 1] + a[i];
		
	sz = -1;
	curC = 0;
	
	for (curC = 0; curC < n; curC++) {
		int L = 0, R = min(curC, n - curC - 1), M1, M2;
		while (R - L >= 5) {
			M1 = L + (R - L) / 3;
			M2 = R - (R - L) / 3;

			if (calc(M1, curC) < calc(M2, curC))
				L = M1;
			else
				R = M2;	
		}
		
		for (int k = L; k <= R; k++) {
			if (calc(sz, c) < calc(k, curC)) {
				sz = k;
				c = curC;			
			}
		}
	}	
	
	cout << 2 * sz + 1 << '\n';
	
	printf("%d", a[c]);
	for (int i = 0; i < sz; i++)
		printf(" %d", a[c - 1 - i]);
	for (int i = 0; i < sz; i++)
		printf(" %d", a[n - 1 - i]);
	
	return 0;
}