#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

bool check(int a, int b, int c) {
    if (a + b <= c) return false;
    if (a + c <= b) return false;
    if (b + c <= a) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int a = 1; a <= n; ++a) {
        for (int b = a; b <= n; ++b) {
            int c = a ^ b;
            if (c == 0 || c < b || c > n) continue;
            if (check(a, b, c)) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}