#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <map>


using namespace std;


int n, t;
double sum[11][11];

void add(int i, int j, double x) {
    if (i == n) {
        return;
    }
    sum[i][j] += x;
    if (sum[i][j] > 1.0) {
        double isl = sum[i][j] - 1.0;
        sum[i][j] = 1.0;
        add(i + 1, j, isl / 2.0);
        add(i + 1, j + 1, isl / 2.0);
    }
}



int main() {
    cin >> n >> t;
    for (int i = 0; i < t; i++) {
        add(0, 0, 1.0);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (abs(sum[i][j] - 1.0) < 1e-9) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}