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
#include <cstring>
#include <cmath>


using namespace std;


int n;
string s;
int a[200001];
int d[200001][2][2][2];


int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        d[i][s[i] - '0'][0][0] = 1;
        d[i][1 - (s[i] - '0')][1][1] = 1;
        if (i == 0) {
            continue;
        }
        for (int j = 0; j < 2; j++) {
            for (int g = 0; g < 2; g++) {
                for (int k = 0; k < 2; k++) {
                    d[i][j][g][k] = max(d[i][j][g][k], d[i - 1][j][g][k]);
                }
            }
        }
        for (int t = 0; t < 2; t++) {
            d[i][s[i] - '0'][t][0] = max(d[i][s[i] - '0'][t][0], d[i - 1][1 - (s[i] - '0')][t][0] + 1);
            d[i][s[i] - '0'][t][0] = max(d[i][s[i] - '0'][t][0], d[i - 1][1 - (s[i] - '0')][t][1] + 1);
        }
        d[i][1 - (s[i] - '0')][1][1] = max(d[i][1 - (s[i] - '0')][1][1], d[i - 1][s[i] - '0'][0][0] + 1);
        d[i][1 - (s[i] - '0')][1][1] = max(d[i][1 - (s[i] - '0')][1][1], d[i - 1][s[i] - '0'][1][1] + 1);
    }
    int ans = 0;
    for (int j = 0; j < 2; j++) {
        for (int g = 0; g < 2; g++) {
            for (int k = 0; k < 2; k++) {
                ans = max(ans, d[n - 1][j][g][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}