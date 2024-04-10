#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int v1, v2, t, d;
int f[110][1111];


int main(){
    scanf("%d%d", &v1, &v2);
    scanf("%d%d", &t, &d);
    t--;
    for (int i = 0; i <= t; i++)
    for (int j = 0; j <= 1100; j++)
        f[i][j] = -INF;
    f[0][v1] = 0;
    for (int i = 1; i <= t; i++)
    for (int j = 0; j <= 1100; j++)
    for (int k = -d; k <= d; k++)
    if (j + k >= 0) f[i][j + k] = max(f[i][j + k], f[i - 1][j] + j);

    printf("%d\n", f[t][v2] + v2);
}