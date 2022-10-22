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
const int MAXN = 5007;

int pref[MAXN];

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); ++i){
		pref[i + 1] = pref[i] + (s[i] == 'a');
	}

	int ans = 0;
	for (int len1 = 0; len1 <= s.size(); ++len1){
		for (int len2 = 0; len1 + len2 <= s.size(); ++len2){
			int a = pref[len1];
			int b = len2 - (pref[len1 + len2] - pref[len1]);
			int c = pref[s.size()] - pref[len1 + len2];
			ans = max(ans, a + b + c);
		}
	}

	cout << ans << '\n';
	return 0;
}