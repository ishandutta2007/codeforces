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
const int MAXN = 1111;

int n, m, S;
string s[MAXN];
bool a[MAXN][MAXN];
int L[MAXN], R[MAXN], pMin[MAXN], pMax[MAXN], pL[MAXN], pR[MAXN];
pii start, pos;
int ans, r, d, maxH, maxW;

int main() {

	cin >> n >> m;
	forn(i, n)
		cin >> s[i];
	
	S = 0;
	forn(i, n) {
		forn(j, m)
			a[i][j] = (s[i][j] == 'X');

		L[i] = m;
		R[i] = -1;
		forn(j, m)
			if (a[i][j]) {
				S++;
				L[i] = min(L[i], j);
				R[i] = max(R[i], j);
			}
			
		for (int j = L[i]; j <= R[i]; j++)
			if (!a[i][j]) {
				cout << -1 << '\n';
				return 0;
			}				
	}
	
	start = {-1, -1};
	forn(i, n)
		if (L[i] != m) {
			start = {i, L[i]};
			break;	
		}
		
	assert(start.X != -1);
		
	pos = start;		
	pMin[pos.X] = pMax[pos.X] = pos.Y;
	r = d = 0;
	bool ok1 = 1;
	maxH = maxW = 1;
	
	int firstI = pos.X, lastI = pos.X;
	while (true) {
		if (a[pos.X + 1][pos.Y]) {
			pos.X++;
			pMin[pos.X] = pMax[pos.X] = pos.Y;
			d++;
			if (ok1)
				maxH++;
			maxW = 1;
		} else if (a[pos.X][pos.Y + 1]) {
			pos.Y++;
			pMax[pos.X] = pos.Y;
			r++;	
			ok1 = 0;
			maxW++;
		} else
			break;
			
		lastI = max(lastI, pos.X);
	}
	
	ans = INF;
	
	forn(i, n) {
		pL[i] = m;
		pR[i] = -1;
	}         		
	/*
	forn(i, n) 
		cout << L[i] << ' ' << R[i] << '\n';
	forn(i, n) 
		cout << pMin[i] << ' ' << pMax[i] << '\n';
	*/
	for (int H = 1; H <= maxH; H++)
		for (int W = 1; W <= maxW; W++) {
			int dd = d - H + 1;
			int rr = r - W + 1;

			//db(H);
			//db(W);
			if ((H + dd) * (W + rr) == S + dd * rr) { // O(n) solutions
				pMax[lastI] -= W - 1;
				
				int curMax = -INF;
				forn(j, H)
					curMax = max(curMax, pMax[firstI + j] + W - 1);
				for (int i = firstI; i <= lastI; i++) {
					pL[i] = pMin[i];
					pR[i] = curMax;	
					if (i + H <= lastI)
						curMax = max(curMax, pMax[i + H] + W - 1);
				}                  					
				
				bool ok = 1;
				forn(i, n) {
					//cout << L[i] << ' ' << R[i] << ' ' << pL[i] << ' ' << pR[i] << '\n';
					if (L[i] != pL[i] || R[i] != pR[i]) {
						ok = 0;
						break;
					}
				}
					
				if (ok)
					ans = min(ans, H * W);
					
				pMax[lastI] += W - 1;				
			}
		}
	
	cout << (ans == INF ? -1 : ans) << '\n';
	
	return 0;
}