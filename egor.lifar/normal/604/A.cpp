#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>
#include <cstring>
#include <cmath>


using namespace std;


int m[5];
int w[5];
int h[2];
int t[5] = {500, 1000, 1500, 2000, 2500};


int main() {
    for (int i = 0; i < 5; i++) {
        cin >> m[i];
    }
    double ans = 0.0;
    for (int i = 0; i < 5; i++) {
        cin >> w[i];
        ans += max(0.3 * t[i], (1.0 - double(m[i]) / 250.0) * t[i] - 50 * w[i]);
    }
    for (int i = 0; i < 2; i++) {
        cin >> h[i];
    }
    ans += 100.0 * h[0];
    ans -= 50.0 * h[1];
    cout << (int)round(ans) << endl;
    return 0;
}