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

struct Event{
	int time;
	bool type;
};

Event init(int time, bool type){
	Event res = *new Event();
	res.time = time;
	res.type = type;

	return res;
}

void pass(){
	return;
}

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1000;

int n, m, k;
pair <int, int> a[MAXN];

bool comp(Event a, Event b){
	return (a.time < b.time) || (a.time == b.time && a.type && !b.type);
}

vector <pair <int, int> > by_string, by_column;

bool check1(int num, int mid){
	if (num < 1 || num > m){
		return false;
	}

	vector <bool> good(k, false);
	int ly, ry;
	for (int i = 0; i < k; ++i){
		ly = a[i].y - mid;
		ry = a[i].y + mid;
		good[i] = (num >= ly && num <= ry);
	}
	
	int last = 0;
	for (int i = 0; i < k; ++i){
		if (good[by_string[i].y]){
			int l = by_string[i].x - mid;
			int r = by_string[i].x + mid;

			if (last + 1 < l){
				return true;
			}

			last = r;
		}
	}

	return (last < n);
}


bool check2(int num, int mid){
	if (num < 1 || num > n){
		return false;
	}

	vector <bool> good(k, false);
	int lx, rx;
	for (int i = 0; i < k; ++i){
		lx = a[i].x - mid;
		rx = a[i].x + mid;
		good[i] = (num >= lx && num <= rx);
	}

	int last = 0;
	for (int i = 0; i < k; ++i){
		if (good[by_column[i].y]){
			int l = by_column[i].x - mid;
			int r = by_column[i].x + mid;

			if (last + 1 < l){
				return true;
			}

			last = r;
		}
	}

	return (last < m);
}

void upd1(int &left, int &right, int num, int mid){
	if (check1(num, mid)){
		left = min(left, num);
		right = max(right, num);
	}
}

void upd2(int &down, int &up, int num, int mid){
	if (check2(num, mid)){
		down = min(down, num);
		up = max(up, num);
	}
}

bool check(int mid){
	int left = MOD;
	int right = -MOD;
	int down = MOD;
	int up = -MOD;

	upd1(left, right, 1, mid);
	upd1(left, right, m, mid);
	
	upd2(down, up, 1, mid);
	upd2(down, up, n, mid);

	for (int i = 0; i < k; ++i){
		int lx = a[i].x - mid;
		int rx = a[i].x + mid;
		int ly = a[i].y - mid;
		int ry = a[i].y + mid;

		upd1(left, right, ly - 1, mid);
		upd1(left, right, ly, mid);
		upd1(left, right, ly + 1, mid);
		upd1(left, right, ry - 1, mid);
		upd1(left, right, ry, mid);
		upd1(left, right, ry + 1, mid);

		upd2(down, up, lx - 1, mid);
		upd2(down, up, lx, mid);
		upd2(down, up, lx + 1, mid);
		upd2(down, up, rx - 1, mid);
		upd2(down, up, rx, mid);
		upd2(down, up, rx + 1, mid);
	}

	return max(right - left + 1, up - down + 1) <= 1 + mid * 2;
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i){
		cin >> a[i].x >> a[i].y;
		by_string.push_back({ a[i].x, i });
		by_column.push_back({ a[i].y, i });
	}

	sort(by_string.begin(), by_string.end());
	sort(by_column.begin(), by_column.end());

	int l = -1;
	int r = 2e9;
	while (l < r - 1){
		int mid = (l + r) / 2;

		if (check(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}

	cout << r << '\n';
	return 0;
}