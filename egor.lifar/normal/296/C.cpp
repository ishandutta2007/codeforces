#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


long long a[100001], b[100001], b1[100001], l[100001], r[100001], d[100001];
int n, m, k;


int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> d[i];
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        b1[x - 1]++;
        b1[y]--;
    }
    long long s = 0;
    for (int i = 0; i < m; i++) {
        s+= b1[i];
        d[i] *= s;
    }
    for (int i = 0; i < m; i++) {
        b[l[i] - 1] += d[i];
        b[r[i]] -= d[i];
    }
    s = 0;
    for (int i = 0; i < n; i++) {
        s += b[i];
        a[i] += s;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}