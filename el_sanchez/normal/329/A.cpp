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
const int MAXN = 111;  

int n;
string s[MAXN];      
bool rows, cols, f;

int main() {

	cin >> n;	
	forn(i, n)	
		cin >> s[i];

	rows = 1;	
	forn(i, n) {
		f = 0;
		forn(j, n)
			if (s[i][j] == '.')
				f = 1;
		if (!f)
			rows = 0;	
	}	
	
	cols = 1;	
	forn(i, n) {
		f = 0;
		forn(j, n)
			if (s[j][i] == '.')
				f = 1;
		if (!f)
			cols = 0;	
	}
	
	if (rows) {
		forn(i, n) {
			forn(j, n)
				if (s[i][j] == '.') {
					cout << i + 1 << ' ' << j + 1 << '\n';
					break;
				}
		}
	} else if (cols) {
		forn(i, n) {
			forn(j, n)
				if (s[j][i] == '.') {
					cout << j + 1 << ' ' << i + 1 << '\n';
					break;
				}
		}
	} else
		cout << -1;
		
	return 0;
}