#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <string>

#define INF 1000000009
#define INFl 1000000000000000007
#define ll long long
#define mp make_pair
#define pb push_back

using namespace std;

	int n,k = 4;

int main(){
//	ifstream in ("input.txt");
	cin >> n;
	string s[6];
	s[0] = "+------------------------+";
	s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
	s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
	s[4] = "|#.......................|";
	s[3] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
	s[5] = "+------------------------+";
	for (int i = 1; i <= min(4, n); i++){
		if (i == 3) s[4][1] = 'O';
		else if (i == 4) s[3][1] = 'O';
		else s[i][1] = 'O';
	}
	for (int i = 1; i <= 10; i++){
		for (int j = 1; j <= 3; j++){
			if (k < n){
				s[j][1 + 2 * i] = 'O';
				k++;
			}
		}
	}
	cout << s[0] << '\n' << s[1] << '\n' << s[2] << '\n' << s[4] << '\n' << s[3] << '\n' << s[5];
}