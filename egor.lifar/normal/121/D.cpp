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
#include <unordered_map>


using namespace std;


int n;
long long k;
long long l[100000], r[100000];
long long dl[100000], dr[100000];
vector<long long> v;
long long maxp = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;


void get(int i, int l, long long a) {
    if (i == l) {
        v.push_back(a);
        return;
    }
    get(i + 1, l, a * 10LL + 4LL);
    get(i + 1, l, a * 10LL + 7LL);
}


bool ans(int ll, int rr) {
    if (v[rr] - v[ll] + 1 > maxp) {
        return false;
    }
    long long sum = 0;
    if (upper_bound(l, l + n, v[ll]) != l + n) {
        int f = distance(l, upper_bound(l, l + n, v[ll]));
        if (3000LL * 1000 * 1000 * 1000 * 1000 * 1000 / v[ll] < n - f) {
            return 0;
        }
        sum += dl[n - 1] - (f > 0 ? dl[f - 1]: 0LL) - v[ll] * 1LL * (n - f);
    }
    if (lower_bound(r, r + n, v[rr]) != r) {
        int f = distance(r, lower_bound(r, r + n, v[rr])) - 1;
        if (3000LL * 1000 * 1000 * 1000 * 1000 * 1000 / v[rr] < 1LL * (f + 1)) {
            return 0;
        }
        sum += v[rr] * (f + 1) - dr[f];
    }
   // cout << k << ' ' << sum << endl;
   // exit(0);
    return sum <= k;
}


// void ans1(int ll, int rr) {
//     long long sum = 0;
//     if (upper_bound(l, l + n, v[ll]) != l + n) {
//         int f = distance(l, upper_bound(l, l + n, v[ll]));
//         sum += dl[n - 1] - (f > 0 ? dl[f - 1]: 0LL) - v[ll] * 1LL * (n - f);
//     }
//     if (lower_bound(r, r + n, v[rr]) != r) {
//         int f = distance(r, lower_bound(r, r + n, v[rr])) - 1;

//         sum += v[rr] * (f + 1) - dr[f];
//     }
//    // cout << v[rr] << endl;
//    // cout << k << ' ' << sum << endl;
//    // exit(0);
//     cout << sum << endl;
// }


int main() {
   	cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d", &l[i], &r[i]);
        maxp = min(maxp, r[i] - l[i] + 1LL);
    }
    sort(l, l + n);
    sort(r, r + n);
    for (int i = 0; i < n; i++) {
        dl[i] = (i > 0 ? dl[i - 1]: 0);
        dl[i] += l[i];
        dl[i] = min(dl[i], 2000LL * 1000 * 1000 * 1000 * 1000 * 1000 + 1LL);
        dr[i] = (i > 0 ? dr[i - 1]: 0);
        dr[i] += r[i];
        dr[i] = min(dr[i], 2000LL * 1000 * 1000 * 1000 * 1000 * 1000 + 1LL);
    }
    for (int i = 1; i <= 18; i++) {
        get(0, i, 0LL);
    }
    int sum = 0;
    for (int i = 0; i < (int)v.size(); i++) {
       // cout << i << endl;
        if (!ans(i, i)) {
        //   cout << i + 1 << endl;
            continue;
        }
        // ans1(i, i);
        // return 0;
      //  cout << v[i] << endl;
        //return 0;
      //  cout << v[i] << endl;
   //  cout << i + 1 << endl;
     //return 0;
        int ll = i;
        int rr = (int)v.size() - 1;
        while (ll != rr) {
            int m = (ll + rr + 1) / 2;
            if (ans(i, m)) {
                ll = m;
            } else {
                rr = m - 1;
            }
        }
     //   cout << ll - i + 1 << endl;
        sum = max(sum, ll - i + 1);
    }
    cout << sum << endl;
    return 0;
}