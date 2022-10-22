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
const int MAXN = 207;


signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <pair <int, int> > a(m);
	for (int i = 0; i < m; ++i){
		cin >> a[i].first >> a[i].second;
	}

	set <int> good;
	for (int k = 1; k <= MAXN; ++k){
		
		bool good1 = true;
		for (int i = 0; i < m; ++i){
			if ((a[i].first - 1) / k + 1 != a[i].second){
				good1 = false;
			}
		}

		if (good1){
			good.insert((n - 1) / k + 1);
		}
	}

	if (good.size() != 1){
		cout << "-1\n";
	}
	else{
		cout << *good.begin() << '\n';
	}
	return 0;
}