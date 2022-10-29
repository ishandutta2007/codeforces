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
typedef __float128 ld; 
//typedef long double ld;

const ld pi = acos(-1.0);
const ld eps = 1e-14;
const int INF = 1E9;		
const int MAXN = 1111;
const ll MOD = 1E9 + 7;

int n;
string s;
int cnt[333];
ll mx, t;
ll ans;
                                	
int main() {
                  
	cin >> n;
	cin >> s;
	forn(i, n)
		cnt[s[i]]++;
		
	mx = -1;
	t = 0;
	forn(i, 333)
		if (cnt[i] > mx) {
			mx = cnt[i];
			t = 1;
		} else if (cnt[i] == mx)
			t++;

	ans = 1;
	forn(i, n)
		ans = (ans * t) % MOD;
	cout << ans;
			            
	return 0;
}