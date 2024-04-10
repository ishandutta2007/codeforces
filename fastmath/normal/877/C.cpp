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
const int MAXN = 1e5 + 7;


signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << n / 2 + n / 2 + (n + 1) / 2 << '\n';
	for (int i = 2; i <= n; i += 2){
		cout << i << ' ';
	}

	for (int i = 1; i <= n; i += 2){
		cout << i << ' ';
	}

	for (int i = 2; i <= n; i += 2){
		cout << i << ' ';
	}
	return 0;
}