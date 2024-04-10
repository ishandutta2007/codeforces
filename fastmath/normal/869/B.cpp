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
#define rand() (rand()<<15+rand())
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 10;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

int form(int n){
	if (n < 0) return n + MOD;
	if (n >= MOD) return n - MOD;
	return n;
}

int fact(int a, int b){
	return form((a * b) % MOD);
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;

	if (b - a > 20){
		cout << "0\n";
		return 0;
	}

	int ans = 1;
	for (int i = a + 1; i <= b; ++i){
		ans = fact(ans, form(i));
	}

	cout << ans << '\n';
	return 0;
}