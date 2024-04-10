#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s[4];
bool f[8][8] = {};
int a[8][8] = {};

int main() {
    REP(i, 4) {
        cin >> s[i];
        if (i < 3) {
            f[s[i][0] - 'a'][s[i][1] - '1'] = true;
            a[s[i][0] - 'a'][s[i][1] - '1'] = 1;
        }
    }
    REP(i, 2) {
        int yy = s[i][0] - 'a';
        int xx = s[i][1] - '1';
        for (int y = yy - 1; y >= 0; --y) {
            ++a[y][xx];
            if (f[y][xx]) break;
        }
        for (int y = yy + 1; y < 8; ++y) {
            ++a[y][xx];
            if (f[y][xx]) break;
        }
        for (int x = xx - 1; x >= 0; --x) {
            ++a[yy][x];
            if (f[yy][x]) break;
        }
        for (int x = xx + 1; x < 8; ++x) {
            ++a[yy][x];
            if (f[yy][x]) break;
        }
    }
    int yy = s[2][0] - 'a';
    int xx = s[2][1] - '1';
    for (int y = max(0, yy - 1); y <= min(7, yy + 1); ++y) {
        for (int x = max(0, xx - 1); x <= min(7, xx + 1); ++x) {
            if (y == yy && x == xx) continue;
            ++a[y][x];
        }
    }
    yy = s[3][0] - 'a';
    xx = s[3][1] - '1';
    for (int y = max(0, yy - 1); y <= min(7, yy + 1); ++y) {
        for (int x = max(0, xx - 1); x <= min(7, xx + 1); ++x) {
            if (!a[y][x] || (a[y][x] == 1 && f[y][x])) {
                printf("OTHER\n");
                return 0;
            }
        }
    }
    printf("CHECKMATE\n");
    return 0;
}