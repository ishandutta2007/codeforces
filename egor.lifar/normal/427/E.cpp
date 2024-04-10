#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>


using namespace std;


long long n, m, a[1000000];
long long k = 0;
long long ans = 0;


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }
    if (n % 2 == 0) {
        k = (a[n / 2 - 1] + a[n / 2]) / 2;
    } else {
        k = a[(n + 1) / 2 - 1];
    }
    int l = 0;//
    int r = n - 1;
    while (n >= 2 * m) {
        n -= 2 * m;
        ans += (k - a[l]) * 2 + (a[r] - k) * 2;
        l+= m;
        r-= m;
    }
    int t = 0;
    int t1 = 0;
    for (int i = l; i <= r; i++) {
        if (k <= a[i]) {
            t = i;
            break;
        }
    }
    for (int i = r; i >= l; i--) {
        if (k >= a[i]) {
            t1 = i;
            break;
        }
    }
    if (n == 0) {
        cout << ans << endl;
        return 0;
    }
    if (r - m + 1 > t) {
        ans += (a[r] - k) * 2;
        r -= m;
    }
    if (l + m - 1 < t1) {
        ans += (k - a[l]) * 2;
        l += m;
    }
    ans += (k - a[l]) * 2 + (a[r] - k) * 2;
    cout << ans << endl;
    return 0;
}