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

using namespace std;

int n, m, k, a[1000];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int kk = 0, mm = 0, s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            if (mm < m) {
                mm++;
            } else {
                s++;
            }
        } else {
            if (kk < k) {
                kk++;
                continue;
            }
            if (mm < m) {
                mm++;
                continue;
            }
            s++;
        }
    }
    cout << s << endl;
	return 0;
}