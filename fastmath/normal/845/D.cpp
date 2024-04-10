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

#define x first
#define y second
#define prev _prev
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

struct Event{
	int type, val;
};

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <Event> t(n);
	for (int i = 0; i < n; ++i){
		cin >> t[i].type;

		if (t[i].type == 1 || t[i].type == 3){
			cin >> t[i].val;
		}

	}

	vector <Event> stack1, stack2;
	int ans = 0;
	int speed = 0;
	for (int i = 0; i < n; ++i){
		if (t[i].type == 4 || t[i].type == 6){
			stack1.push_back(t[i]);
		}

		if (t[i].type == 3 || t[i].type == 5){
			stack2.push_back(t[i]);
		}

		if (t[i].type == 1){
			speed = t[i].val;
		}

		while (stack2.size() && stack2[stack2.size() - 1].type == 3 && stack2[stack2.size() - 1].val < speed){
			stack2.pop_back();
			++ans;
		}

		if (t[i].type == 2){
			while (stack1.size() && stack1[stack1.size() - 1].type == 6){
				stack1.pop_back();
				++ans;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}