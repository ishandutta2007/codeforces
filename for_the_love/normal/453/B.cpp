#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 105;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int a[N], b[N], v[N], f[N][1 << 16], n, ans[N], num[N][1 << 16], from[N][1 << 16], p[N], m, mask[N], res[N];

void Solve(int i, int j){
    if (!i) return;
    res[i] = num[i][j];
    Solve(i - 1, from[i][j]);
}

bool cmp(int i, int j){return a[i] < a[j];}

int main(){
    for (int i = 2; i < 100; i++) if (!v[i]){
        p[m++] = i;
        mask[i] |= (1 << (m - 1));
        for (int j = 2; j * i < 100; j++){
            mask[i * j] |= (1 << (m - 1));
            v[i * j] = 1;
        }
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);


    memset(f, 0x7f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 0; j < 1 << 16; j++)
    for (int k = 1; k <= 58; k++)
    if ((mask[k] & j) == 0){
        int t = f[i - 1][j] + abs(k - a[i]);
        if (t < f[i][j | mask[k]]){
            f[i][j | mask[k]] = t;
            num[i][j | mask[k]] = k;
            from[i][j | mask[k]] = j;
        }
    }
    int ans = INF, t;
    for (int i = 0; i < 1 << 16; i++)
    if (f[n][i] < ans){
        ans = f[n][i];
        t = i;
    }
    Solve(n, t);
    for (int i = 1; i <= n; i++) printf("%d ", res[i]);
}