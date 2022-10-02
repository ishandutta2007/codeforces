#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <unordered_set>


using namespace std;


int r, p, s;
double d[101][101][101];


int main() {
	cin >> r >> p >> s;
	d[r][p][s] = 1;
	for (int i = r; i >= 0; i--) {
		for (int j = p; j >= 0; j--) {
			for (int g = s; g >= 0; g--) {
				if (j > 0 && i > 0) {
					double h = double(i * j) / double(i * j + j * g + g * i);
					d[i][j - 1][g] += d[i][j][g] * h;
				}
				if (g > 0 && j > 0) {
					double h = double(j * g) / double(i * j + j * g + g * i);
					d[i][j][g - 1] += d[i][j][g] * h;
				}
				if (i > 0 && g > 0) {
					double h = double(g * i) / double(i * j + j * g + g * i);
					d[i - 1][j][g] += d[i][j][g] * h;
				}
 			}
		}
	}
	double sum = 0.0, sum1 = 0.0, sum2 = 0.0;
	for (int i = 1; i <= r; i++) {
		sum += d[i][0][0];
	}
	for (int i = 1; i <= p; i++) {
		sum1 += d[0][i][0];
	}
	for (int i = 1; i <= s; i++) {
		sum2 += d[0][0][i];
	}
	printf("%.9lf %.9lf %.9lf\n", sum, sum1, sum2);
    return 0;
}