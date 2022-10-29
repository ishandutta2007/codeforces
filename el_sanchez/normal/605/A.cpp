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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;

int n, ans;
int a[MAXN], pos[MAXN];

int main() {

	cin >> n;
	forn(i, n) {
		cin >> a[i];
		a[i]--;
	}
		
	forn(i, n) {
		pos[a[i]] = i;	
	}
	
	ans = n;
	int L = 0;
	forab(i, 1, n + 1)
		if (i == n || pos[i - 1] > pos[i]) {
			int R = i - 1;
			ans = min(ans, n - (R - L + 1));
			L = i;	
		}
	
	cout << ans << '\n';
			
	return 0;
}