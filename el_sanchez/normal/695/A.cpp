#include "bits/stdc++.h"

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define ford(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

template<typename T> inline T sqr(T x)
{
    return x*x; 
}                    

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

//const ld pi = acos((ld)-1.0);
const ld eps = 1e-6;
const int INF = (int)1E9;
const int MAXN = 21;
const int MAXMASK = (1 << MAXN);

bool eq(ld a, ld b) {
	return fabs(a - b) < eps;
}

int n, N, k, mmask;
ld cnk[MAXN][MAXN];
ld p[MAXN];
ld pSum[MAXMASK], coeff[MAXN];
int trueId[MAXN], mass[MAXMASK];
ld ans[MAXN];

void printAns() {
	cout.precision(20);
	forn(i, N)
		cout << ans[i] << " \n"[i == N - 1];
}

int main() {

	cin >> n >> k;
	N = n;
	forn(i, n)
		cin >> p[i];

	forn(i, n)
		if (eq(p[i], 1.0)) {
			ans[i] = 1.0;
			printAns();
			return 0;
		}	

	forn(i, n)
		trueId[i] = i;
			
	forn(i, n) {
		if (eq(p[i], 0.0)) {
			for (int j = i; j < n - 1; j++) {
				p[j] = p[j + 1];
				trueId[j] = trueId[j + 1];
			}
			n--;
			i--;
		}
	}

   	if (n <= k) {
   		forn(i, n)
   			ans[trueId[i]] = 1.0;
   		printAns();
   		return 0;
   	}

   	cnk[0][0] = 1;
   	forab(i, 1, MAXN) {
   		cnk[i][0] = 1;
   		forab(j, 1, MAXN)
   			cnk[i][j] = cnk[i - 1][j - 1] + cnk[i - 1][j];
   	}

   	for (int j = k - 1; j >= 1; j--) {
   		coeff[j] = 0;
   		for (int i = 1; i <= k - 1 - j; i++)
   			coeff[j] -= cnk[n - j - 1][i] * coeff[i + j]; 
   		coeff[j]++;
   	}

   	for (int j = k - 1; j >= 1; j--) {
   		//cout << coeff[j] << endl;
   	}

   	mmask = 1 << n;
   	forn(mask, mmask) {
   		pSum[mask] = 0;
   		mass[mask] = 0;
   		forn(i, n)
   			if ((mask >> i) & 1) {
   				pSum[mask] += p[i];
   				mass[mask]++;
   			}	
   	}

   	int j;
   	forn(i, n) {
   		//cout << p[i] << endl;
   		ld curAns = 0.0;

   		forn(mask, mmask) {
   			j = mass[mask];
   			if (1 <= j && j <= k - 1 && ((mask >> i) & 1) == 0) {
   				assert(!eq(pSum[mask], 1.0));
   				curAns += coeff[j] * (pSum[mask] / (1.0 - pSum[mask]));
   			}	
   			//cout << pSum[mask] << ' ' << curAns << endl;
   		}

   		curAns++;
   		curAns *= p[i];

   		ans[trueId[i]] = curAns;
   	}

   	printAns();

	return 0;
}