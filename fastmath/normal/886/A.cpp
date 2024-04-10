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

int a[6];

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 6; ++i){
		cin >> a[i];
	}

	for (int i = 0; i < 6; ++i){
		for (int j = i + 1; j < 6; ++j){
			for (int k = j + 1; k < 6; ++k){

				int sum1 = a[i] + a[j] + a[k];

				int sum2 = 0;
				for (int p = 0; p < 6; ++p){
					if (p != i && p != j && p != k){
						sum2 += a[p];
					}
				}

				if (sum1 == sum2){
					cout << "YES";
					return 0;
				}

			}
		}
	}

	cout << "NO";
	return 0;
}