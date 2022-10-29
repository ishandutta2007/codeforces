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
const int MAXN = 500500;

int n, ans;
int a[MAXN];
int sz;
int L[MAXN], R[MAXN];

int main() {

	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
		
	sz = 1;
	L[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i == n || a[i] == a[i - 1]) {
			R[sz - 1] = i - 1;
			
			if (i != n) {
				sz++;
				L[sz - 1] = i; 	
			}
		}
	}
	/*
	forn(i, sz)
		cout << L[i] << ' ' << R[i] << '\n';
	*/
	
	ans = 0;
	forn(i, sz) {
		int len = R[i] - L[i] + 1;
		if (len & 1) {
			ans = max(ans, len / 2);
			forab(j, L[i], R[i] + 1)
				a[j] = a[L[i]];
		} else {
			ans = max(ans, len / 2 - 1);
			forn(j, len / 2)
				a[L[i] + j] = a[L[i]];
			forn(j, len / 2)
				a[R[i] - j] = a[R[i]];			
		}
	}
	
	printf("%d\n", ans);
	forn(i, n)
		printf("%d ", a[i]);
		
	return 0;
}