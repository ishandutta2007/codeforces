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

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 11111;
    
ll h1, a1, d1;
ll h2, a2, d2;
ll h, a, d;
ll t1, t2, ans, cur;
ll tt1[MAXN], tt2[MAXN];

int main() {

	cin >> h1 >> a1 >> d1;
	cin >> h2 >> a2 >> d2;
	cin >> h >> a >> d;
	ans = 0;
	if (a1 <= d2) {
		ans += a * (d2 + 1 - a1);
		a1 = d2 + 1;	
	}	
	if (a2 <= d1) {
		cout << ans;
		return 0;
	}
	
	forn(i, MAXN)
		tt1[i] = tt2[i] = INF;

	for (int i = 0; i <= 11111; i++)
		for (int j = 0; j <= 222; j++) {
			ll cur = h * i + d * j;
			if (a2 - d1 - j <= 0 || (h1 + i + a2 - d1 - j - 1) / (a2 - d1 - j) > 200)
				tt1[201] = min(tt1[201], cur);
			else {
				int v = (h1 + i + a2 - d1 - j - 1) / (a2 - d1 - j);
				tt1[v] = min(tt1[v], cur);
			}
		}

	for (int i = 0; i <= 222; i++) {
		ll cur = a * i;
		int v = (h2 + a1 + i - d2 - 1) / (a1 + i - d2);
		tt2[v] = min(tt2[v], cur);
	}
	
	cur = INF;
	for (int i = 0; i <= 201; i++)
		for (int j = 0; j < i; j++)
	    	cur = min(cur, tt1[i] + tt2[j]);
	 
	ans += cur;
	cout << ans;

		
	return 0;
}