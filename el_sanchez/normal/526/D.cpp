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
    
ll P[2];
ll M[2];
int n, k;
string s, res;
ll H[2][MAXN], PW[2][MAXN];
int st[MAXN], fn[MAXN], ans[MAXN];

inline bool cmpHash(int p1, int p2, int len) {
	if (p1 + len - 1 >= n || p2 + len - 1 >= n)
		return 0;
	forab(j, 1, 2) {
		ll a1 = H[j][p1 + len - 1];
		if (p1 > 0)
			a1 -= H[j][p1 - 1] * PW[j][len];
		ll a2 = H[j][p2 + len - 1];
		if (p2 > 0)
			a2 -= H[j][p2 - 1] * PW[j][len];
		if (j == 1) {
			a1 %= M[1];
			a2 %= M[1];
			if (a1 < 0)
				a1 += M[1];
			if (a2 < 0)
				a2 += M[1];
		}
		if (a1 != a2)
			return 0;
	}
	
	return 1;
}
int main() { 

	cin >> n >> k;
	cin >> s;
	res = s;
	
	P[0] = 257;
	P[1] = 269;
	M[0] = 0;
	M[1] = 999999937;
	forn(j, 2) {
		H[j][0] = s[0];
		PW[j][0] = 1;
		forab(i, 1, n) {
			H[j][i] = (H[j][i - 1] * P[j] +	s[i]);
			PW[j][i] = PW[j][i - 1] * P[j];
			if (j == 1) {
				H[j][i] %= M[j];
				PW[j][i] %= M[j];
			}
		}
	}
	
	//cout << cmpHash(0, 4, 1) << '\n';
	//cout << cmpHash(0, 4, 2) << '\n';
	
	for (int len = 1; len <= n; len++) {
		int pos = len;
		bool f = 1;
		
		forn(i, k - 1) {
			if (pos + len - 1 >= n) {
				f = 0;
				break;
			}
			//cout << "ok\n";
			if (!cmpHash(0, pos, len)) {
				f = 0;
				break;
			}
			pos += len;
		}
		
		if (!f)
			continue;
			
		//cout << pos << '\n';
		
		int l = pos - 1, r = min(n, pos + len), mid;
		while (r - l > 1) {
			mid = (l + r) >> 1;
			//cout << mid << ' ' << mid - pos + 1 << '\n';
			if (cmpHash(0, pos, mid - pos + 1))
				l = mid;
			else
				r = mid;	
		}
		
		l = pos - 1;
		
		//cout << len << ' ' << l << ' ' << r - 1 << '\n';
		st[l]++;
		fn[r - 1]++;
	}
	
	int cur = 0;
	forn(i, n) {
		cur += st[i];
		if (cur > 0)
			res[i] = '1';
		else
			res[i] = '0';
		cur -= fn[i];	
	}
	
	cout << res;
		
	return 0;
}