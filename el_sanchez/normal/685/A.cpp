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
const int MAXN = 100500;

int n[2];
int dig[2];
int used[7], ans, res[2];

int main() {

	forn(i, 2) {
		cin >> n[i];

		int tmp = n[i];
		tmp--;
		
		if (tmp == 0)
			dig[i] = 1;
		else {
            dig[i] = 0;
			while (tmp > 0) {
				tmp /= 7;
				dig[i]++;
			}
		}
	}

	int len = dig[0] + dig[1];
	if (len > 7) {
		cout << 0 << '\n';
		return 0;
	}
	
	int MX = 1;
	forn(i, len) 
		MX *= 7;
		
	forn(mask, MX) {
		int T = mask;
		res[0] = res[1] = 0;
		forn(i, 7)
			used[i] = 0;
			
		bool ok = 1;
		
		forn(j, 2) {
			forn(i, dig[j]) {
				int d = T % 7;
				
				if (used[d])
					ok = 0;
				
				used[d] = 1;
				res[j] = res[j] * 7 + d;
				T /= 7;
			}
		}
		
		if (ok && res[0] < n[0] && res[1] < n[1])
			ans++;		
	}
	
	cout << ans;
	
	return 0;
}