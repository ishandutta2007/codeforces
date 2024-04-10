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
const int MAXN = 150500;
    
int n, d, h;

int main() {
	 
	cin >> n >> d >> h;
	
	if (d > 2 * h) {
		cout << -1 << '\n';
		return 0;
	}
	if (d == 1) { // => h = 1
		if (n == 2) {
		    printf("%d %d\n", 1, 2);
		} else {
			cout << -1 << '\n';	
		}
		
		return 0;
	}
	if (h == 1) {
		forn(i, n - 1)
			printf("%d %d\n", 1, i + 2);
		return 0;
	}
	
	int f = 2;
	//first path
	forn(i, h) {
		printf("%d %d\n", f - 1, f);
		f++;
	}
	
	//second path
	forn(i, d - h) {
		printf("%d %d\n", (i == 0 ? 1 : f - 1), f);
		f++;	
	}
	
	while (f <= n) {
		printf("%d %d\n", 2, f);
		f++;	
	}
	
	return 0;
}