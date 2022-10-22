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
const int MAXN = 2e5 + 7;

bool tel[MAXN];

struct Event{
	int time, num;
	bool open;
};

Event init(int time, int num, bool open){
	Event res = *new Event();
	res.time = time;
	res.num = num;
	res.open = open;

	return res;
}

bool comp(Event x, Event y){
	return (x.time< y.time) || (x.time == y.time && x.open && !y.open);
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <Event> t;
	int l, r;
	for (int i = 0; i < n; ++i){
		cin >> l >> r;
		t.push_back(init(l, i, true));
		t.push_back(init(r, i, false));
	}

	sort(t.begin(), t.end(), comp);

	bool free1 = true, free2 = true;
	for (int i = 0; i < 2 * n; ++i){
		if (t[i].open){
			if (!free1 && !free2){
				cout << "NO\n";
				return 0;
			}

			if (free1){
				free1 = false;
				tel[t[i].num] = true;
			}
			else{
				free2 = false;
				tel[t[i].num] = false;
			}
		}
		else{
			if (tel[t[i].num]){
				free1 = true;
			}
			else{
				free2 = true;
			}
		}
	}

	cout << "YES\n";
	return 0;
}