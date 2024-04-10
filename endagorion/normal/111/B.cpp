#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector< int > max(200000, -1);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for (int j = 1; j * j <= x; ++j) {
            if (x % j == 0) {
                if (max[j] < i - y) {
                    ++ans;
                }
                max[j] = i;
                if (j * j != x && max[x / j] < i - y) {
                    ++ans;
                }
                max[x / j] = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}