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

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;        
const int MAXN = 100500;
const int MAXBIT = 61;

ll bit(ll n, ll x) {
	return (n >> x) & 1;
}

int n;
ll l, r, x;

int main() {

	cin >> n;
	forn(nn, n) {
		cin >> l >> r;
		x = 0;
		for (int i = MAXBIT; i >= 0; i--) {
			if (bit(l, i) == bit(r, i))
				x += (bit(l, i) << i);
			else {
				bool f = 1;
				for (int j = 0; j < i; j++) {
					x += (1ll << j);
					if (!bit(r, j))
						f = 0;
				}
				if (f)
					x += (1ll << i);
				break;
			}			
		}
		cout << x << '\n';
				
	}
		return 0;
}