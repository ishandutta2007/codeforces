#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
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
const int N = 1e5 + 7;
const int M = 3e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

struct Segment{
    int sign, s;
} t[N * 8];

#define lx x + x
#define rx lx + 1
int l[N], r[N], q[N];

void PushDown(int x){
    t[x].s |= t[x].sign;
    t[lx].sign |= t[x].sign;
    t[rx].sign |= t[x].sign;
    t[x].sign = 0;
}

void Add(int x, int l, int r, int a, int b, int c){
    PushDown(x);
    if (l >= a && r <= b){
        t[x].sign |= c;
        PushDown(x);
        return;
    }
    int mid = l + r >> 1;
    if (a <= mid) Add(lx, l, mid, a, b, c);
    if (b > mid) Add(rx, mid + 1, r, a, b, c);
    PushDown(lx); PushDown(rx);
    t[x].s = t[lx].s & t[rx].s;
}

int Query(int x, int l, int r, int a, int b){
    PushDown(x);
    if (l >= a && r <= b) return t[x].s;
    int mid = l + r >> 1, ret = (1 << 30) - 1;
    if (a <= mid) ret &= Query(lx, l, mid, a, b);
    if (b > mid) ret &= Query(rx, mid + 1, r, a, b);
    return ret;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &l[i], &r[i], &q[i]);
        Add(1, 1, n, l[i], r[i], q[i]);
    }
    for (int i = 1; i <= m; i++){
        if (Query(1, 1, n, l[i], r[i]) != q[i]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", Query(1, 1, n, i, i));
}