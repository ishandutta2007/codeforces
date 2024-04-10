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
const int MAXN = 1e5 + 7;


signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	n *= 2;
	vector <int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	int ans = BIG_MOD;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i){
		for (int j = i + 1; j < n; ++j){
			
			vector <int> b;
			for (int k = 0; k < n; ++k){
				if (k != i && k != j){
					b.push_back(a[k]);
				}
			}

			int res = 0;
			for (int k = 0; k < n - 2; k += 2){
				res += b[k + 1] - b[k];
			}

			ans = min(ans, res);
		}
	}

	cout << ans << '\n';
	return 0;
}