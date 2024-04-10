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
const int N = 5e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
#define lx x + x
#define rx lx + 1
int t[N * 4];

struct Gnode{
    int a, b, c, d;
} g[N];

int f[N], a[N], last[N], next[N];
map <int, int> S;
void Build(int x, int l, int r){
    t[x] = INF;
    if (l == r) return;
    int mid = l + r >> 1;
    Build(lx, l, mid);
    Build(rx, mid + 1, r);
}

void Add(int x, int l, int r, int a, int b){
    if (l == r){
        t[x] = b;
        return;
    }
    int mid = l + r >> 1;
    if (a <= mid) Add(lx, l, mid, a, b);
    else Add(rx, mid + 1, r, a, b);
    t[x] = min(t[lx], t[rx]);
}
int Query(int x, int l, int r, int a, int b){
    if (a > b) return INF;
    if (l >= a && r <= b) return t[x];
    int mid = l + r >> 1, ret = INF;
    if (a <= mid) ret = min(ret, Query(lx, l, mid, a, b));
    if (b > mid) ret = min(ret, Query(rx, mid + 1, r, a, b));
    return ret;
}
vector <int> ans;
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if (!S[a[i]]) last[i] = 0;
        else last[i] = S[a[i]];
        S[a[i]] = i;
    }
    S.clear();
    for (int i = n; i >= 1; i--){
        if (!S[a[i]]) next[i] = INF;
        else next[i] = S[a[i]];
        S[a[i]] = i;
    }
    Build(1, 1, n);
    for (int i = 1; i <= n; i++){
        if (last[i] && last[last[i]] && last[last[last[i]]] && f[last[last[last[i]]] - 1] + 1 > f[i]){
            f[i] = f[last[last[last[i]]] - 1] + 1;
            g[i].a = last[last[last[i]]], g[i].b = last[last[i]], g[i].c = last[i], g[i].d = i;
        }
        if (f[i - 1] > f[i]){
            f[i] = f[i - 1];
            g[i] = g[i - 1];
        }
        while (1){
            int x = Query(1, 1, n, 1, i);
            if (x <= i) Add(1, 1, n, last[x], INF);
            else break;
        }
        if (last[i]){
            int x = Query(1, 1, n, last[i] + 1, i - 1);
            if (x != INF && f[x] < f[last[i] - 1] + 1){
                f[x] = f[last[i] - 1] + 1;
                g[x].a = last[i], g[x].b = last[x], g[x].c = i, g[x].d = x;
            }
        }
        Add(1, 1, n, i, next[i]);
    }
    int p = n;
    for (int i = 0; i < f[n]; i++){
        ans.PB(g[p].d);
        ans.PB(g[p].c);
        ans.PB(g[p].b);
        ans.PB(g[p].a);
        p = g[p].a - 1;
    }
    printf("%d\n", f[n] * 4);
    for (int i = (int)ans.size() - 1; i >= 0; i--) printf("%d ", a[ans[i]]);
}