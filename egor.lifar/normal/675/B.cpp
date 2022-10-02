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

int n, a, b, c, d;

int main() {    
    cin >> n >> a >> b >> c >> d;
    int ans = 0;
    for (int x = 1; x <= n; x++) {
        int sum = x + a + b;
        int y = sum - a - c;
        int z = sum - c - d;
        int w = sum - b - d;
        if (y <= n && y >= 1 && z >= 1 && z <= n && w >= 1 && w <= n) {
            ans++;
        }
    }
    cout << 1LL * ans * n << endl;
    return 0;
}