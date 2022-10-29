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
const int MAXN = 22;
const ll MOD = 1E9 + 7;
    
ll a, b, res, cur, cur2;

int main() {

	cin >> a >> b;
	res = 0;
	cur = 0;
	for (ll r = 1; r <= b - 1; r++) {
		cur = 1ll * r * a;
		cur %= MOD;
		res = (res + cur) % MOD;
		
		cur = 1ll * r * b;
		cur %= MOD;
		cur2 = a * (a + 1) / 2;
		cur2 %= MOD;
		
		cur = (cur * cur2) % MOD;
		
		res = (res + cur) % MOD;
			
	}
	
	cout << res;
		
	return 0;
}