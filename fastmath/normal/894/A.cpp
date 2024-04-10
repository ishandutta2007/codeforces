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

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	for (int i = 0; i < n; ++i){
		for (int j = i + 1; j < n; ++j){
			for (int k = j + 1; k < n; ++k){
				ans += (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q');
			}
		}
	}

	cout << ans;
	return 0;
}