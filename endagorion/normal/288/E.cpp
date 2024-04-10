#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

const long long P = 1000000000 + 7;
const int MAXN = 300010;
long long d10[MAXN], d2[MAXN];
long long ans[MAXN], ssum[MAXN];
long long i9 = (P + 1) / 9;

inline long long _n(long long Q) {
    return (Q % P + P) % P;
}

long long append(long long res, long long sum, long long low, long long high, long long count, int l, int d) {
    long long nres = _n(res + _n(d * _n(_n(2 * sum - low - high) * d10[l])) + _n(d * d * _n((count - 1) * d10[2 * l])));
    return nres % P;
}

long long solve(string s) {
    int N = s.length();
    reverse(all(s));
    long long res;
    long long count;
    long long low, high;
    long long sum;
    if (s[0] == '4') {
        res = 0;
        count = 1;
        low = high = 4;
        sum = 4;
    } else {
        res = 28;
        count = 2;
        low = 4;
        high = 7;
        sum = 11;
    }
    for (int i = 1; i < N; ++i) {
        long long nres, ncount, nlow, nhigh, nsum;
        if (s[i] == '4') {
            nres = append(res, sum, low, high, count, i, 4);
            ncount = count;
            nlow = (low + 4 * d10[i]) % P;
            nhigh = (high + 4 * d10[i]) % P;
            nsum = (sum + 4 * _n(count * d10[i])) % P;
        } else {
            long long b1 = _n(4 * d10[i] + 7 * _n(i9 * (d10[i] - 1)));
            long long b2 = _n(7 * d10[i] + 4 * _n(i9 * (d10[i] - 1)));
            long long half = append(ans[i - 1], ssum[i - 1], _n(4 * _n(i9 * (d10[i] - 1))), _n(7 * _n(i9 * (d10[i] - 1))),
                d2[i], i, 4) + b1 * b2;
            nres = _n(half + append(res, sum, low, high, count, i, 7));
            ncount = (count + d2[i]) % P;
            nlow = (low + 4 * d10[i]) % P;
            nhigh = (high + 7 * d10[i]) % P;
            nsum = _n(sum + 7 * _n(count * d10[i]) + ssum[i - 1] + 4 * _n(d10[i] * d2[i]));
        }
        res = nres; count = ncount; low = nlow; high = nhigh; sum = nsum;
    }
    return res;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    string s1, s2;
    cin >> s1 >> s2;
    int N = s1.length();
    d10[0] = d2[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        d10[i] = (d10[i - 1] * 10) % P;
        d2[i] = (d2[i - 1] * 2) % P;
    }
    ans[0] = 28;
    ssum[0] = 11;
    for (int i = 1; i < MAXN; ++i) {
        long long b1 = _n(4 * d10[i] + 7 * _n(i9 * (d10[i] - 1)));
        long long b2 = _n(7 * d10[i] + 4 * _n(i9 * (d10[i] - 1)));
        ans[i] = _n(append(ans[i - 1], ssum[i - 1], _n(4 * _n(i9 * (d10[i] - 1))), _n(7 * _n(i9 * (d10[i] - 1))),
            d2[i], i, 4) + append(ans[i - 1], ssum[i - 1], _n(4 * _n(i9 * (d10[i] - 1))), _n(7 * _n(i9 * (d10[i] - 1))),
            d2[i], i, 7) + _n(b1 * b2));
        ssum[i] = _n(2 * ssum[i - 1] + 11 * _n(d10[i] * d2[i]));
    }
    cout << _n(solve(s2) - solve(s1)) << '\n';

	return 0;
}