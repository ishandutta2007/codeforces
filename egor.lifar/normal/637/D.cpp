#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>


using namespace std;


int n, m;
int a[300001];
bool d[300001];
pair<bool, int> r[1000001];
int ss = 1;
int c[300001];


void change(int i, bool x) {
    r[i] = make_pair(x, i - ss);
    while (i / 2 > 0) {
        i /= 2;
        r[i] = max(r[i * 2], r[i * 2 + 1]);
    } 
}


int main() {
    int s, dd;
    cin >> n >> m >> s >> dd;
    a[0] = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    while (ss <= n) {
        ss *= 2;
    }
    int rr = n;
    for (int i = n; i >= 0; i--) {
        if (i == n) {
            change(i + ss, 1);
            d[i] = 1;
            c[i] = -1;
            continue;
        }
        while (a[rr] - a[i + 1] + 2 > dd) {
            change(ss + rr, 0);
            rr--;
        }
        if (a[i + 1] - a[i] - 2 >= s && r[1].first == 1) {
            c[i] = r[1].second;
            d[i] = 1;
            change(i + ss, 1);
        } else {
            d[i] = 0;
            c[i] = -1;
        }
    }
    if (!d[0]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int f = 0;
    while (f != -1) {
        if (f == n) {
            if (m == a[f] + 1) {
                return 0;
            }
            printf("RUN %d\n", m - a[f] - 1);
            return 0;
        }
        printf("RUN %d\n", a[f + 1] - a[f] - 2);
        printf("JUMP %d\n", a[c[f]] - a[f + 1] + 2);
        f = c[f];
    }
    return 0;
}