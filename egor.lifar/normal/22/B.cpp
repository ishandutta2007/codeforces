#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int n, m;
string s[25];
int d[25][25];


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                d[i][j] = 1;
            }
            d[i][j] += (i > 0 ? d[i - 1][j]: 0) + (j > 0 ? d[i][j - 1]: 0);
            d[i][j] -= (i > 0 && j > 0 ? d[i - 1][j - 1]: 0);
        }
    }
    int ans = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int g = i; g < n; g++) {
                for (int k = j; k < m; k++) {
                    if (d[g][k] + (i > 0 && j > 0 ? d[i - 1][j - 1]: 0) - (j > 0 ? d[g][j - 1]: 0) - (i > 0 ? d[i - 1][k]: 0) == 0) {
                        ans = max(ans, (k - j + g - i + 2) * 2);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}