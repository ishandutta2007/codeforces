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
	string s;
	cin >> s;
	for (int i = 0; i < 100; ++i){
		string res = "";
		for (int j = 0; j < i; ++j){
			res += '0';
		}

		res += s;

		bool good = true;
		for (int j = 0; j < res.size(); ++j){
			good &= (res[j] == res[res.size() - 1 - j]);
		}

		if (good){
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}