#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
 
 
using namespace std;
 
 
int n;
int a[101][3];
int c[101];

 
int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 2; j++) {
            a[i][j] = n;
        }
    }
    a[0][0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        for (int j = 0; j <= 2; j++) {
            a[i + 1][0] = min(a[i + 1][0], 1 + a[i][j]);
        }
        if (c[i] == 2 || c[i] == 3) {
            for (int j = 0; j <= 2; j++) {
                if (j == 1) {
                    continue;
                }
                a[i + 1][1] = min(a[i + 1][1], a[i][j]);
            }
        }
        if (c[i] == 1 || c[i] == 3) {
            for (int j = 0; j <= 2; j++) {
                if (j == 2) {
                    continue;
                }
                a[i + 1][2] = min(a[i + 1][2], a[i][j]);
            }
        }
    }
    int ans = n;
    ans = min(ans, a[n][0]);
    ans = min(ans, a[n][1]);
    ans = min(ans, a[n][2]);
    cout << ans << endl;
    return 0;
}