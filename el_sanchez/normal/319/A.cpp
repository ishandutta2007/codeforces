#pragma comment(linker, "/STACK:67108864")

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

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 111;
const ll MOD = 1E9 + 7;

string s;
int n, a[MAXN];
ll st[MAXN], ans, cans;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> s;
	n = s.size();
	forn(i, n) {
		a[i] = (s[i] == '1');
	}

	st[0] = 1;
	forab(i, 1, MAXN)
		st[i] = (st[i - 1] * 2) % MOD;

	ans = 0;
	forn(i, n) {
		cans = 1;
		if (a[i]) {
			cans = (((st[i] * st[n - i - 1]) % MOD) * st[n - i - 1]) % MOD;
			ans = (ans + cans) % MOD;
		}
	}

	cout << ans;

	return 0;
}