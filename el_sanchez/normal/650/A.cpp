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
#define db(x) cerr << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 200500;

int n;
pii a[MAXN];
ll ans;
map<int, int> curInX, curInY;
map<pii, int> cur;

int main() {
        
	scanf("%d", &n);
	forn(i, n)
		scanf("%d%d", &a[i].X, &a[i].Y);

	forn(i, n) {
		curInX[a[i].X]++;
		curInY[a[i].Y]++;
		cur[a[i]]++;		
	}
		
	ans = 0;
	
	forn(i, n) {
		ans += (curInX[a[i].X] + curInY[a[i].Y] - 1 - cur[a[i]]);
		
		curInX[a[i].X]--;
		curInY[a[i].Y]--;
		cur[a[i]]--;		
	}
	
	cout << ans << '\n';
	
	return 0;	
}