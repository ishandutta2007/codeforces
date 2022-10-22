/*2007*/
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>
#include <time.h>
#include <queue>

using namespace std;

void pass(){
	return;
}

#define int long long
#define rand() (rand()<<15+rand())
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(time(NULL));
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 2e5 + 7;

int a[MAXN];

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	int ans = -1;
	set <int> s;
	for (int i = n - 1; i >= 0; --i){
		if (s.find(a[i]) == s.end()){
			ans = a[i];
		}

		s.insert(a[i]);
	}

	cout << ans;
	return 0;
}