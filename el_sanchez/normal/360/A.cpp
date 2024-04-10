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
const int MAXN = 5555;
    
int n, m;
int a[MAXN], notmore[MAXN], add[MAXN];
vector<pair<pii, pii> > q;

int main() {
	
	cin >> n >> m;
	q.resize(m);
	forn(i, m) {
		cin >> q[i].X.X >> q[i].Y.X >> q[i].Y.Y >> q[i].X.Y;
		q[i].Y.X--;
		q[i].Y.Y--;
	}	
	forn(i, n)
		notmore[i] = INF;
	forn(i, m) {
		if (q[i].X.X == 1) {
			for (int j = q[i].Y.X; j <= q[i].Y.Y; j++)
				add[j] += q[i].X.Y;	
		} else {
			for (int j = q[i].Y.X; j <= q[i].Y.Y; j++) {
				notmore[j] = min(notmore[j], q[i].X.Y - add[j]);	
				if (notmore[j] < -INF) {
					cout << "NO";
					return 0;
				}
			}
			
		}		}
	
	forn(i, n)
		a[i] = notmore[i];
		
	forn(i, m) {
		if (q[i].X.X == 1) {
			for (int j = q[i].Y.X; j <= q[i].Y.Y; j++)
				notmore[j] += q[i].X.Y;	 			
		} else {
			int mx = notmore[q[i].Y.X];	
			for (int j = q[i].Y.X; j <= q[i].Y.Y; j++)
				mx = max(mx, notmore[j]);
			if (mx != q[i].X.Y) {
				cout << "NO";
				return 0;
			}			
		}	
	}
	
	cout << "YES\n";
	forn(i, n)
		cout << a[i] << ' ';
			
	return 0;
}