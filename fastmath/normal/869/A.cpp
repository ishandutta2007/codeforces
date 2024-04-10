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
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 2007;
const int MAXV = 1e7;

int a[MAXN], b[MAXN];
bool have[MAXV];

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		have[a[i]] = true;
	}

	for (int i = 0; i < n; ++i){
		cin >> b[i];
		have[b[i]] = true;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			ans += have[a[i] ^ b[j]];
		}
	}

	if (ans % 2 == 0){
		cout << "Karen\n";
	}
	else{
		cout << "Koyomi\n";
	}
	return 0;
}