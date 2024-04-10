#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>


using namespace std;


int n, k;


int main() {
    cin >> n >> k;
    cout << (6 * (n - 1) + 5) * k << endl;
    for (int i = 0; i < n; i++) {
        cout << (6 * i + 1) * k << ' ' << (6 * i + 2) * k << ' ' << (6 * i + 3)* k << ' ' << (6 * i + 5)* k<< endl;
    }
    return 0;
}