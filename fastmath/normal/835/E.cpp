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
const int BIT = 9;

int x, y;
bool sovp[BIT + 1];

int quer(vector <int> q){
	cout << "? ";
	cout << q.size() << ' ';
	for (int x : q){
		cout << x << ' ';
	}
	cout << endl;
	fflush(stdout);

	int ans;
	cin >> ans;
	fflush(stdout);
	return ans;
}

int find(vector <int> a){
	if (a.size() == 1){
		return a[0];
	}

	int n = a.size();
	int l = (n - 1) / 2 + 1;
	vector <int> first, second;
	for (int i = 0; i < l; ++i){
		first.push_back(a[i]);
	}

	for (int i = l; i < n; ++i){
		second.push_back(a[i]);
	}

	int xor_ = quer(first);
	if (xor_ == 0 || xor_ == x){
		return find(second);
	}
	else{
		return find(first);
	}
}

signed main(){
	int n;
	cin >> n >> x >> y;
	int p1 = -1;
	for (int bt = 0; bt <= BIT; ++bt){
		vector <int> q0;
		for (int i = 1; i <= n; ++i){
			if (((i >> bt) & 1) == 0){
				q0.push_back(i);
			}
		}

		int xor_ = quer(q0);
		sovp[bt] = 1;
		if (xor_ != 0 && xor_ != x){
			if (p1 == -1) p1 = find(q0);
			sovp[bt] = 0;
		}
	}

	int p2 = 0;
	for (int bt = 0; bt <= BIT; ++bt){
		if (((p1 >> bt) & 1) && sovp[bt]) p2 += (1 << bt);
		if (!((p1 >> bt) & 1) && !sovp[bt]) p2 += (1 << bt);
	}

	if (p1 > p2) swap(p1, p2);
	cout << "! " << p1 << ' ' << p2 << endl;
	fflush(stdout);
	return 0;;;
}