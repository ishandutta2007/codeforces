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

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;        
const int MAXN = 1111;
const ll MOD = 1E9 + 9;
                  
ll bpow(ll a, ll p) {
	ll res = 1;
	while (p > 0) {
		if (p & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		p >>= 1;	
	}
	return res;
}

ll n, m, k, n1, ans, p1;

int main() {

	cin >> n >> m >> k;
	m = n - m;
	if (k * m <= n) {
		n1 = n - k * m;
		p1 = n1 / k;
		ans = ((MOD + bpow(2, p1 + 1) - 2) * k) % MOD;
		ans = (ans + n1 % k) % MOD;		
		ans = (ans + (k - 1) * m) % MOD;
	} else {
		ans = n - m;
	}	
	
	cout << ans;	
	return 0;
}