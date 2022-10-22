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

int get(string s, string t){
	int res = 0;
	for (int i = 0; i + t.size() - 1 < s.size(); ++i){
		res += (s.substr(i, t.size()) == t);
	}

	return res;
}

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	vector <string> a = { "Danil", "Olya", "Slava", "Ann", "Nikita" };
	string s;
	cin >> s;
	int sum = 0;
	for (string elem : a){
		sum += get(s, elem);
	}

	if (sum == 1){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}

	return 0;
}