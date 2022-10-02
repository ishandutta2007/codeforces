#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


#define M 1000000007


int t;
string s;
int d[101][2601];


int main() {
	cin >> t;
	d[0][0] = 1;
	for (int i = 0; i < 100; i++) {
		for (int k = 0; k <= 2600; k++) {
			for (int j = 1; j <= 26; j++) {
				if (k + j <= 2600) {
					d[i + 1][k + j] += d[i][k];
					d[i + 1][k + j] %= M;
				}
			}
		}	
	}
	for (int k = 0; k < t; k++) {
		cin >> s;
		int n = (int)s.size();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += s[i] - 'a' + 1;
		}
		printf("%d\n", d[n][sum] - 1);
	}
	return 0;
}