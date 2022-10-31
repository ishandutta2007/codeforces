#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>
 
typedef long long ll;
typedef unsigned long long ull;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const ll N = 100005;

#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define pb push_back
#define sz(x) int(x.size())
#define problem "test"
 
using namespace std;

ll x, y;

int main(){
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	cin >> x >> y;
	cout.precision(12);
	if (y > x){
		cout << -1;
	} else {
		ll k = (x - y) / (2 * y);
		double l = y, r = 1e9;
		for (int i = 0; i < 1e7; i++){
			double m = (l + r) / 2;
			double xx = (2 * k + 1)* m, yy = m; 
			if (yy - y <= x - xx) l = m;
			else r = m;
		}
		cout << fixed << l << '\n';
	}
}