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
typedef long double ld; 

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;        
const int MAXN = 100500;
                  
int n;
pair<string, string> s[MAXN];
int dp[MAXN][2];
int a[MAXN];

int main() {

	cin >> n;
	forn(i, n)
		cin >> s[i].X >> s[i].Y;
	forn(i, n) {
		cin >> a[i];
		a[i]--;
	}
	
	dp[0][0] = dp[0][1] = 1;
	for (int i = 1; i < n; i++) {
		if (dp[i - 1][0] && s[a[i - 1]].X < s[a[i]].X)
			dp[i][0] = 1;
		if (dp[i - 1][0] && s[a[i - 1]].X < s[a[i]].Y)
			dp[i][1] = 1;
		if (dp[i - 1][1] && s[a[i - 1]].Y < s[a[i]].X)
			dp[i][0] = 1;
		if (dp[i - 1][1] && s[a[i - 1]].Y < s[a[i]].Y)
			dp[i][1] = 1;       			
	}

	if (dp[n - 1][0] || dp[n - 1][1])
		cout << "YES";
	else
		cout << "NO";	
    
	return 0;
}