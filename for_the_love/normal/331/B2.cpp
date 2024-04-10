#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1800000;
int t[N], b[300005], a[300005];

void Build(int x, int l, int r){
    if (l == r){
        if (l > 1 && b[l] < b[l - 1]) t[x] = 1; else t[x] = 0;
        return;
    }
    int mid = (l + r) / 2;
    Build(x + x, l, mid);
    Build(x + x + 1, mid + 1, r);
    t[x] = t[x + x] + t[x + x + 1];
}

void Change(int x, int l, int r, int a, int b){
    if (l == a && r == a){
        t[x] = b;
        return;
    }
    int mid = (l + r) / 2;
    if (a <= mid) Change(x + x, l, mid, a, b);
    else Change(x + x + 1, mid + 1, r, a, b);
    t[x] = t[x + x] + t[x + x + 1];
}
int Get(int x, int l, int r, int a, int b){
    if (l >= a && r <= b) return t[x];
    int mid = (l + r) / 2;
    if (b <= mid) return Get(x + x, l, mid, a, b);
    if (a > mid) return Get(x + x + 1, mid + 1, r, a, b);
    return Get(x + x, l, mid, a, b) + Get(x + x + 1, mid + 1, r, a, b);
    return 0;
}
int main(){
    int n, m, p, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }
    Build(1, 1, n);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &p, &x, &y);
        if (p == 2){
            if (a[x] > 1) Change(1, 1, n, a[x], 0);
            if (a[x] < n) Change(1, 1, n, a[x] + 1, 0);
            if (a[y] > 1) Change(1, 1, n, a[y], 0);
            if (a[y] < n) Change(1, 1, n, a[y] + 1, 0);

            int tmp = a[x]; a[x] = a[y]; a[y] = tmp;
            b[a[x]] = x; b[a[y]] = y;
            if (a[x] > 1 && b[a[x]] < b[a[x] - 1]) Change(1, 1, n, a[x], 1);
            if (a[x] < n && b[a[x] + 1] < b[a[x]]) Change(1, 1, n, a[x] + 1, 1);
            if (a[y] > 1 && b[a[y]] < b[a[y] - 1]) Change(1, 1, n, a[y], 1);
            if (a[y] < n && b[a[y] + 1] < b[a[y]]) Change(1, 1, n, a[y] + 1, 1);
        }else{
            if (x < n) printf("%d\n", Get(1, 1, n, x + 1, y) + 1);
            else printf("%d\n", 1);
        }
    }

}