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

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;        
const int MAXN = 100500;  
const int MOD = 1E9 + 7;
                      
string s, t;
string ss;
int dp[MAXN][2][2][2];
int p[2 * MAXN], good[MAXN], canstart[MAXN];

int main() {
                          
	cin >> s;
	int n = s.size();
	cin >> t;

	ss = t + "#" + s;
	
	p[0] = 0;
	for (int i = 1; i < ss.size(); i++) {
		int j = p[i - 1];
		while (j > 0 && ss[i] != ss[j])
			j = p[j - 1];
		if (ss[i] == ss[j]) j++;
		p[i] = j;
	}	
	
	forn(i, n)
		good[i] = (p[t.size() + i + 1] >= t.size());
	forn(i, n)
		if (i + t.size() - 1 < n)
			canstart[i] = good[i + t.size() - 1];
		
	good[n] = 0;
	
	s += '#';
	/*
	forn(i, n)
		cout << canstart[i];
	cout << '\n';
	*/
	dp[0][0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		forn(l, 2)
		forn(j, 2)
			forn(k, 2) {
				if (dp[i][l][j][k] != 0) {
					//cerr << i << ' ' << j << ' ' << k << endl;
					//assert(!(j == 1 && k == 1));
					
					int cur = dp[i][l][j][k];
					
					//not opened:
					int kk = (t.size() == 1 && canstart[i]);
					
					//just open here
					if (j == 1 && !canstart[i]) {
						dp[i + 1][l][0][0] += cur;
						dp[i + 1][l][0][0] %= MOD;
					}
					
					//open & jump
					if (j == 1 && canstart[i]) {
						dp[i + t.size()][l][0][1] += cur;
						dp[i + t.size()][l][0][1] %= MOD;	
					}
					
					//go
					if (j == 1) {
						dp[i + 1][l][1][0] += cur;
						dp[i + 1][l][1][0] %= MOD;
					}
					
					//opened:
					//jump
					if (j == 0 && k == 0 && canstart[i]) {
						dp[i + t.size()][l][0][1] += cur;
						dp[i + t.size()][l][0][1] %= MOD;	
					}

					//go
					if (j == 0 && (k == 1 || !canstart[i])) {
						dp[i + 1][l][0][k] += cur;
						dp[i + 1][l][0][k] %= MOD;
					}
					
					//close
					if (j == 0 && k == 1) {
						dp[i + 1][1][1][0] += cur;
						dp[i + 1][1][1][0] %= MOD;	
					}

					//close old&just open new
					if (j == 0 && k == 1 && !canstart[i]) {
						dp[i + 1][1][0][0] += cur;
						dp[i + 1][1][0][0] %= MOD;	
					}

					//close old& open new & jump
					if (j == 0 && k == 1 && canstart[i]) {
						dp[i + t.size()][1][0][1] += cur;
						dp[i + t.size()][1][0][1] %= MOD;	
					}
											
				}
			}
	}
	
	int ans = 0;
	ans = dp[n][1][1][0];
	//cout << ans << '\n';	
	ans = (ans + dp[n][0][0][1]) % MOD;
	//cout << ans << '\n';	
	ans = (ans + dp[n][1][0][1]) % MOD;
	cout << ans << '\n';	
	
	return 0;
}