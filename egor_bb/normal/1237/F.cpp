#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 3605;
const int MOD = 998244353;

int add(int a, int b) {
	a += b;
	return a >= MOD ? a - MOD : a;
}

int mult(int a, int b) {
	return int((a * 1ll * b) % MOD);
}

int toPow(int x, int d) {
	if (d == 0) return 1;
	int t = toPow(x, d / 2);
	t = mult(t, t);
	if (d & 1) return mult(t, x);
	return t;
}

int bad[N][2];
int lastDp[2][N], dp[2][N], cntGood[2];
int fact[N], inv[N];

void calcDp(int k, int maxCoord) {
	forn(i, maxCoord + 1) {
		dp[k][i] = 0;
		cntGood[k] += 1 - bad[i][k];
		//cerr << bad[i][k] << " ";
	}
	//cerr << '\n';
	//cerr << cntGood[k] << '\n';
	dp[k][0] = 1;
	forab(i, 1, maxCoord + 1) {
		if (bad[i][k]) continue;
		
		forn(j, N) {
			lastDp[1][j] = lastDp[0][j];
		}
		forn(j, N) {
			lastDp[0][j] = dp[k][j];
		}
		
		forn(j, maxCoord + 1) {
			dp[k][j] = lastDp[0][j];
			if (j > 0 && (i - 1) >= 1 && !bad[i - 1][k]) {
				dp[k][j] = add(dp[k][j], lastDp[1][j - 1]);
			}
		}
	}
}


int cnk(int n, int k) {
	return mult(fact[n], inv[n - k]);
}

int getNum(int cnt2, int cnt1, int k) {
	int ways2 = dp[k][cnt2];
	int pos1 = cntGood[k] - 2 * cnt2;
	if (pos1 < cnt1) return 0;
	return mult(ways2, cnk(pos1, cnt1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    inv[0] = 1;
    forab(i, 1, N) {
		fact[i] = mult(fact[i - 1], i);
		inv[i] = toPow(fact[i], MOD - 2);
	}
	//cerr << '\n';
    int h, w, n;
    cin >> h >> w >> n;
    bad[0][0] = bad[0][1] = 1;
    forab(i, h + 1, N) bad[i][0] = 1;
    forab(i, w + 1, N) bad[i][1] = 1;
    forn(i, n) {
    	int r1, c1, r2, c2;
    	cin >> r1 >> c1 >> r2 >> c2;
    	bad[r1][0] = 1;
    	bad[r2][0] = 1;
    	bad[c1][1] = 1;
    	bad[c2][1] = 1;
    	//cerr << c1 << " " << c2 << " ";
    }
    //cerr << '\n';
    calcDp(0, max(h, w));
    calcDp(1, max(h, w));
    
    //cerr << '\n';
    //cerr << cntGood[0] << " " << cntGood[1] << '\n';
    int ans = 0, ansLast = 0;
    forn(cnt2, max(h, w) + 1) {
    	forn(cnt1, max(h, w) + 1) {
    		ans = add(ans, mult(getNum(cnt2, cnt1, 0), getNum(cnt1, cnt2, 1)));
    	/*	if (ans != ansLast) {
    			//cerr << cnt2 << " " << cnt1 << '\n';
    		}*/
    		ansLast = ans;
    	}
    }
    cout << ans << '\n';
    return 0;
}