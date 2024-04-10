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
const int MAXN = 1000500;

int n, q;
int s[2];
int t, x;

int main() {

	scanf("%d%d", &n, &q);
	s[0] = 0;
	s[1] = 1;
	
	forn(i, q) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d", &x);
			if (x < 0)
				x = n + x;
			x = n - x;
				
			if (!(x & 1)) {
				forn(j, 2)
					s[j] = (s[j] + x) % n;
			} else {
				int tmp = s[0];
				s[0] = (s[1] + x + n - 1) % n;
				s[1] = (tmp + x + n + 1) % n;
			}
		} else {
			swap(s[0], s[1]);	
		}
		
		//printf("%d %d\n", s[0], s[1]);
	}
	
	forn(i, n >> 1) {
		forn(j, 2)
			printf("%d ", (s[j] + 2 * i) % n + 1);	
	}
	
	return 0;
}