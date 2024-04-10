#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>


using namespace std;


string s1, s2;
int n, m;
int d[5000][5000], d1[5000][5000], d2[5000][5000];
int a[5000], a1[5000];


int main() {
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s1[i] == s2[j]) {
                d[i][j] = 1;
                if (i > 0 && j > 0) {
                    d[i][j] += d[i - 1][j - 1];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s1[i] == s1[j]) {
                d1[i][j] = 1;
                if (i > 0 && j > 0) {
                    d1[i][j] += d1[i - 1][j - 1];
                }
            }
            if (j != i) {
                a[i] = max(a[i], d1[i][j]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (s2[i] == s2[j]) {
                d2[i][j] = 1;
                if (i > 0 && j > 0) {
                    d2[i][j] += d2[i - 1][j - 1];
                }
            }
            if (j != i) {
                a1[i] = max(a1[i], d2[i][j]);
            }
        }
    }
    int ans = 1000000000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int s = max(a[i], a1[j]);
            if (d[i][j] >= s + 1) {
                ans = min(ans, s + 1);
            }
        }
    }
    if (ans == 1000000000) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}