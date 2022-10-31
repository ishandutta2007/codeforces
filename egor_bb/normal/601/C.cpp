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
#include <queue>
 

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

int n, m, a[N], p[N], ss;
double delta[N][2], sum[N];

int main() {
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
//	freopen (problem".in", "r", stdin);
//	freopen (problem".in", "w", stdout);
	scanf("%d%d", &n, &m);
if (m == 1){
cout << 1 << '\n';
return 0;
}
	forn(i, n){
		scanf("%d", &a[i]);
		ss += a[i];
	}
	delta[0][0] = 1;
	int now = 0;
	forn(i, n){
		now = 1 - now;
		sum[0] = delta[0][1 - now];
		forab(j, 1, n * m){
			sum[j] = sum[j - 1] + delta[j][1 - now];
		}
		forab(j, 1, (i + 1) * m + 1){
			double s = sum[j - 1];
			if (j - m > 0) s -= sum[j - m - 1];
			if (j - a[i] >= 0) s  -= delta[j - a[i]][1 - now];
			delta[j][now] = s * 1. / (m - 1);
		}
		delta[0][0] = delta[0][1] = 0;
	}
	double p = 0;
	forn(i, ss){
		p += delta[i][now];
	}
	cout.precision(15);
	cout << fixed << p * (m - 1) + 1 << '\n';
	return 0;
}