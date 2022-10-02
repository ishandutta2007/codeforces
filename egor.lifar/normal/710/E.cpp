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
#include <unordered_map>
#include <cassert>


using namespace std;


int n;
long long d[10000000];
int x, y;


int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + x;
        for (int j = max((i + 1) / 2, 1); j <= min(i / 2 + 70, i - 1); j++) {
            int ni = j * 2;
            d[i] = min(d[i], d[j] + y + 1LL * (ni - i) * x);
        }
    }
    cout << d[n] << endl;
    return 0;
}