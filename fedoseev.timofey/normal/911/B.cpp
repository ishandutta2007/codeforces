#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int l = 1;
    int r = a + b + 1;
    while (l + 1 != r) {
        int m = (l + r) >> 1;
        if (a / m + b / m >= n && a / m != 0 && b / m != 0) {
            l = m;
        }
        else {
            r = m;
        }
    }
    cout << l << endl;
}