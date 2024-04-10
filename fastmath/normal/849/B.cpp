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
#define prev _prev
#define hash _hash;
#define x first
#define y second
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1007;

int gcd(int a, int b){
	while (b){
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

bool check1(int x1, int y1, int delt1, int delt2, int x2, int y2){
	int deltx = x2 - x1;
	if (deltx % delt1){
		return false;
	}

	if (y1 + (deltx / delt1) * delt2 != y2){
		return false;
	}

	return true;
}

bool check(vector <pair <int, int> > a, int d1, int d2){
	if (!a.size()){
		return false;
	}

	if (a.size() == 1){
		return true;
	}

	int delt1 = a[1].x - a[0].x;
	int delt2 = abs(a[1].y - a[0].y);

	int div = gcd(delt1, delt2);

	delt1 /= div;
	delt2 /= div;

	if (a[1].y < a[0].y){
		delt2 = -delt2;
	}

	if (!(delt1 == d1 && delt2 == d2)){
		return false;
	}

	for (int i = 2; i < a.size(); ++i){
		if (!check1(a[0].x, a[0].y, delt1, delt2, a[i].x, a[i].y)){
			return false;
		}
	}

	return true;
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <pair <int, int> > a(n);
	for (int i = 0; i < n; ++i){
		a[i].x = i + 1;
		cin >> a[i].y;
	}

	vector <pair <int, int> > p;
	int delt1, delt2, div;

	p = {};
	delt1 = a[1].x - a[0].x;
	delt2 = abs(a[1].y - a[0].y);
	div = gcd(delt1, delt2);
	delt1 /= div;
	delt2 /= div;

	if (a[1].y < a[0].y){
		delt2 = -delt2;
	}
	for (int i = 2; i < n; ++i){
		if (!check1(a[0].x, a[0].y, delt1, delt2, a[i].x, a[i].y)){
			p.push_back(a[i]);
		}
	}

	if (check(p, delt1, delt2)){
		cout << "Yes\n";
		return 0;
	}

	p = {};
	delt1 = a[2].x - a[0].x;
	delt2 = abs(a[2].y - a[0].y);
	div = gcd(delt1, delt2);
	delt1 /= div;
	delt2 /= div;

	if (a[2].y < a[0].y){
		delt2 = -delt2;
	}

	if (!check1(a[0].x, a[0].y, delt1, delt2, a[1].x, a[1].y)){
		p.push_back(a[1]);
	}

	for (int i = 3; i < n; ++i){
		if (!check1(a[0].x, a[0].y, delt1, delt2, a[i].x, a[i].y)){
			p.push_back(a[i]);
		}
	}

	if (check(p, delt1, delt2)){
		cout << "Yes\n";
		return 0;
	}

	p = {};
	delt1 = a[2].x - a[1].x;
	delt2 = abs(a[2].y - a[1].y);
	div = gcd(delt1, delt2);
	delt1 /= div;
	delt2 /= div;

	if (a[2].y < a[1].y){
		delt2 = -delt2;
	}

	if (!check1(a[1].x, a[1].y, delt1, delt2, a[0].x, a[0].y)){
		p.push_back(a[0]);
	}

	for (int i = 3; i < n; ++i){
		if (!check1(a[1].x, a[1].y, delt1, delt2, a[i].x, a[i].y)){
			p.push_back(a[i]);
		}
	}

	if (check(p, delt1, delt2)){
		cout << "Yes\n";
		return 0;
	}

	cout << "No\n";
	return 0;
}