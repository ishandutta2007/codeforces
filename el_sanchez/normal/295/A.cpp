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
const int MAXN = 100500;  
                          
int n, m, k, oper[MAXN], cur;
ll a[MAXN];
int l[MAXN], r[MAXN], x[MAXN], x1, x2;
ll add[MAXN];

int main() {

	cin >> n >> m >> k;
	forn(i, n)
		cin >> a[i];
	forn(i, m) {
		scanf("%d%d%d", &l[i], &r[i], &x[i]);
		l[i]--, r[i]--;
	}
	forn(i, k) {
		scanf("%d%d", &x1, &x2);
		x1--, x2--;
		oper[x1]++;
		oper[x2 + 1]--;	
	}

	cur = 0;
	forn(i, m) {
		cur += oper[i];
		add[l[i]] += 1ll * cur * x[i];
		add[r[i] + 1] -= 1ll * cur * x[i];
	}
	
	ll w = 0;
	forn(i, n) {
		w += add[i];
		cout << w + a[i] << ' ';		
	}
	
	return 0;
}