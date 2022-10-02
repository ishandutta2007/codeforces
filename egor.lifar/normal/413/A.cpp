#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int n, m, mint, maxt, t[100000];


int main() {
    cin >> n >> m >> mint >> maxt;
    int k = -1000000000, l = 1000000000;
    for (int i = 0; i < m; i++) {
        cin >> t[i];
        l = min(l, t[i]);
        k = max(k, t[i]);
    }
    if (l < mint || k > maxt) {
        cout << "Incorrect" << endl;
        return 0;
    }
    if (l > mint && k < maxt && m == n - 1 && mint != maxt) {
        cout << "Incorrect" << endl;
        return 0;
    }
    cout << "Correct" << endl;
    return 0;
}