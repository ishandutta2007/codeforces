#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>

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
typedef unsigned int uint;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 1111;

int n, k, ans, cid;
vi a, used;
ll cur;
map<ll, int> lib;
bool f;

int main() {

	//freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

	scanf("%d%d", &n, &k);
	if (k == 1) {
		cout << n;
		return 0;
	}
	a.resize(n);

	used.resize(n, 0);
	forn(i, n) 
		scanf("%d", &a[i]);
	sort(all(a));
	forn(i, n)
		lib[a[i]] = i;

	ans = 0;
	forn(i, n)
		if (!used[i]) {
			used[i] = 1;
			ans++;
			cur = a[i];
			f = 0;
			cur *= k;
			while (lib.find(cur) != lib.end()) {
				cid = lib[cur];
				used[cid] = 1;
				if (f)
					ans++;
				f = !f;
				cur *= k;
			}
		}
	cout << ans;

    return 0;
}