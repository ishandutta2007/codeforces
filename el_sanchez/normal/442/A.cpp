#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 111;
                  
int n, ans, cur;
string t = "RGBYW";
string s[MAXN];
int have[5][5], used[2][5];

int main() {

	memset(have, 0, sizeof(have));
	cin >> n;
	forn(i, n) {
		cin >> s[i];
		int k1 = 0;
		forn(j, t.size())
			if (t[j] == s[i][0])
				k1 = j;
		int k2 = s[i][1] - '1';
		have[k1][k2] = 1;	
	}
	
	ans = 10;
	for (int mask = 0; mask < (1 << 10); mask++) {
		cur = 0;
		memset(used, 0, sizeof(used));
		forn(i, 5) {
			int k = (mask >> i) & 1;
			cur += k;
			used[0][i] = k;
		}
		forn(i, 5) {
			int k = (mask >> (i + 5)) & 1;
			cur += k;
			used[1][i] = k;
		}
		
		bool good = 1;
		forn(i, 5)
			forn(j, 5)
				if (have[i][j]) {
					forn(k, 5)
						if (i != k && have[k][j]) {
							if (!(used[0][i] || used[0][k]))
								good = 0;
						}
					forn(k, 5)
						if (j != k && have[i][k]) {
							if (!(used[1][j] || used[1][k]))
								good = 0;
						}
					forn(i1, 5)
						forn(j1, 5)
							if (i1 != i && j1 != j && have[i1][j1])
								if (!(used[0][i] || used[0][i1] || used[1][j] || used[1][j1]))
									good = 0;
				}
				
		if (good)
			ans = min(ans, cur);
	}
	
	cout << ans;
		return 0;
}