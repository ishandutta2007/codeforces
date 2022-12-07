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

const int MX = 5003;
int fen[MX][MX] = {}, fen2[2 * MX][MX] = {}, fen3[2 * MX][MX] = {};
int n, q;

void fenInc(int (&fen)[MX][MX], int x, int Y) {
    for (; x < MX; x |= x + 1) {
        for (int y = Y; y < MX; y |= y + 1) {
            ++fen[x][y];
        }
    }
}

void fenDec(int (&fen)[MX][MX], int x, int Y) {
    for (; x < MX; x |= x + 1) {
        for (int y = Y; y < MX; y |= y + 1) {
            --fen[x][y];
        }
    }
}

void fenInc(int (&fen)[2 * MX][MX], int x, int Y) {
    for (; x < 2 * MX; x |= x + 1) {
        for (int y = Y; y < MX; y |= y + 1) {
            ++fen[x][y];
        }
    }
}

void fenDec(int (&fen)[2 * MX][MX], int x, int Y) {
    for (; x < 2 * MX; x |= x + 1) {
        for (int y = Y; y < MX; y |= y + 1) {
            --fen[x][y];
        }
    }
}

int fenGet(int (&fen)[MX][MX], int x, int Y) {
    int ret = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
        for (int y = Y; y >= 0; y = (y & (y + 1)) - 1) {
            ret += fen[x][y];
        }
    }
    return ret;
}

int fenGet(int (&fen)[2 * MX][MX], int x, int Y) {
    int ret = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
        for (int y = Y; y >= 0; y = (y & (y + 1)) - 1) {
            ret += fen[x][y];
        }
    }
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    REP(i, q) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int dir, x, y, len;
            scanf("%d%d%d%d", &dir, &x, &y, &len);
            if (dir == 1) {
                fenInc(fen, x, y);
                fenDec(fen, x, y + len + 1);
                fenDec(fen2, x + y + len + 1, y);
                fenInc(fen2, x + y + len + 1, y + len + 1);
            } else if (dir == 2) {
                fenInc(fen, x, y - len);
                fenDec(fen, x, y + 1);
                fenDec(fen3, n + 2 + x - y + len, y - len);
                fenInc(fen3, n + 2 + x - y + len, y + 1);
            } else if (dir == 3) {
                fenDec(fen, x + 1, y);
                fenInc(fen, x + 1, y + len + 1);
                fenInc(fen3, n + 1 + x - len - y, y);
                fenDec(fen3, n + 1 + x - len - y, y + len + 1);
            } else {
                fenDec(fen, x + 1, y - len);
                fenInc(fen, x + 1, y + 1);
                fenInc(fen2, x + y - len, y - len);
                fenDec(fen2, x + y - len, y + 1);
            }
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%d\n", fenGet(fen, x, y) + fenGet(fen2, x + y, y) + fenGet(fen3, n + 1 + x - y, y));
        }
    }
    return 0;
}