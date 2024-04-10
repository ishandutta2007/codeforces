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


int n, d, h;


int main() {
    cin >> n >> d >> h;
    if (h < (d + 1) / 2) {
        cout << -1 << endl;
        return 0;
    }
    if (d < h) {
        cout << -1 << endl;
        return 0;
    }
    if (h == d && d < 2 && n > 2) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= d; i++) {
        if (i == h) {
            printf("%d %d\n", 2 + i - 1, 1);
        } else {
            if (i == h + 1) {
                printf("%d %d\n", 1, 2 + i - 1);
            } else {
                if (i < h) {
                    printf("%d %d\n", 2 + i - 1, 2 + i);
                } else {
                    printf("%d %d\n", 2 + i - 2, 2 + i - 1);
                }
            }
        }
    }
    if (h == d) {
        for (int j = d + 2; j <= n; j++) {
            printf("%d %d\n", 3, j);
        }
        return 0;
    }
    for (int j = d + 2; j <= n; j++) {
        printf("%d %d\n", 1, j);
    }
    return 0;
}