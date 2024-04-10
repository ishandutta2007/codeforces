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
const int MAXN = 37;

int a[MAXN];

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	int s1 = n / 2;
	vector <int> a1(1 << s1);
	for (int mask = 0; mask < (1 << s1); ++mask){
		for (int i = 0; i < s1; ++i){
			a1[mask] += a[i] * ((mask >> i) & 1);
		}
		a1[mask] %= m;
	}
	sort(a1.begin(), a1.end());

	int s2 = (n + 1) / 2;
	vector <int> a2(1 << s2);
	for (int mask = 0; mask < (1 << s2); ++mask){
		for (int i = 0; i < s2; ++i){
			a2[mask] += a[s1 + i] * ((mask >> i) & 1);
		}
		a2[mask] %= m;
	}
	sort(a2.begin(), a2.end());
	
	int ans = 0;
	int j = a2.size() - 1;
	for (int i = 0; i < a1.size(); ++i){
		if (a1[i] + a2[0] >= m) break;

		while (a1[i] + a2[j] >= m){
			--j;
		}

		ans = max(ans, a1[i] + a2[j]);
	}

	cout << ans;
	return 0;
}