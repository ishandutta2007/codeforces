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

const int N = 1e5 + 100;

int got[2][N], cntBad = 0, n;

int gotCnt(int x, int y) {
	int xx = x ^ 1;
	if (got[x][y] == 0) return 0;
	int cnt = 0;
	if (got[xx][y]) cnt++;
	if (y - 1 >= 0 && got[xx][y - 1]) cnt++;
	if (y + 1 < n && got[xx][y + 1]) cnt++;
	return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int q;
	cin >> n >> q;
	forn(i, q) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		int cntLast = gotCnt(x, y);
		got[x][y] ^= 1;
		int cntNow = gotCnt(x, y);
		cntBad -= cntLast;
		cntBad += cntNow;
		if (cntBad) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}