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


int n, m;


int main() {
    cin >> n >> m;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 100000;
    for (int i = 0; i <= n; i++) {
        int s = i + (n - i) / 2;
        if (s % m == 0 && (n - i) % 2 == 0) {
            ans = min(ans, s);
        }
    }
    if (ans == 100000) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}