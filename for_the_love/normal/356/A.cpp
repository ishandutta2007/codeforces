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
const int N = 3e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

struct Segment{
    int sign, s;
} t[N * 8];

#define lx x + x
#define rx lx + 1

inline void PushDown(int x){
    if (!t[x].sign) return;
    t[x].s = t[x].sign;
    t[lx].sign = t[x].sign, t[rx].sign = t[x].sign;
    t[x].sign = 0;
}
int Query(int x, int l, int r, int a){
    PushDown(x);
    if (l == r) return t[x].s;
    int mid = l + r >> 1;
    if (a <= mid) return Query(lx, l, mid, a); else return Query(rx, mid + 1, r, a);
}

void Insert(int x, int l, int r, int a, int b, int c){
    PushDown(x);
    if (l >= a && r <= b){
        t[x].sign = c;
        PushDown(x);
        return;
    }
    int mid = l + r >> 1;
    if (a <= mid) Insert(lx, l, mid, a, b, c);
    if (b > mid) Insert(rx, mid + 1, r, a, b, c);
}

int l[N], r[N], x[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &l[i], &r[i], &x[i]);
    for (int i = m; i >= 1; i--){
        if (l[i] < x[i]) Insert(1, 1, n, l[i], x[i] - 1, x[i]);
        if (r[i] > x[i]) Insert(1, 1, n, x[i] + 1, r[i], x[i]);
    }
    for (int i = 1; i <= n; i++)
    if (i == x[m]) printf("0 "); else printf("%d ", Query(1, 1, n, i));



}