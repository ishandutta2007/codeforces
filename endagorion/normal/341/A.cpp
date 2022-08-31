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

long long a[200000];
long long psum[200000];

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    cin >> N;
    long long snum = 0, sden = N;
    long long mnum = 0, mden = N;
    psum[0] = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        snum += a[i];
    }
    sort(a, a + N);
    for (int i = 0; i < N; ++i) {
        psum[i + 1] = psum[i] + a[i];
    }
    for (int i = 0; i < N; ++i) {
        mnum += 2 * (i * a[i] - psum[i]);
    }
    long long rnum = snum + mnum, rden = N;
    long long g = gcd(rnum, rden);
    rnum /= g;
    rden /= g;
    cout << rnum << ' ' << rden << '\n';

    return 0;
}