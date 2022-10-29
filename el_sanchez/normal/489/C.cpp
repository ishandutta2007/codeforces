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
const ld eps = 1e-12;
const int INF = 1E9;		
const int MAXN = 5555;

int m, s;
string a[2];

int main() {
                
	cin >> m >> s;
	if (s == 0) {
		if (m == 1)
			cout << 0 << ' ' << 0;
		else
			cout << -1 << ' ' << -1;
		return 0;
	}
	
	if (s > 9 * m) {
		cout << -1 << ' ' << -1;
		return 0;
	}
	
	forn(i, 2) {
		a[i] = "";
		forn(j, m)
			a[i] += '0';
	}
	
	int ss = s;
	for (int i = 0; i < m && ss > 0; i++) {
		int r = min(ss, 9);
		a[0][i] = '0' + r;
		ss -= r;	
	}
	
	if (s <= 9 * (m - 1)) {
		a[1][0] = '1';
		s--;	
	} else {
	    a[1][0] = '0' + s - 9 * (m - 1);
	    s = 9 * (m - 1);
	}
	ss = s;       
	
	for (int i = m - 1; i >= 0 && ss > 0; i--) {
		assert(i != 0);
		
		int r = min(ss, 9);
		a[1][i] = '0' + r;
		ss -= r;	
	}
	
	cout << a[1] << ' ' << a[0];
	
	return 0;
}