#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)
#define MAXSQN 32000
#define MAXLG 29

typedef long long lint;

using namespace std;

const int maxsqn = MAXSQN;
const int maxlg = MAXLG;

bool used[MAXSQN+10];
int grundy[MAXLG+1];
map<int, int> memo;

int calc(int mask)
{
    if (memo.find(mask) != memo.end()) return memo[mask];

    int guse[14];
    memset(guse, 0, sizeof(guse));
    for (int exp = 1; exp <= maxlg; exp++)
        if (mask & (1<<exp)) {
            int mask2 = mask;
            for (int v = exp; v <= maxlg; v += exp)
                mask2 &= ~(1<<v);
            guse[calc(mask2)] = 1;
        }

    int v;
    for (v = 0; guse[v]; v++);

    return memo[mask] = v;
}

int calc_grundy(int many)
{
    if (many == 0) return 0;
    if (many == 1) return 1;

    if (many == 2) return 2;
    if (many == 3) return 1;
    if (many == 4) return 4;
    if (many == 5) return 3;
    if (many == 6) return 2;
    if (many == 7) return 1;
    if (many == 8) return 5;
    if (many == 9) return 6;
    if (many == 10) return 2;
    if (many == 11) return 1;
    if (many == 12) return 8;
    if (many == 13) return 7;
    if (many == 14) return 5;
    if (many == 15) return 9;
    if (many == 16) return 8;
    if (many == 17) return 7;
    if (many == 18) return 3;
    if (many == 19) return 4;
    if (many == 20) return 7;
    if (many == 21) return 4;
    if (many == 22) return 2;
    if (many == 23) return 1;
    if (many == 24) return 10;
    if (many == 25) return 9;
    if (many == 26) return 3;
    if (many == 27) return 6;
    if (many == 28) return 11;
    if (many == 29) return 12;

    return calc((1<<(many+1))-1-1);
}

int main(int argc, char ** argv)
{
    lint n;

    cin >> n;

    lint div = min((lint)ceill(powl(1.0L * n, 0.5))+3LL, n);

    for (int s = 0; s <= maxlg; s++)
        grundy[s] = calc_grundy(s);
    
    lint result = grundy[1];

    lint remainoutdiv = n-div;
    for (lint x = 2; x <= div; x++) {
        if (used[x]) continue;

        int size = 0;

        for (lint y = x; y <= n; y *= x, size ++) {
            if (y <= div)
                used[y] = true;
            else
                remainoutdiv --;
        }

        result ^= grundy[size];
    }
    if (remainoutdiv%2)
        result ^= grundy[1];

    if (result)
        cout << "Vasya" << endl;
    else
        cout << "Petya" << endl;

    return 0;
}