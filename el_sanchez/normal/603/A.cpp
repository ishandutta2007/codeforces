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
    
int n, ans, sz;
string s;
int blocks[MAXN];

int main() {

	cin >> n;
	cin >> s;
	
	if (n <= 2) {
		cout << n << '\n';
		return 0;
	}
	
	ans = 0;
	
	sz = 0;
	int L = 0;
	for (int i = 1; i <= n; i++)
		if (i == n || s[i] != s[i - 1]) {
			blocks[sz++] = i - L;
			ans++;
			L = i;	
		}
	        
	forn(i, sz)
		if (blocks[i] >= 3) {
			ans += 2;
			cout << ans << '\n';
			return 0;
		}
		
	int cnt = 0;
	forn(i, sz)
		if (blocks[i] >= 2) {
			cnt++;
		}
		
	if (cnt >= 2) {
		ans += 2;
		cout << ans << '\n';
		return 0;
	}
	if (cnt == 1) {
		ans++;
		cout << ans << '\n';
		return 0;
	}
	
	cout << ans << '\n';
	
	return 0;
}