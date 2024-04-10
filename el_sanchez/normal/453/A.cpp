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

ld pw(ld x, int n) {
	ld res = 1;
	while (n > 0) {
		if (n & 1)
			res *= x;
		n >>= 1;
		x *= x;	
	}	
	return res;
}

int n, k;
ld res, cur;

int main() {

	cin >> n >> k;
	res = 0;
	for (int x = 1; x <= n; x++) {
		cur = pw(1.0 * x / n, k) - pw(1.0 * (x - 1) / n, k);
		cur *= x;
		res += cur;	
	}
	
	cout.precision(30);
	cout << res;
		
	return 0;
}