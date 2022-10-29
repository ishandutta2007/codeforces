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

int lH, rH, mM;
int D;
string s, t, ans;

void getAns(int pos, int cD = 0) {
	if (pos == 5) {
	    if (D > cD) {
	    	int h = 10 * (t[0] - '0') + (t[1] - '0');
	    	int m = 10 * (t[3] - '0') + (t[4] - '0');
	    	
	    	if (lH <= h && h <= rH && m <= mM) {
				D = cD;
				ans = t;	
	    	}
	    }
		
		return;
	}
	
	if (pos == 2) {
		getAns(pos + 1, cD);
		return;
	}
	
	forn(i, 10) {
		t[pos] = '0' + i;
		getAns(pos + 1, cD + (s[pos] != t[pos]));
	}
}

int main() {

	cin >> rH;
	if (rH == 12) {
		lH = 1;
	} else {
		lH = 0;
		rH--;	
	}
	
	mM = 59;
	cin >> s;
	forn(i, 5)
		t += ' ';
	t[2] = ':';
	D = 100;
	getAns(0);
	cout << ans << '\n';
	
	return 0;
}