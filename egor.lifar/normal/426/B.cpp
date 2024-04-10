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


int n, m;
int a[100][100];


bool gen(int x) {
    if (x == n) {
        return true;
    }
    if (x * 2 > n) {
        return false;
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != a[x + x - i - 1][j]) {
                return false;
            }
        }
    }
    return gen(2 * x);
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (gen(i + 1)) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}