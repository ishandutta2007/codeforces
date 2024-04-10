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
	string s;
	cin >> s;

	int count1 = 0, count2 = 0;
	for (int i = 0; i < n - 1; ++i){
		if (s[i] == 'S' && s[i + 1] == 'F'){
			count1++;
		}
		else if (s[i] == 'F' && s[i + 1] == 'S'){
			count2++;
		}
	}

	if (count1 > count2){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}

	return 0;
}