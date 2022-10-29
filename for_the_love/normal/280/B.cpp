#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100005], n, i, ans, t[400020], res;

void find(int x, int l, int r, int a){
    if (l == r){
        res = t[x];
        return;
    }
    int mid = (l + r) / 2;
    if (t[x + x + 1] > a) find(x + x + 1, mid + 1, r, a);
    else if (t[x + x] > a) find(x + x, l, mid, a);
}
void insert(int x, int l, int r, int a, int b){
    if (l == r){
        t[x] = b;
        return;
    }
    int mid = (l + r) / 2;
    if (a > mid) insert(x + x + 1, mid + 1, r, a, b);
    else insert(x + x, l, mid, a, b);
    t[x] = max(t[x + x], t[x + x + 1]);
}
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if (t[1] < a[i]){
            insert(1, 1, n, i, a[i]);
            continue;
        }
        find(1, 1, n, a[i]);
        ans = max(res ^ a[i], ans);
        insert(1, 1, n, i, a[i]);
    }
    memset(t, 0, sizeof(t));
    for (i = n; i >= 1; i--){
        if (t[1] < a[i]){
            insert(1, 1, n, n - i + 1, a[i]);
            continue;
        }
        find(1, 1, n, a[i]);
        ans = max(res ^ a[i], ans);
        insert(1, 1, n, n - i + 1, a[i]);
    }
    printf("%d\n", ans);
}