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
 

using namespace std;


int n;
int a[4010],b[4010];


int main(){
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        double c;
        cin >> c;
        int d = (int)(c * 1000 + 0.5);
        a[i] = d % 1000;
    }
    int sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        sum += a[i];
    }
    for (int i = 0; i < 2 * n; i++) {
        b[i] = (a[i] == 0 ? 0: 1000);
    }
    sort(b, b + 2 * n);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        l += b[i];
    }
    for (int i = 0; i < n; i++) {
        r += b[n + i];
    }
    int ans = 2000000000;
    for (int i = l; i <= r; i += 1000) {
        ans = min(ans, abs(i - sum));
    }
    printf("%.3f\n", ans / 1000.0);
    return 0;
}