#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;


#define M 1000000007
#define P 424243


string s, s1;
int n;
int h[200001];
int h1[200001];
int p[200001];


int gethash(int l, int r) {
    return (h[r] - (l > 0 ? 1LL * h[l - 1] * p[r - l + 1]: 0) % M + M) % M;
}


int gethash1(int l, int r) {
    return (h1[r] - (l > 0 ? 1LL * h1[l - 1] * p[r - l + 1]: 0) % M + M) % M;
}


bool good(int l, int r, int l1, int r1) {
    if (gethash(l, r) == gethash1(l1, r1)) {
        return true;
    }
    if ((r - l + 1) % 2 == 0) {
        return ((good(l, (l + r) / 2, (l1 + r1) / 2 + 1, r1) && good((l + r) / 2 + 1, r, l1, (l1 + r1) / 2)) || (good(l, (l + r) / 2, l1, (l1 + r1) / 2) && good((l + r) / 2 + 1, r, (l1 + r1) / 2 + 1, r1)));
    } else {
        return false;
    }
}


int main() {
    cin >> s >> s1;
    n = (int)s.size();
    int m = n;
    while (m % 2 == 0) {
        m /= 2;
    }
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = (1LL * p[i - 1] * P) % M;
    }
    for (int i = 0; i < n; i++) {
        h[i] = ((i > 0 ? 1LL * h[i - 1] * P: 0) % M + s[i]) % M;
    }
    for (int i = 0; i < n; i++) {
       h1[i] = ((i > 0 ? 1LL * h1[i - 1] * P: 0) % M + s1[i]) % M;
    }
    if (good(0, n - 1, 0, n - 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}