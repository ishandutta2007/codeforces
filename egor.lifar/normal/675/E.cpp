#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <map>


using namespace std;


int n;
int a[100001];
pair<int, int> d[300001];


pair<int, int> rmq(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return make_pair(-1, -1);
    }
    if (l <= vl && vr <= r) {
        return d[v];
    }
    return max(rmq(v * 2, vl, (vl + vr) / 2, l, r), rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}


long long dp[100001];


int main() {
    cin >> n;
    int ss = 1;
    while (ss < n) {
        ss *= 2;
    }
    a[n - 1] = n - 1;
    d[ss + n - 1] = make_pair(a[n - 1], n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
        a[i]--;
        d[ss + i] = make_pair(a[i], i);
    }
    for (int i = ss - 1; i >= 1; i--) {
        d[i] = max(d[i * 2], d[i * 2 + 1]);
    }
    dp[n - 1] = 0;
    long long ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        int m = rmq(1, 1, ss, i + 2, a[i] + 1).second;
        dp[i] = dp[m] - (a[i] - m) + n - i - 1;
        ans += dp[i];
    }
    cout << ans << endl;
    return 0;
}