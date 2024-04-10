#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <random>
#include <string>


//mt19937 rnd(rand());
using namespace std;

int get(char c){
	if (c == 'O'){
		return 1e5;
	}

	if (c == 'X'){
		return 0;
	}

	if (c == '.'){
		return 1;
	}
}


int main(){
	int n = 10;
	char a[10][10];
	for (int i = 0; i < 10; ++i){
		for (int j = 0; j < 10; ++j){
			cin >> a[i][j];
		}
	}

	string ans = "NO";
	for (int i = 0; i < 6; ++i){
		for (int j = 0; j < 10; ++j){
			if (get(a[i][j]) + get(a[i + 1][j]) + get(a[i + 2][j]) + get(a[i + 3][j]) + get(a[i + 4][j]) <= 1){
				ans = "YES";
			}
		}
	}

	for (int i = 0; i < 10; ++i){
		for (int j = 0; j < 6; ++j){
			if (get(a[i][j]) + get(a[i][j + 1]) + get(a[i][j + 2]) + get(a[i][j + 3]) + get(a[i][j + 4]) <= 1){
				ans = "YES";
			}
		}
	}

	for (int i = 0; i < 6; ++i){
		for (int j = 0; j < 6; ++j){
			if (get(a[i][j]) + get(a[i + 1][j + 1]) + get(a[i + 2][j + 2]) + get(a[i + 3][j + 3]) + get(a[i + 4][j + 4]) <= 1){
				ans = "YES";
			}
		}
	}

	for (int i = 0; i < 6; ++i){
		for (int j = 4; j < 10; ++j){
			if (get(a[i][j]) + get(a[i + 1][j - 1]) + get(a[i + 2][j - 2]) + get(a[i + 3][j - 3]) + get(a[i + 4][j - 4]) <= 1){
				ans = "YES";
			}
		}
	}

	cout << ans;
	return 0;
}