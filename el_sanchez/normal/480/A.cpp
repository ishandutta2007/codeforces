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

typedef int ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;
const ll P = 1999;
        
int n, k, ans;
vector<pii> a;

int main() {

	cin >> n;
	a.resize(n);
	forn(i, n) {
		cin >> a[i].X >> a[i].Y;
	}
	sort(all(a));  
	
	int cur = a[0].Y;
	for (int i = 1; i < n - 1; i++) {
		if (a[i].Y < cur)
			cur = a[i].X;
		else
			cur = max(cur, a[i].Y);
		if (cur > a[n - 1].Y) {
			cout << a[n - 1].X;
			return 0;
		}
	}
	cout << a[n - 1].Y;
		
	return 0;
}