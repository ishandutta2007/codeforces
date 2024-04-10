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
#include <cstring>
#include <cmath>


using namespace std;


int n, k;
int a[100001];


int grundy(int a) {
    if (k % 2 == 0) {
        if (a == 0) {
            return 0;
        }
        if (a == 1) {
            return 1;
        }
        if (a == 2) {
            return 2;
        }
        return grundy(a % 2) ^ 1;
    } else {
        if (a == 0) {
            return 0;
        }
        if (a == 1) {
            return 1;
        }
        if (a == 2) {
            return 0;
        }
        if (a == 3) {
            return 1;
        }
        if (a == 4) {
            return 2;
        }
        if (a % 2 == 1) {
            return 0;
        }
        return (grundy(a / 2) == 1 ? 2: 1);
    }
}


int main() {
    cin >> n >> k;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res ^= grundy(a[i]);
    }
    if (res) {
        cout << "Kevin" << endl;
    } else {
        cout << "Nicky" << endl;
    }
    return 0;
}