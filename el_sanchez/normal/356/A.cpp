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
const int MAXN = 333333;
    
int n, m, l, r, x;
int won[MAXN], nxt[MAXN];

int main() {

	cin >> n >> m;
	
	forn(i, n) {
		won[i] = -1;
		nxt[i] = i + 1;
	}
	nxt[n - 1] = -1;
	
	forn(ii, m) {
		cin >> l >> r >> x;
		l--, r--, x--;
		if (won[l] != -1)
			l = nxt[l];
		/*
		cerr << l << ' ' << r << endl;
		forn(i, n)
			cerr << nxt[i] << ' ';
		cerr << '\n';
		*/	
		int i;
		for (i = l; i <= r; ) {
			if (i != x && won[i] == -1)
				won[i] = x;	
			if (nxt[i] > r || nxt[i] == -1)
				break;
			i = nxt[i];
		}
		
		int cur = x;
		for (int j = l; j <= r && j != -1; ) {
			if (j == x)
				cur = nxt[i];
			int tj = nxt[j];
			nxt[j] = cur;
			j = tj;
		}		
	}
	
	forn(i, n)
		cout << won[i] + 1 << ' ';
		
	return 0;
}