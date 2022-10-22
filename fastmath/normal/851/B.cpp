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
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

struct Vect{
	int x, y;
};

Vect init(int x1, int y1, int x2, int y2){
	Vect res = *new Vect();
	res.x = x2 - x1;
	res.y = y2 - y1;
	return res;
}

int cp(Vect a, Vect b){
	return a.x * b.y - a.y * b.x;
}

int get_r(int x1, int y1, int x2, int y2){
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int r1 = get_r(x1, y1, x2, y2);
	int r2 = get_r(x2, y2, x3, y3);
	if (cp(init(x1, y1, x2, y2), init(x1, y1, x3, y3)) && r1 == r2){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
	}

	return 0;
}