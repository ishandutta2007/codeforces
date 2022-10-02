#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


int n;
int b[300];
vector<int> d[300];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		d[i].resize(1000);
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			int sum = 0;
			int l = 0;
			while (sum + 9 <= b[i]) {
				sum += 9;
				d[0][l] = 9;
				l++;
			} 
			if (b[i] - sum > 0) {
				d[0][l] = b[i] - sum;
			}
		} else {
			int l = 0;
			bool t = true;
			while (t) {
				if (d[i - 1][l] != 9) {
					for (int j = d[i - 1][l] + 1; j <= 9; j++) {
						if (b[i] >= j) {
							//if (9 * l >= b[i] - j) {
								int sum = 0;
								for (int g = l + 1; g < (int)d[i - 1].size(); g++) {
									sum += d[i - 1][g];
								}
								if (b[i] - j < sum) {
									continue;
								}  
								if (b[i] - j - sum > 9 * l) {
									continue;
								}
								d[i][l] = j;
								for (int g = 0; g < l; g++) {
									if (sum + 9 <= b[i] - j) {
										d[i][g] = 9;
										sum += 9;
									} else {
										d[i][g] = b[i] - j - sum;
										break;
									}
 								}
								t = false;
								for (int g = l + 1; g < (int)d[i - 1].size(); g++) {
									d[i][g] = d[i - 1][g];
								}
								break;
							//}
						}
					} 
				}
				l++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		reverse(d[i].begin(), d[i].end());
		bool b = true;
		for (int j = 0; j < 1000; j++) {
			if (d[i][j] != 0 || j == 999) {
				b = false;
			}
			if (!b) {
				cout << d[i][j];
			}
		}
		cout << endl;
	}
  	return 0; 
}