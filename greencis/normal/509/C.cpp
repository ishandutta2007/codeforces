#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAXN = 1000;

int n,b[999];
int a[999][MAXN];
int len[999];

int comp(int idxa, int idxb) {
    for (int i = 0; i < MAXN; ++i) {
        if (a[idxa][i] > a[idxb][i]) return 1;
        if (a[idxa][i] < a[idxb][i]) return -1;
    }
    return 0;
}

void gen(int idx, int num) {
    len[idx] = (num + 8) / 9;
    for (int i = MAXN-1; i >= 0 && num > 0; --i) {
        if (num >= 9) a[idx][i] = 9, num -= 9;
        else a[idx][i] = num, num = 0;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",&b[i]);

    gen(0, b[0]);
    for (int i = 1; i < n; ++i) {
        int prevsum = 0;
        for (int j = MAXN-1; j >= 0; --j) prevsum += a[i-1][j], a[i][j] = a[i-1][j];

        bool good = false;
        for (int j = MAXN-1; j >= 0 && !good; --j) {
            for (int z = a[i][j] + 1; z <= 9 && !good; ++z) {
                if (prevsum + z - a[i][j] <= b[i] && b[i] - (prevsum + z - a[i][j]) <= 9 * (MAXN - j - 1)) {
                    good = true;
                    int sumleft = b[i] - (prevsum + z - a[i][j]);
                    a[i][j] = z;
                    int curidx = MAXN-1;
                    while (curidx > j) {
                        if (sumleft > 9) a[i][curidx] = 9, sumleft -= 9;
                        else a[i][curidx] = sumleft, sumleft = 0;
                        --curidx;
                    }
                }
            }
            prevsum -= a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        bool was = false;
        for (int j = 0; j < MAXN; ++j) {
            if (a[i][j]) was = true;
            if (was) printf("%d",a[i][j]);
        }
        if (!was) printf("0");
        printf("\n");
    }

    return 0;
}