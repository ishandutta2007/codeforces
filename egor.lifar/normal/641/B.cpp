#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <unordered_map>

using namespace std;

int n, m;

int a[100][100];

int d[10000];

int main() {
    //freopen("input.txt", "r");
    //freopen("output.txt", "w");

    int q;
    scanf("%d %d %d", &n, &m, &q);

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = count++;
        }
    }

    while (q--) {
        int t;
        scanf("%d", &t);

        int r, c, x;
        if (t == 1) {
            scanf("%d", &r);
        } else if (t == 2) {
            scanf("%d", &c);
        } else {
            scanf("%d %d %d", &r, &c, &x);
        }

        r -= 1;
        c -= 1;

        if (t == 3) {
            d[a[r][c]] = x;
        }

        if (t == 1) {
            int p = a[r][0];
            for (int j = 0; j < m - 1; j++) {
                a[r][j] = a[r][j + 1];
            }
            a[r][m - 1] = p;
        }

        if (t == 2) {
            int p = a[0][c];
            for (int i = 0; i < n - 1; i++) {
                a[i][c] = a[i + 1][c];
            }
            a[n - 1][c] = p;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", d[i * m + j]);
        }
        printf("\n");
    }



    return 0;
}