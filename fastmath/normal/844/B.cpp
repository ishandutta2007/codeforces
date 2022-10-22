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
#define x first
#define y second
#define prev _prev
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 107;

int a[MAXN][MAXN];
ll p[MAXN];
signed main(){
	p[0] = 1;
	for (int i = 1; i < MAXN; ++i){
		p[i] = p[i - 1] * 2;
	}

	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i){
		int b = 0;
		int w = 0;

		for (int j = 0; j < m; ++j){
			if (!a[i][j]){
				++w;
			}
			else{
				++b;
			}
		}

		ans += p[b] + p[w] - 2;
	}

	for (int j = 0; j < m; ++j){
		int b = 0;
		int w = 0;

		for (int i = 0; i < n; ++i){
			if (!a[i][j]){
				++w;
			}
			else{
				++b;
			}
		}

		ans += p[b] + p[w] - 2;
	}

	cout << ans - n * m;
	return 0;
}