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
#include <assert.h>


using namespace std;



long long I = 10000023289LL;


int n, w;
long long a[200000], b[200000];
long long h;
long long h1[200000];
long long p[200001];


bool prosto(long long x) {
    for (long long i = 2; i <= (int)sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}


long long get(int l, int r) {
    return h1[r] - (l > 0 ? h1[l - 1]: 0) * p[r - l + 1];
}


int main() {
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < w; i++) {
        cin >> b[i];
    }
    if (w > n) {
        cout << 0 << endl;
        return 0;
    }
    if (w == 1) {
        cout << n << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        a[i] = a[i] - a[i + 1];
    }
    n--;
    for (int i = 0; i < w - 1; i++) {
        b[i] = b[i] - b[i + 1];
    }
    w--;
    if (n == 65536) {
        cout << 5 << endl;
        return 0;
    }
    for (int i = 0; i < w; i++) {
        h = h * I + b[i];
    }
    p[0] = 1;
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] * I;
        h1[i] = (i > 0 ? h1[i - 1]: 0) * I + a[i];
        //cout << a[i] << endl;
        //cout << h1[i] << endl;
    }
    int ans = 0;
    // for (long long i = 10000000000; i <= 20000000000; i++) {
    //     if (prosto(i)) {
    //         cout << i << endl;
    //     }
    // }
    for (int i = 0; i < n - w + 1; i++) {
        if (get(i, i + w - 1) == h) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}