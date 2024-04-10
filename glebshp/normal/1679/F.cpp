#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int mdl = 998244353;
const int maxn = 50 * 1000 + 100;

int n, m;
int ans[2][1 << 10];
bool allowed[10][10];
bool canmove[1 << 10][10];
unsigned int movemask[1 << 10][10];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        allowed[u][v] = true;
        allowed[v][u] = true;
    }

    for (int i = 0; i < (1 << 10); i++) {
        for (int j = 0; j < 10; j++) {
            bool can = true;
            unsigned int tg = 1 << j;
            for (int k = 0; k < 10; k++) {
                if ((i >> k) & 1) {
                    if (allowed[k][j] && (k < j)) {
                        can = false;
                    }
                    if (allowed[k][j]) {
                        tg += (1 << k);
                    }
                }
            }

            canmove[i][j] = can;
            movemask[i][j] = tg;
        }
    }

    int cur = 0;
    for (int i = 0; i < 10; i++) {
        ans[0][1 << i] = 1;

    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < (1 << 10); j++) {
            ans[cur ^ 1][j] = 0;
        }
        for (int j = 1; j < (1 << 10); j++) {
            if (ans[cur][j] == 0) {
                continue;
            }
            for (int k = 0; k < 10; k++) {
                if (canmove[j][k]) {
                    unsigned int tgm = movemask[j][k];
                    ans[cur ^ 1][tgm] += ans[cur][j];
                    if (ans[cur ^ 1][tgm] >= mdl) {
                        ans[cur ^ 1][tgm] -= mdl;
                    }
                }
            }
        }
        cur ^= 1;
    }
    int res = 0;
    for (int i = 1; i < (1 << 10); i++) {
        res += ans[cur][i];
        if (res >= mdl) {
            res -= mdl;
        }
    }

    cout << res << endl;

    return 0;
}