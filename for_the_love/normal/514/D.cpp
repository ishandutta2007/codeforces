#include <map>
#include <set>
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

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

#define lx x + x
#define rx lx + 1

int t[5][N << 2];
int a[5][N << 2];
int b[5], ans[5];
int n, m, k;


void Build(int p, int x, int l, int r){
    if (l == r){
        t[p][x] = a[p][l];
        return;
    }
    int mid = l + r >> 1;
    Build(p, lx, l, mid), Build(p, rx, mid + 1, r);
    t[p][x] = max(t[p][lx], t[p][rx]);
}

int Query(int p, int x, int l, int r, int a, int b){
    if (l >= a && r <= b) return t[p][x];
    int mid = l + r >> 1, ret = -INF;
    if (a <= mid) ret = max(ret, Query(p, lx, l, mid, a, b));
    if (b > mid) ret = max(ret, Query(p, rx, mid + 1, r, a, b));
    return ret;
}

bool Check(int lim){
    for (int i = 1; i <= n - lim + 1; i++){
        int sum = 0;
        for (int j = 0; j < m; j++){
            b[j] = Query(j, 1, 1, n, i, i + lim - 1);
            sum += b[j];
        }
        if (sum <= k) return 1;
    }
    return 0;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++)
        scanf("%d", &a[j][i]);
    for (int i = 0; i < m; i++)
        Build(i, 1, 1, n);
    int l = 1, r = n, res = -1;
    while (l <= r){
        int mid = l + r >> 1;
        if (Check(mid)){
            l = mid + 1;
            res = mid;
            for (int i = 0; i < m; i++)
                ans[i] = b[i];
        }else r = mid - 1;
    }
    //printf("%d\n", res);
    for (int i = 0; i < m; i++)
        printf("%d ", ans[i]);
}