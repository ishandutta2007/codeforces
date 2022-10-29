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
const int MAXN = 100500;
   
string s;
int n, m, l, r;
int o[3][MAXN], p[3], d[3];
    
int cnt(int k, int l, int r) {
	int res = o[k][r];
	if (l != 0)
		res -= o[k][l - 1];
	return res;
}

int main() {

	cin >> s;
	n = s.size();
	
	o[0][0] = o[1][0] = o[2][0] = 0;
	o[s[0] - 'x'][0] = 1;
	
	forab(i, 1, n) {
		forn(j, 3)
			o[j][i] = o[j][i - 1];
		o[s[i] - 'x'][i]++;		
	}
	
	cin >> m;
	forn(i, m) {
		cin >> l >> r;
		l--, r--;	
		forn(j, 3)
			p[j] = cnt(j, l, r);
		swap(p[0], p[2]);
		
		bool f = 0;
		forn(j, 3) {
			forn(k, 3)
				d[k] = p[(k + j) % 3];
			
			if ((r - l + 1) % 3 >= 1)
				d[0]--;
			if ((r - l + 1) % 3 >= 2)
				d[1]--;
				
			if (d[0] == d[1] && d[1] == d[2])
				f = 1;
		}
		
		cout << ((r - l + 1 < 3) || f ? "YES\n" : "NO\n");
		
	}			
	return 0;
}