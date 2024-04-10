#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
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
const int N = int(2e6) + 9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m, dx, dy, cnt[N], a[N], b[N], A[N], B[N];

int get(int x, int y){
    return (x - y + n) % n;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &dx, &dy);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++){
        a[x] = i;
        b[y] = i;
        A[i] = x, B[i] = y;
        x = (x + dx) % n;
        y = (y + dy) % n;
    }

    for (int i = 0; i < m; i++){
        scanf("%d%d", &x, &y);
        cnt[get(a[x], b[y])]++;
    }
    int ans = -1, pos = 0;
    for (int i = 0; i < n; i++){
        if (cnt[i] > ans){
            ans = cnt[i];
            pos = i;
        }
    }

    printf("%d %d\n", A[0], B[n - pos]);
}