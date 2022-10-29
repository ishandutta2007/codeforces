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

using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1.0);
const ld eps = 1e-14;
const int INF = 1E9;		                    
const int MAXN = 1000500;
const int MAGIC = 50000;
    
ll C, D, x, y, Ha, Hb, Wa, Wb, ans, cur;

int main() { 

	cin >> C >> Ha >> Hb >> Wa >> Wb;
	
	ans = 0;
	forn(tt, 2) {
		if (Wa > MAGIC) {
			ans = 0;
			for (ll i = 0; ; i++) {
				if (i * Wa > C)
					break;
				D = C - i * Wa;
				x = D / Wb;
				ans = max(ans, i * Ha + x * Hb);
			}
			cout << ans;
			
			return 0;
		}
		
		swap(Wa, Wb);
		swap(Ha, Hb);
	}

	ans = 0;
	
	forn(tt, 2) {
		x = C / Wa;
		D = C - x * Wa;
		y = D / Wb;
		D = D - y * Wb;
		cur = x * Ha + y * Hb;
		ans = max(ans, cur);
		
		forn(i, MAXN) {
			x--;
			if (x < 0)
				break;
				
			D = C - x * Wa;
			y = D / Wb;
			D = D - y * Wb;
			cur = x * Ha + y * Hb;
			ans = max(ans, cur);
		}
		
		swap(Wa, Wb);
		swap(Ha, Hb);
	}
	
	cout << ans;
	
	return 0;
}