//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <cassert>
#include <ctime>
*/
               
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
#define db(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 511;
const int MOD = 1E9 + 7;
const int dx[2] = {0, 1};
const int dy[2] = {1, 0};

int n, m, h, id, cDiag, ni, nj;
bool center;
string w[MAXN];
int dp[2][MAXN][MAXN];
pii s, f, ns, nf, nsp, nfp;
ll ans;

pii getPos(int diag, int pos) {
	if (diag < m)
		return {pos, diag - pos};
	return {pos + diag - m + 1, m - 1 - pos};
}

pii getDiags(int x, int y) {
	int d = x + y;
	int pos;
	if (d < m)
		pos = x;
	else
		pos = x - (d - (m - 1));	
	return {d, pos};
}

bool correct(pii p) {
	return 0 <= p.X && p.X < n && 0 <= p.Y && p.Y < m;
}

int main() {
	
	scanf("%d %d", &n, &m);
	forn(i, n)
		cin >> w[i];
	
	center = !((n + m) & 1);
	cDiag = (n + m) / 2 - 1;
	
	//cerr << center << '\n';
	//cerr << cDiag << '\n';
	
	if (w[0][0] != w[n - 1][m - 1]) {
		cout << 0;
		return 0;
	}
	/*
	forn(d, n + m)
		forn(i, n) {
			cout << d << ' ' << i << " -> ";
			s = getPos(d, i);
			cout << s.X << ' ' << s.Y << '\n';	
		}
	*/
	id = 0;
	dp[0][0][0] = 1;
	h = max(n, m);
	for (int d = 0; d < cDiag; d++) {
	    forn(i, h)
	    	forn(j, h)
	    		dp[id ^ 1][i][j] = 0;
	    		
	    forn(i, h)
	    	forn(j, h)
	    		if (dp[id][i][j]) {
	    			s = getPos(d, i);
	    			f = getPos(n + m - 2 - d, j);
	    			
	    			forn(d1, 2)
	    				forn(d2, 2) {
	    					ns = {s.X + dx[d1], s.Y + dy[d1]};
	    				    nf = {f.X - dx[d2], f.Y - dy[d2]};
	    				    if (correct(ns) && correct(nf)) {
	    				    	if (w[ns.X][ns.Y] == w[nf.X][nf.Y]) {
	    				    		///???
	    				    		nsp = getDiags(ns.X, ns.Y);
	    				    		nfp = getDiags(nf.X, nf.Y);
	    				    		ni = nsp.Y;
	    				    		nj = nfp.Y;
	    				    		
	    				    		/*	
	    				    		cout << '(' << s.X << ',' << s.Y << "), (" << f.X << ',' << f.Y << ") -> ("
	    				    		            << ns.X << ',' << ns.Y << "), (" << nf.X << ',' << nf.Y << ")";   
	    				    		
	    				    		cout << "to " << d + 1 << ' ' << ni << ' ' << nj;
	    				    		cout << " add " << dp[id][i][j] << endl;
	    				    		*/
	    				    		///???
	    				    		dp[id ^ 1][ni][nj] += dp[id][i][j];
	    				    		if (dp[id ^ 1][ni][nj] >= MOD)
	    				    			dp[id ^ 1][ni][nj] -= MOD;
	    				    	}
	    				    }
	    				}
	    		}
	    				
		id ^= 1;	
	}

	ans = 0;
	if (center) {
		forn(i, h)
			ans += dp[id][i][i];
		ans %= MOD;
	} else {
		if (cDiag < m - 1) {
			forn(i, h) {
				ans += dp[id][i][i];
				ans += dp[id][i][i + 1];
			}
		} else {
		    forn(i, h) {
				ans += dp[id][i][i];
				ans += dp[id][i + 1][i];
			}
		}
		ans %= MOD;	
	}		
	cout << ans;
	
	return 0;
}