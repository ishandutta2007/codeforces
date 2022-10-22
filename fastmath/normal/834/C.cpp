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

#define int long long
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);

	int n;
	scanf("%I64d", &n);
	int a, b;
	for (int i = 0; i < n; ++i){
		scanf("%I64d%I64d", &a, &b);
		int l = 0;
		int r = 1e6 + 228;
		int f = a * b;
		while (l < r - 1){
			ll m = (l + r) / 2;
			if (m * m * m <= a * b){
				l = m;
			}
			else{
				r = m;
			}
		}

		if (l * l * l == f && (!(a % l)) && (!(b % l))){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}

	return 0;
}