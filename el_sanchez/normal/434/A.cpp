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
                  
int n, m;
int a[MAXN];
vi seg[MAXN];
ll v, ans, cur, tmp, cur2;

int main() {

	cin >> m >> n;
	forn(i, n)
		cin >> a[i];

	ans = 0;
	forn(i, n - 1)	
		ans += abs(a[i] - a[i + 1]);
	
	forn(i, n) {
		if (i != 0 && a[i - 1] != a[i])
			seg[a[i]].pb(a[i - 1]);
		if (i != n - 1 && a[i + 1] != a[i])
			seg[a[i]].pb(a[i + 1]);		
	}
	
	cur = 0;
	forn(i, m + 1) {
		if (seg[i].empty())
			continue;
		sort(all(seg[i]));
		
		cur2 = 0;	           
		tmp = 0;
		forn(j, seg[i].size()) 
			tmp += abs(i - seg[i][j]); 
		
		for (int k = max(0, (int)seg[i].size() / 2 - 1); k < min((int)seg[i].size(), (int)seg[i].size() / 2 + 2); k++) {
			v = seg[i][k];
			
			cur2 = -tmp;
			forn(j, seg[i].size())
				cur2 += abs(v - seg[i][j]);
			if (cur2 < cur)
				cur = cur2;	
		}
	}
	
	ans += cur;
	cout << ans;
	
	return 0;
}