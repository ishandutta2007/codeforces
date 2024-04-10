#include <map>
#include <set>
#include <cmath>
#include <ctime>
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
typedef pair<DB, DB> DPI;
const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

#define lx x + x
#define rx lx + 1

struct Segment_Tree{
    int g; PI p;
} t[N * 8];

int a[N];

int gcd(int a, int b){if (!b) return a; return gcd(b, a % b);}

void Build(int x, int l, int r){
    if (l == r){
        t[x].g = a[l];
        t[x].p = MP(a[l], 1);
        return;
    }
    int mid = l + r >> 1;
    Build(lx, l, mid); Build(rx, mid + 1, r);
    t[x].g = gcd(t[lx].g, t[rx].g);
    if (t[lx].p.first == t[rx].p.first) t[x].p = MP(t[lx].p.first, t[lx].p.second + t[rx].p.second);
    else t[x].p = min(t[lx].p, t[rx].p);
}

int Query1(int x, int l, int r, int a, int b){
    if (l >= a && r <= b) return t[x].g;
    int mid = l + r >> 1; LL tmp = -1;
    if (a <= mid) tmp = Query1(lx, l, mid, a, b);
    if (b > mid){
        int tt = Query1(rx, mid + 1, r, a, b);
        if (tmp == -1) tmp = tt; else tmp = gcd(tmp, tt);
    }
    return tmp;
}

PI Query2(int x, int l, int r, int a, int b){
    if (l >= a && r <= b) return t[x].p;
    int mid = l + r >> 1; PI p = MP(INF, 0);
    if (a <= mid){
        PI pp = Query2(lx, l, mid, a, b);
        if (pp.first == p.first) p.second += pp.second;
        else p = min(p, pp);
    }
    if (b > mid){
        PI pp = Query2(rx, mid + 1, r, a, b);
        if (pp.first == p.first) p.second += pp.second;
        else p = min(p, pp);
    }
    return p;
}

int main(){
    int n, q, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    Build(1, 1, n);
    scanf("%d", &q);
    while (q--){
        scanf("%d%d", &x, &y);
        int tmp = Query1(1, 1, n, x, y);
        PI p = Query2(1, 1, n, x, y);
        if (p.first == tmp) printf("%d\n", y - x + 1 - p.second); else printf("%d\n", y - x + 1);
    }
}