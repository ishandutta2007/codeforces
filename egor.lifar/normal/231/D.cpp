#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>    


using namespace std;


int x, y, z, x1, y11, z1;
int a[6];


int main() {
    cin >> x >> y >> z >> x1 >> y11 >> z1;
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    int ans = 0;
    if (y < 0) {
        ans += a[0];
    }
    if (y > y11) {
        ans += a[1];
    }
    if (z < 0) {
        ans += a[2];
    }
    if (z > z1) {
        ans += a[3];
    }
    if (x < 0) {
        ans += a[4];
    }
    if (x > x1) {
        ans += a[5];
    }
    cout << ans << endl;
    return 0;
}