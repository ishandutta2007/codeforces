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
const int MAXN = 1e5 + 7;

bool bad(char c){
	return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	int i = 0;
	for (; i < n;){
		if (!bad(s[i])){
			cout << s[i];
			++i;
			continue;
		}

		if (i == n - 1){
			cout << s[i];
			++i;
			continue;
		}

		if (!bad(s[i + 1]) || !bad(s[i + 2])){
			cout << s[i];
			++i;
			continue;
		}

		bool good = true;
		int j = i + 1;
		for (; j < n && bad(s[j]); ++j){
			good &= (s[j] == s[j - 1]);
		}

		if (good){
			for (int k = i; k < j; ++k){
				cout << s[k];
			}

			i = j;
			continue;
		}

		if (s[i] != s[i + 1]){
			cout << s[i] << s[i + 1] << ' ';
			i = i + 2;
			continue;
		}

		cout << s[i];
		i = i + 1;
		for (; i < n && s[i] == s[i - 1]; ++i){
			cout << s[i];
		}
		cout << ' ';
	}

	return 0;
}