#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int n, k, ans = -1;
int a1[1000001], b1[1000001], a[1000001], b[1000001], t[1000001], d[1000001], in[1000001], Max[2000001];
int s = 1;


int getmax (int v, int vl, int vr, int l, int r) {
    if (l > vr || r < vl) {
        return 0;
    }
    if (vl >= l && vr <= r) {
        return Max[v];
    }
    return max(getmax(v * 2, vl, (vl + vr) / 2, l, r), getmax(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}


void update(int v) {
    v /= 2;
    if (v <= 0) {
        return;
    } 
    Max[v] = max(Max[v * 2], Max[v * 2 + 1]);
    update(v);
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a1[i];
        t[a1[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> b1[i];
    }
    for (int i = 0; i < n; i++) { 
        a[i] = i;
        b[i] = t[b1[i]];
    }
    while (n > s) {
        s *= 2;
        k++;
    }
    for (int i = 1; i < 2 * s; i++) {
        Max[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        d[i] = getmax(1, 1, s, b[i], n) + 1;
        Max[s + b[i] - 1] = d[i];
        update(s + b[i] - 1);
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}


//1 2 3 4
//3 4 1 2