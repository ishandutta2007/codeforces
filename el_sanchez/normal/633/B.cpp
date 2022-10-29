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
const int MAXN = 100500;

int n;
vi ans;
int c2, c5;

int main() {

	cin >> n;
	c2 = c5 = 0;
	for (int i = 1; ; i++) {
		int t = i;
		while (t % 2 == 0) {
			t /= 2;
			c2++;
		}
		while (t % 5 == 0) {
			t /= 5;
			c5++;
		}
		
		if (min(c2, c5) == n)
			ans.pb(i);
		if (min(c2, c5) > n)
			break;
	}
		
	cout << ans.size() << '\n';
	for (auto a: ans)
		printf("%d ", a);
		
    return 0;
}