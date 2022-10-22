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

int cnt[2][2][2][2];

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		int p[4];
		p[0] = 0;
		p[1] = 0;
		p[2] = 0;
		p[3] = 0;

		for (int j = 0; j < k; ++j){
			cin >> p[j];
		}

		cnt[p[0]][p[1]][p[2]][p[3]]++;
	}

	if (cnt[0][0][0][0]){
		cout << "YES\n";
		return 0;
	}

	for (int p1 = 0; p1 < 2; ++p1){
		for (int p2 = 0; p2 < 2; ++p2){
			for (int p3 = 0; p3 < 2; ++p3){
				for (int p4 = 0; p4 < 2; ++p4){
					for (int p5 = 0; p5 < 2; ++p5){
						for (int p6 = 0; p6 < 2; ++p6){
							for (int p7 = 0; p7 < 2; ++p7){
								for (int p8 = 0; p8 < 2; ++p8){

									if ((p1 & p5) || (p2 & p6) || (p3 & p7) || (p4 & p8)){
										continue;
									}

									if (cnt[p1][p2][p3][p4] && cnt[p5][p6][p7][p8]){
										cout << "YES\n";
										return 0;
									}

								}
							}
						}
					}
				}
			}
		}
	}

	cout << "NO\n";
	return 0;
}