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
pair<int, int> a[1000000];
int r[1000000];
int d[1000000];
int dp[1000000];
int x1[200001], yy1[200001], x2[200001], y2[200001];


void change(int i, int x) {
    d[i] = x;
    while (i / 2 > 0) {
        i /= 2;
        d[i] = max(d[i * 2], d[i * 2 + 1]);
    }
}



int rmq(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return d[v];
    }
    int vm = (vl + vr) / 2;
    return max(rmq(v * 2, vl, vm, l, r), rmq(v * 2 + 1, vm + 1, vr, l, r));
}




int main() {
    cin >> n;
    int ss = 1;
    while (ss < n) {
        ss *= 2;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        r[a[i].second] = i; 
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      //  cout << r[i] << endl;
      //  cout <<  rmq(1, 1, ss, 1, r[i] + 1) << endl;
        dp[i] = rmq(1, 1, ss, 1, r[i] + 1) + 1;
        change(ss + r[i], dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}