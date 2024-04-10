#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

void pass(){
	return;
}

#define int long long
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;


signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, k, mn, mx;
	cin >> n >> k;
	if (k == n || k == 0){
		mn = 0;
	}
	else{
		mn = 1;
	}

	if (k == 0){
		mx = 0;
	}
	else{
		int nado = (n - 1) / 3 + (bool)((n - 1) % 3);
		if (3 * k >= n){
			mx = n - k;
		}
		else{
			mx = k * 2;
		}
	}

	cout << mn << ' ' << mx;
	return 0;
}