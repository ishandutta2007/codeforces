#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>
#include <cstring>
#include <cmath>


using namespace std;


int n, k;
int a[200001];


int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int f = 2 * k - n;
    int ans = 0;
    for (int i = n - 1; i >= max(0, n - f); i--) {
        ans = max(ans, a[i]);
    }
    for (int i = n - f - 1; i >= (n - f) / 2; i--) {
        if (i == n - f - 1 - i) {
            ans = max(ans, a[i]);
        } else {
            ans = max(ans, a[i] + a[n - f - 1 - i]);
        }
    }
    cout << ans << endl;
    return 0;
}