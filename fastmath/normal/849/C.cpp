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

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

string ans = "";

void gen(int n, char c){
	if (!n){
		return;
	}

	int k = 0;
	while ((k + 1) * k / 2 <= n){
		++k;
	}

	for (int i = 0; i < k; ++i){
		ans += c;
	}

	gen(n - k * (k - 1) / 2, c + 1);
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if (!n){
		cout << "a";
		return 0;
	}

	gen(n, 'a');
	cout << ans;
	return 0;
}