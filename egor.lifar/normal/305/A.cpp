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
#include <vector>
#include <stdio.h>


using namespace std;


int k;
int d[101][10001];
bool c[101][10001];
int a[101];



bool good(int a, int b) {
    while (a > 0 && b > 0) {
        if (a % 10 && b % 10) {
            return 0;
        }
        a /= 10;
        b /= 10;
    }
    return 1;
}


int main() {
    cin >> k;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &a[i]);
        for (int j = 0; j <= 10000; j++) {
            d[i][j] = max(d[i][j], d[i - 1][j]);
            if (j >= a[i]) {
                if (good(j - a[i], a[i])) {
                    d[i][j] = max(d[i][j], d[i - 1][j - a[i]] + 1);
                    if (d[i][j] == d[i - 1][j - a[i]] + 1) {
                        c[i][j] = 1;
                    }
                }
            }
        }
    }  
    int ans = 0;
    int li = k;
    int lj = -1;
    for (int j = 0; j <= 10000; j++) {
        ans = max(ans, d[k][j]);
        if (ans == d[k][j]) {
            lj = j;
        }
    }
    cout << ans << endl;
    while (li) {
        bool t = c[li][lj];
        if (t) {
            printf("%d ", a[li]);
        }
        lj -= (t ? a[li]: 0);
        li--;
    }
    printf("\n");
    return 0;
}