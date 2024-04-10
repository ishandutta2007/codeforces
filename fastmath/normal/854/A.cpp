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

int gcd(int a, int b){
	while (b){
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a = -MOD, b = 1;
	for (int i = 0; i <= n; ++i){
		int j = n - i;

		if (i >= j){
			continue;
		}

		if (gcd(i, j) == 1 && i * b > a * j){
			a = i;
			b = j;
		}
	}

	cout << a << ' ' << b << '\n';
	return 0;
}