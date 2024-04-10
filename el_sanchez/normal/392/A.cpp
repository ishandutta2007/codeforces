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
const int MAXN = 1111;

ll n, ans;

int main() {

	cin >> n;
	if (n == 0) {
		cout << 1;
		return 0;
	}
	
	ans = 0;
	for (ll i = 0, j = n; i < n; ) {
		ans++;
		if (sqr(i + 1) + sqr(j) <= n * n)
			i++;
		else {
			j--;
			if (sqr(i + 1) + sqr(j) <= n * n)
				i++;
		}
	}
	
	ans *= 4;
	cout << ans;
	
	return 0;
}