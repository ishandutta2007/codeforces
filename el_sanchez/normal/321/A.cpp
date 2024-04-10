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
#define pii pair<long long, long long>
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
const char c[] = {'D', 'U', 'L', 'R'};
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int INF = 1E9;        
const int MAXN = 111;  

ll a, b, da, db, la, lb, k;
int n;
string s;
vector<pii> path;

int main() {
   
	cin >> a >> b;
	cin >> s;
	n = s.size();
	path.pb(mp(0, 0));
	forn(i, n) {
		forn(d, 4)
			if (c[d] == s[i]) {
				pii cur = path.back();
				path.pb(mp(cur.X + dx[d], cur.Y + dy[d]));
				break;
			}
	}
	
	da = path.back().X;
	db = path.back().Y;
	if (da != 0)
		k = abs(a) / abs(da);
	else if (db != 0)
		k = abs(b) / abs(db);
	else
		k = 0;
		
	la = da * k;
	lb = db * k;
	forn(i, 111)
		if (la != 0 || lb != 0) {
			la -= da;
			lb -= db;
		}	

	forn(i, 222) {
		pii cur = mp(la, lb);
		forn(j, path.size())
			if (mp(cur.X + path[j].X, cur.Y + path[j].Y) == mp(a, b)) {
				cout << "Yes";
				return 0;
			}
		
		la += da;
		lb += db;
	}	
	cout << "No";
	
	return 0;
}