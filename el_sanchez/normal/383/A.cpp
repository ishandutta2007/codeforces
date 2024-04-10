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
const int MAXN = 200500;

ll ans, cur, k;
int n;
int a[MAXN], sum[2][MAXN];
vi p[2];

int main() {

	cin >> n;       	
	forn(i, n)
		cin >> a[i];
	
	ans = 0;
	k = 0;
	forn(i, n) {
		if (a[i] == 1)
			k++;
		else
			ans += k;
	}
	
	cur = 0;
	k = 0;
	ford(i, n) {
		if (a[i] == 0)
			k++;
		else
			cur += k;	
	}
	
	ans = min(ans, cur);
	cout << ans;
		return 0;
}