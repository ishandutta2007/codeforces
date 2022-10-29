#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
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

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 111;
const int MAXC = 30;

string a, b, s;
int n, m, k, kk;
int dp[MAXN][MAXN][MAXN], par[MAXN][MAXN][MAXN], last[MAXN][MAXN][MAXN];
int go[MAXN][MAXC], p[MAXN], cans;

void get(int aa, int b, int c) {
	if (dp[aa][b][c] == 0)
		return;
	
	if (par[aa][b][c] == 2) {
		get(aa - 1, b - 1, last[aa][b][c]);
		cout << a[aa - 1];
	}
	if (par[aa][b][c] == 0)
		get(aa - 1, b, c);
	if (par[aa][b][c] == 1)
		get(aa, b - 1, c);
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> a >> b >> s;
	n = a.size();
	m = b.size();
	k = s.size();
	dp[0][0][0] = 0;
	
	p[0] = 0;
	for (int i = 1; i < k; i++) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j]) j++;
		p[i] = j;
	}
	
	for (int i = 0; i < k; i++) {
		for (char c = 'A'; c <= 'Z'; c++) {
			int j = i; //current prefix
			while (j > 0 && s[j] != c)
				j = p[j - 1];
			if (s[j] == c)
				j++;
			go[i][c - 'A'] = j;
		}
	}
	/*
	for (int i = 0; i < k; i++)
		for (char c = 'A'; c <= 'Z'; c++)
			if (go[i][c - 'A'] > 0)
				cerr << i << ' ' << c << ' ' << go[i][c - 'A'] << endl;
	*/
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int l = 0; l < k; l++) {
				cans = dp[i][j][l];
				
				if (i < n && j < m) {
					
					if (a[i] == b[j])
						if (dp[i + 1][j + 1][go[l][a[i] - 'A']] < cans + 1) {
							par[i + 1][j + 1][go[l][a[i] - 'A']] = 2;
							last[i + 1][j + 1][go[l][a[i] - 'A']] = l;
							dp[i + 1][j + 1][go[l][a[i] - 'A']] = cans + 1;
						}
						
				}
				
				if (i < n) {
					if (dp[i + 1][j][l] < cans) {
						par[i + 1][j][l] = 0;
						dp[i + 1][j][l] = cans;
					}
				}
				
				if (j < m) {
					if (dp[i][j + 1][l] < cans) {
						par[i][j + 1][l] = 1;
						dp[i][j + 1][l] = cans;
					}
				}
				
			}
	
	kk = 0;
	forn(i, k)
		if (dp[n][m][i] > dp[n][m][kk])
			kk = i;
	//cerr << dp[n][m][kk];
	if (dp[n][m][kk] == 0)
		cout << 0;
	else
		get(n, m, kk);
	
    return 0;
}