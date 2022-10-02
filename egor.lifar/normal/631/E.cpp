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


using namespace std;


int n;
int a[200001];
long long sum[200001];
long long ans;

long long f(int i, int j) {
    return ans + 1LL * a[i] * (j - i) - sum[j] + sum[i];
}


long long f1(int i, int j) {
    return ans - 1LL * a[i] * (i + 1) + 1LL * a[i] * (j + 1) + (i != j ? sum[i - 1] - (j == 0 ? 0: sum[j - 1]): 0);
}


int main() {
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        ans += (1LL * a[i] * (i + 1));
        sum[i] = a[i];
        if (i != 0) {
            sum[i] += sum[i - 1];
        }
    }
    long long ans1 = -100000000000000000LL;
    for (int i = 0; i < n; i++) {
        int l = i;
        int r = n - 1;
        while (l < r) {
            int m = (l + r) / 2; 
            if (f(i, m) <= f(i, m + 1)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        for (int j = max(i, l - 5); j <= min(n - 1, l + 5); j++) {
            ans1 = max(ans1, f(i, j));
        }
    }
    for (int i = 0; i < n; i++) {
        int l = 1;
        int r = i - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (f1(i, m) <= f1(i, m + 1)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        for (int j = max(0, l - 5); j <= min(l + 5, i); j++) {
            ans1 = max(ans1, f1(i, j));
        }
    }
    cout << ans1 << endl;
    return 0;
}