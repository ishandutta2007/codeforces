#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <map>
#include <string.h>
#include <vector>


using namespace std;


int n;
long long a[300000];
long long ans = 0;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            ans += n * a[i];
            break;
        }
        ans += (i + 2) * a[i];
    }
    cout << ans << endl;
    return 0;
}