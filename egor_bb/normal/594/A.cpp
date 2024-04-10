#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cassert>
#include <ctime>
#include <cmath>
 

typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
typedef unsigned int uint;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int MAXN = int(3e2) + 10;

#define pii pair <int, int>
#define pll pair <ll, ll>
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 
#define problem "test"

const int N = int(1e6);

using namespace std;


int n, x[N], l[N], r[N];

int main() {
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	cin >> n;
	forn(i, n)
		cin >> x[i];
	sort (x, x + n);
	int d = n - 2 - (n - 1) / 2;
	int ans = INF;
	for(int i = 0; i + d + 1 < n; i++){
		ans = min(ans, x[i + d + 1] - x[i]);
	}
	cout << ans << '\n';
}