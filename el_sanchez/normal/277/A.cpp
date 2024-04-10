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
const int MAXN = 111;  
          
int n, m, k, l, rt, ans;
int lang[MAXN][MAXN], used[MAXN];

void dfs(int v) {
	used[v] = 1;
	forn(i, n)
		if (!used[i]) {
			forn(j, m)
				if (lang[v][j] && lang[i][j]) {
					dfs(i);
					break;
				}
		}	
}

int main() {

	cin >> n >> m;	
	ans = 0;
	rt = -1;

	forn(i, n) {
		cin >> k;
		if (k != 0)
			rt = i;
		forn(j, k) {
			cin >> l;
			l--;
			lang[i][l] = 1;	
		}
	}

	ans = -1;	
	if (rt == -1) {
		rt = 0;
		ans++;
		lang[0][0] = 1;
	}

	forn(i, n)
		if (!used[i]) {
			ans++;
			dfs(i);
		}
		
	forn(i, n)
		if (!used[i])
			ans++;
	cout << ans; 	
	
	return 0;
}