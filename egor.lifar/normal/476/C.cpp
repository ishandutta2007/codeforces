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


#define INF 1000000007


long long a, b;


int main() {
    cin >> a >> b;
    if (b == 1) {
        cout << 0 << endl;
        return 0;
    }
    long long ans = 0;
    for (long long i = 1; i < b; i++) {
        ans += (((((((a * (a + 1)) / 2) % INF) * i) % INF) * b) % INF + i * a) % INF;
        ans %= INF;
    }
    cout << ans << endl;
    return 0;
}