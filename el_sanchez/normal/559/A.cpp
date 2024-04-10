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
const ld eps = 1e-7;
const int INF = 1E9;
const int MAXN = 100500;
                     
ll k, d, tmp[3], h;
ll r[2], ans;
bool f[2];

int main() {

    cin >> k >> r[0] >> tmp[0] >> tmp[1] >> tmp[2] >> r[1];
    h = r[0] + tmp[0];
    
    ans = 0;
    k = 2 * k + 1;
	for (int i = 1; i <= h; i++) {
		ans += k;
		
		if (i == r[0]) {
			f[0] = 1;	
		} else if (f[0])
			k--;
		else
			k++;
		if (i == r[1]) {
			f[1] = 1;	
		} else if (f[1])
			k--;
		else
			k++;
	}
	
	cout << ans;	return 0;
}