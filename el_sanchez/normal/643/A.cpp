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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 5050;

int n;
int a[MAXN];
int ans[MAXN];
int id, times[MAXN];

int main() {

	cin >> n;
	forn(i, n) {
		cin >> a[i];
		a[i]--;	
	}
	
	memset(ans, 0, sizeof(ans));
	
	for (int L = 0; L < n; L++) {
		forn(i, n)
			times[i] = 0;
			
		id = n;
		for (int R = L; R < n; R++) {
			times[a[R]]++;
			if (times[id] < times[a[R]] || (times[id] == times[a[R]] && id > a[R]))
				id = a[R];
			ans[id]++;
		}
	}
	
	forn(i, n)
		cout << ans[i] << " \n"[i == n - 1];


	return 0;
}