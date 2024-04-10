#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>


using namespace std;


mt19937 rnd(rand());
int inf = 1e9;
long long big_inf = 1e18;


int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[50][50];
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}

	bool ans = true;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			
			bool ans1 = false;

			if (a[i][j] == 1){
				ans1 = true;
			}

			for (int ii = 0; ii < n; ++ii){
				for (int jj = 0; jj < n; ++jj){
					if (a[ii][j] + a[i][jj] == a[i][j]){
						ans1 = true;
					}
				}
			}

			if (!ans1){
				ans = false;
			}
		}
	}

	if (ans){
		cout << "Yes";
	}
	else{
		cout << "No";
	}


	return 0;
}