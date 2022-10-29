#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)
 
#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
const long double pi = 3.1415926535897932384626433832795;

const long double eps = 1e-9;
const int INF = int(1e9);
const ll LINF = ll(1e18);
const int MAXN = 3333;

int n, m, k, ans;
int sk;
vi a;

int main() {

    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

	scanf("%d", &m);
	scanf("%d", &sk);
	forn(i, m - 1) {
		scanf("%d", &k);
		sk = min(k, sk);
	}
	scanf("%d", &n);
	a.resize(n);
	forn(i, n)
		scanf("%d", &a[i]);
	sort(all(a));

	ans = 0;
	int pos = n - 1;
	while (pos >= 0) {
		forn(i, sk) {
			if (pos < 0)
				break;
			ans += a[pos];
			pos--;
		}
		pos -= 2;
	}
	cout << ans;

    return 0;
}