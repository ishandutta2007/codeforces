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


#define M 1000000007
#define INF 1000000000


int n;
int q[4001];
int c[4001][4001];
int q1[4001];



int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                c[i][j] = 1;
                continue;
            }
            if (j == 1) {
                c[i][j] = i;
                continue;
            }
            if (j == i) {
                c[i][j] = 1;
                continue;
            }
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] %= M;
        }
    }
    q[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j + i <= n; j++) {
            q[j + i] += (1LL * q[i] * c[n - i - 1][j - 1]) % M;
            q[j + i] %= M;
        }
    }
    q1[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j + i <= n; j++) {
            q1[j + i] += (1LL * q1[i] * c[n - i - 1][j - 1]) % M;
            q1[j + i] %= M;
        }
        q1[i + 1] += q1[i];
        q1[i + 1] %= M;
    }
    int ans = (q1[n] - q[n] + M) % M;
    cout << ans << endl;
    return 0;
}