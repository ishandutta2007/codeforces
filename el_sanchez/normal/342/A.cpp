#pragma comment(linker, "/STACK:16777216")

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
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;
const int MAXN = 11111;

int n, a, cnt[8];
int f[3];


int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	forn(i, n) {
		cin >> a;
		cnt[a]++;
	}
	if (cnt[5] > 0 || cnt[7] > 0 || cnt[1] != n / 3) {
		cout << -1;
		return 0;
	}
	if (cnt[3] > 0) {
		f[0] = cnt[3];
		if (cnt[6] < cnt[3]) {
			cout << -1;
			return 0;
		}
		cnt[6] -= f[0];
		cnt[3] -= f[0];
		cnt[1] -= f[0];
	}
	if (cnt[1] != cnt[2]) {
		cout << -1;
		return 0;
	}
	f[1] = cnt[4];
	f[2] = cnt[6];
	forn(i, f[0])
		cout << "1 3 6\n";
	forn(i, f[1])
		cout << "1 2 4\n";
	forn(i, f[2])
		cout << "1 2 6\n";

	return 0;
}