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


using namespace std;


int n, m;
char c[101][101];
int g[101][101];


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!(c[i][j] >= 'A' && c[i][j] <= 'Z')) {
                vector<int> bad;
                bad.resize(6);
                if (i > 0) {
                    bad[c[i - 1][j] - 'A']++;
                }
                bad[c[i][j - 1] - 'A']++;
                if (j + 1 < m && c[i][j + 1] >= 'A' && c[i][j + 1] <= 'Z') {
                    bad[c[i][j + 1] - 'A']++;
                }
                int k = 0;
                for (int i = 0; i <= 5; i++) {
                    if (!bad[i]) {
                        k = i;
                        break;
                    }
                }
                char cc = 'A' + k;
                if (j == 0 || cc < c[i][j - 1]) {
                    c[i][j] = cc;
                    g[i][j] = 1;
                    continue;
                }
           //     cout << "opa" << endl;
                if (j > 0 && bad[c[i][j - 1] - 'A'] == 1) {
                    int j1 = j - g[i][j - 1];
                    int i1 = i;
                //    cout << i1 << ' ' << j1 << endl;
                    if (i1 + g[i][j - 1] >= n || j1 + g[i][j - 1] >= m) {
                        c[i][j] = cc;
                        g[i][j] = 1;
                        continue;
                    }
                    //cout << i1 << ' ' << j1 << endl;
                    bool b = true; 
                    int f = g[i1][j1];
                    for (int i2 = i1; i2 <= i1 + f; i2++) {
                        for (int j2 = j1; j2 <= j1 + f; j2++) {
                            if (i2 == i1) {
                                if (i2 > 0) {
                                    if (c[i2 - 1][j2] == c[i1][j1]) {
                                        b = false;
                                        break;
                                    }
                                }
                            }
                            if (j2 == j1) {
                                if (j2 > 0) {
                                    if (c[i2][j2 - 1] == c[i1][j1]) {
                                        b = false;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if (!b) {
                        c[i][j] = cc;
                        g[i][j] = 1;
                        continue;
                    }
                    for (int i2 = i1; i2 <= i1 + f; i2++) {
                        for (int j2 = j1; j2 <= j1 + f; j2++) {
                            c[i2][j2] = c[i1][j1];
                            g[i2][j2] = f + 1;
                        }
                    }
                } else {
                    c[i][j] = cc;
                    g[i][j]  =1;
                    continue;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << c[i][j];
        }
        cout << endl;
    }
    return 0;
}