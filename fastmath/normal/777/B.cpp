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

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);

	int a[10], b[10];
	for (int i = 0; i < 10; ++i){
		a[i] = b[i] = 0;
	}

	int n;
	cin >> n;
	char c;
	for (int i = 0; i < n; ++i){
		cin >> c;
		a[c - 48]++;
	}

	for (int i = 0; i < n; ++i){
		cin >> c;
		b[c - 48]++;
	}

	int a1[10], b1[10];
	for (int i = 0; i < 10; ++i){
		b1[i] = b[i];
		a1[i] = a[i];
	}
	for (int i = 0; i < 10; ++i){
		for (int j = i; j < 10; ++j){
			if (b1[j] >= a1[i]){
				b1[j] -= a1[i];
				a1[i] = 0;
				break;
			}
			else{
				a1[i] -= b1[j];
				b1[j] = 0;
			}
		}
	}
	int ans1 = 0;
	for (int i = 0; i < 10; ++i){
		ans1 += a1[i];
	}
	cout << ans1 << '\n';


	for (int i = 0; i < 10; ++i){
		b1[i] = b[i];
		a1[i] = a[i];
	}
	for (int i = 0; i < 10; ++i){
		for (int j = i + 1; j < 10; ++j){
			if (b1[j] >= a1[i]){
				b1[j] -= a1[i];
				a1[i] = 0;
				break;
			}
			else{
				a1[i] -= b1[j];
				b1[j] = 0;
			}
		}
	}
	int ans2 = 0;
	for (int i = 0; i < 10; ++i){
		ans2 += a[i] - a1[i];
	}

	cout << ans2 << '\n';
	return 0;
}