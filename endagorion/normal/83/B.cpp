#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using std::vector;
using std::pair;
using std::make_pair;
using std::min;
using std::max;
using std::cin;
using std::cout;

long long toKill(const vector<long long> &a, long long x) {
    long long res = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        res += min(a[i], x);
    }
    return res;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    long long maxA = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
        maxA = max(maxA, a[i]);
    }
    long long l = 0, r = maxA + 1;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (toKill(a, m) > k) {
            r = m;
        } else {
            l = m;
        }
    }
    if (k > s) {
        cout << -1 << '\n';
        return 0;
    }
    k -= toKill(a, l);
    for (int i = 0; i < n; ++i) {
        a[i] = max(a[i] - l, (long long)0);
    }
    vector <long long> ansB, ansE;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            if (k > 0) {
                if (a[i] > 1) {
                    ansE.push_back(i + 1);
                }
                --k;
            } else {
                ansB.push_back(i + 1);
            }
        }
    }
    for (size_t i = 0; i < ansB.size(); ++i) {
        cout << ansB[i] << ' ';
    }
    for (size_t i = 0; i < ansE.size(); ++i) {
        cout << ansE[i] << ' ';
    }
    cout << '\n';
    return 0;
}