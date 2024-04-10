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

int n[2], ptr[2];
vi a[2];
int ans;

int main() {
                  
	forn(i, 2) {
		cin >> n[i];
		a[i].resize(n[i]);
		forn(j, n[i])
			cin >> a[i][j];
		sort(all(a[i]));
	}
	
	ptr[0] = ptr[1] = 0;
	while (ptr[0] < n[0] && ptr[1] < n[1]) {
		if (abs(a[0][ptr[0]] - a[1][ptr[1]]) <= 1) {
			ans++;
			ptr[0]++;
			ptr[1]++;
		} else if (a[0][ptr[0]] < a[1][ptr[1]])
			ptr[0]++;
		else
			ptr[1]++;
	}
	
	cout << ans;
	
	return 0;
}