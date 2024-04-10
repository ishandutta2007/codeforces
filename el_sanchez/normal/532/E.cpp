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
const int MAXN = 100500 * 30;
const ll M[2] = {999999937, 999999883};
const ll P[2] = {97, 89};

int n;
string s[2];
pair<int, int> hh[2][MAXN];
int sz[2];
ll PW[2][MAXN];
ll H[2][2][MAXN], cur;  

ll countHash(int strid, int num, int l, int r) {
	if (l >= n)
		return 0;
	if (r < 0)
		return 0;
		
	ll ans = H[strid][num][r];
	if (l > 0)
		ans -= H[strid][num][l - 1] * PW[num][r - l + 1];
	ans %= M[num];
	if (ans < 0)
		ans += M[num];
	return ans;
}

int main() { 
        	
    forn(i, 2) {
    	PW[i][0] = 1;
    	for (int j = 1; j < MAXN; j++) {
    		PW[i][j] = PW[i][j - 1] * P[i];
    		PW[i][j] %= M[i];
    	}
    }
	
	cin >> n;
	//n = 100000;
	
	forn(strid, 2) {
		cin >> s[strid];
		//s[strid] = "";
		//forn(i, n)
		//	s[strid] += 'a';
		//cout << s[strid] << '\n';
			
		forn(j, 2) {
			H[strid][j][0] = s[strid][0] - 'a';
			for (int k = 1; k < n; k++)
				H[strid][j][k] = (H[strid][j][k - 1] * P[j] + s[strid][k] - 'a') % M[j];	
		}
		
		sz[strid] = 0;
		
		for (int k = 0; k <= n; k++) {
			forn(symid, 27) {
				forn(j, 2) {
					cur = countHash(strid, j, 0, k - 1) * PW[j][n - k + 1];
					cur %= M[j];
					cur += 1ll * symid * PW[j][n - k];
					cur %= M[j];
					cur += countHash(strid, j, k, n - 1);
					cur %= M[j];
					if (cur < 0)
						cur += M[j];
					if (j == 0)
						hh[strid][sz[strid]].X = cur;
					else {
						hh[strid][sz[strid]].Y = cur;
						sz[strid]++;	
					}
				}
			}	
		}	
	}		
		
	//cout << sz[0] << ' ' << sz[1] << '\n';
	
	forn(strid, 2) {
		sort(hh[strid], hh[strid] + sz[strid]);
		int w = unique(hh[strid], hh[strid] + sz[strid]) - hh[strid];
		sz[strid] = w;	
	}
	/*
	cout << sz[0] << ' ' << sz[1] << '\n';
	
	forn(i, sz[0])
		cout << hh[0][i].X << ' ' << hh[0][i].Y << '\n';
	*/	
	int ans = 0;
	int ptr[2];
	ptr[0] = ptr[1] = 0;
	while (ptr[0] < sz[0] && ptr[1] < sz[1]) {
		if (hh[0][ptr[0]] < hh[1][ptr[1]])
			ptr[0]++;
		else if (hh[0][ptr[0]] > hh[1][ptr[1]])
			ptr[1]++;
		else {
			ans++;
			ptr[0]++;
			ptr[1]++;	
		}
	}
	
	cout << ans;
	
	return 0;
}