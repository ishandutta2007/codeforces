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
#define prev _prev
#define hash _hash;
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e6 + 7;

int a[MAXN];
int last[MAXN];
int myright[MAXN];

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	if (n == 1){
		cout << "1\n";
		return 0;
	}

	for (int i = 0; i < MAXN; ++i){
		last[i] = n;
	}

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	for (int i = n - 1; i >= 0; --i){
		myright[i] = last[a[i]] - i - 1;
		last[a[i]] = i;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		ans += (i + 1) * (myright[i] + 1) - 1;
	}

	double sr = (double)ans / (n * (n - 1) / 2);
	cout << (double)(sr * n * (n - 1) + n) / (n * n);
	return 0;
}