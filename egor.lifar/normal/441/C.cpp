#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <map>
#include <string.h>
#include <vector>


using namespace std;


int n, m, k;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool b[303][303];


int main() {
    cin >> n >> m >> k;
    bool t = true;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
                b[i][j] = true;
            }
        }
    }
    int x = 1;
    int y = 0;
    int s = 1;
    bool g = true;
    while (g) {
        g = false;
        int t = 0;
        for (int i = 0; i < 4; i++) {
            while (!b[x + dx[i]][y + dy[i]]) {
                g = true;
                t = t % 2;
                x += dx[i];
                y += dy[i];
                b[x][y] = true;
                if (s < k) {
                    if (t == 0) {
                        cout << 2 << ' ' << x << ' ' << y << ' ';
                    } else {
                        cout << x << ' ' << y << endl;
                        s++;
                    }
                } else {
                    if (s == k) {
                        cout << n * m - 2 * (k - 1);
                    }
                    cout << ' ' << x << ' ' << y;
                    s++;
                }
                t++;
            }
        }
    }
    cout << endl;
    return 0;
}