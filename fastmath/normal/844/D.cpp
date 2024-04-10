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

#define x first
#define y second
#define prev _prev
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;
const int q1 = 501;
const int q2 = 997;

signed main(){
	cout.precision(20);
	int n, s, x;
	cin >> n >> s >> x;
	fflush(stdout);

	int num = s;
	int val, next;
	for (int i = 0; i < q1; ++i){
		if (num == -1){
			break;
		}

		cout << "? " << num << endl;
		fflush(stdout);
		cin >> val >> next;

		if (val >= x){
			cout << "! " << val << endl;
			fflush(stdout);
			return 0;
		}

		num = next;
	}

	int mx_ind = -1;
	int mx_val = -MOD;
	for (int i = 0; i < q2; ++i){
		num = (rnd() % n) + 1;
		cout << "? " << num << endl;
		fflush(stdout);
		cin >> val >> next;

		if (val < x && val > mx_val){
			mx_val = val;
			mx_ind = num;
		}
	}

	num = mx_ind;
	for (int i = 0; i < q1; ++i){
		if (num == -1){
			break;
		}

		cout << "? " << num << endl;
		fflush(stdout);
		cin >> val >> next;

		if (val >= x){
			cout << "! " << val << endl;
			fflush(stdout);
			return 0;
		}

		num = next;
	}

	cout << "! -1" << endl;
	fflush(stdout);
	return 0;
}