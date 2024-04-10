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
const int MAXN = 222;

int n, m;
int ans;
int cnt[2], rest[2];

int main() {        

	cin >> n >> m;
	int L = 0, R = INF, mid;
	while (R - L > 1) {
		mid = (L + R) >> 1;
		
		bool ok = 1;
		cnt[0] = mid / 2 - mid / 6;
		cnt[1] = mid / 3 - mid / 6;
		
		rest[0] = max(0, n - cnt[0]);
		rest[1] = max(0, m - cnt[1]);
		
		if (rest[0] + rest[1] <= mid / 6)
			ok = 1;
		else
			ok = 0;
		
		if (ok)
			R = mid;
		else
			L = mid;
	}
	
	cout << R << '\n';
	
	return 0;
}