/*2007*/
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
#include <queue>

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

bool used[26];
vector <string> myleft(26), myright(26);
bool all_have[26];

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <string> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		vector <bool> have(26, false);
		for (int j = 0; j < a[i].size(); ++j){
			all_have[a[i][j] - 'a'] = true;
			if (have[a[i][j] - 'a']){
				cout << "NO\n";
				return 0;
			}

			have[a[i][j] - 'a'] = true;
		}
	}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < a[i].size(); ++j){

			char c = a[i][j];

			for (int k = j - 1; k >= 0; --k){
				if (j - k > myleft[c - 'a'].size()){
					myleft[c - 'a'] += a[i][k];
				}
				else if (myleft[c - 'a'][j - k - 1] != a[i][k]){
					cout << "NO\n";
					return 0;
				}
			}

			for (int k = j + 1; k < a[i].size(); ++k){
				if (k - j > myright[c - 'a'].size()){
					myright[c - 'a'] += a[i][k];
				}
				else if (myright[c - 'a'][k - j - 1] != a[i][k]){
					cout << "NO\n";
					return 0;
				}
			}

		}
	}

	int have = 0;
	for (int i = 0; i < 26; ++i){
		have += all_have[i];
	}

	string ans;
	while (true){
		if (ans.size() == have) break;
		bool relaxed = false;

		for (int i = 0; i < 26; ++i){
			if (myleft[i].size() == 0 && !used[i] && all_have[i]){

				char c = i;
				relaxed = true;
				while (true){

					if (used[c]){
						cout << "NO";
						return 0;
					}

					used[c] = true;
					ans += (char)(c + 'a');
					if (myright[c].size() == 0) break;
					c = myright[c][0] - 'a';
				}

				continue;
			}
		}

		if (!relaxed){
			cout << "NO";
			return 0;
		}
	}

	cout << ans;
	return 0;
}