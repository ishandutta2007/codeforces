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
PI t[N * 8], dp[N];
int n, l[N], r[N];
LL h[N], a[N];
map <LL, int> S;


void Insert(int x, int l, int r, int a, PI p){
    if (l == a && r == a){
        t[x] = max(t[x], p);
        return;
    }
    int mid = l + r >> 1;
    if (a <= mid) Insert(lx, l, mid, a, p);
    else Insert(rx, mid + 1, r, a, p);
    t[x] = max(t[lx], t[rx]);
}
PI Query(int x, int l, int r, int a, int b){
    if (l >= a && r <= b) return t[x];
    int mid = l + r >> 1; PI ret = MP(0, 0);
    if (a <= mid) ret = max(ret, Query(lx, l, mid, a, b));
    if (b > mid) ret = max(ret, Query(rx, mid + 1, r, a, b));
    return ret;
}

int Find1(LL x){
    int l = 1, r = n, ret = -1;
    while (l <= r){
        int mid = l + r >> 1;
        if (a[mid] <= x){
            ret = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    return ret;
}

int Find2(LL x){
    int l = 1, r = n, ret = -1;
    while (l <= r){
        int mid = l +r >> 1;
        if (a[mid] >= x){
            r = mid - 1;
            ret = mid;
        }else l = mid + 1;
    }
    return ret;
}

int main(){
    int d;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++){
        scanf("%I64d", &h[i]);
        a[i] = h[i];
    }
    sort(a + 1, a + n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++)
    if (a[i] != a[i - 1]) S[a[i]] = ++m;

    for (int i = 1; i <= n; i++){
        int t1 = Find1(a[i] - d);
        int t2 = Find2(a[i] + d);
        if (t1 != -1) l[S[a[i]]] = S[a[t1]];
        if (t2 != -1) r[S[a[i]]] = S[a[t2]];
    }

    for (int i = n; i >= 1; i--){
        int x = S[h[i]];
        dp[i] = MP(1, 0);
        if (l[x]){
            PI p = Query(1, 1, m, 1, l[x]);
            dp[i] = max(dp[i], MP(p.first + 1, p.second));
        }
        if (r[x]){
            PI p = Query(1, 1, m, r[x], m);
            dp[i] = max(dp[i], MP(p.first + 1, p.second));
        }
        Insert(1, 1, m, x, MP(dp[i].first, i));
    }
    int ans = 0, p;
    for (int i = 1; i <= n; i++)
    if (dp[i].first > ans){
        ans = dp[i].first;
        p = i;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= ans; i++){
        printf("%d ", p);
        p = dp[p].second;
    }
}