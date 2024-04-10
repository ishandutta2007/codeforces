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


int n, a, b;


int main() {
    cin >> n >> a >> b;
    int f = 0;
    int f1 = 0;
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            f += (b + 1) / 2;
            f1 += b / 2;
        } else {
            f1 += (b + 1) / 2;
            f += b / 2;
        }
    }
    if (f < (n + 1) / 2 || f1 < n / 2) {
        cout << -1 << endl;
        return 0;
    }
    int t = 1;
    int t1 = 2;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if ((i + j) % 2 == 0 && t <= n) {
                printf("%d ", t);
                t += 2;
                continue;
            }
            if ((i + j) % 2 == 1 && t1 <= n) {
                printf("%d ", t1);
                t1 += 2;
                continue;
            }
            printf("0 ");
        }
        printf("\n");
    }
    return 0;
}