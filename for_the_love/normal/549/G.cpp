#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


//#define lx x + x
//#define rx lx + 1
//
//PI t[N * 4];
//int sign[N * 4], a[N];
//
//
//void Build(int x, int l, int r){
//    sign[x] = 0;
//    if (l == r){
//        t[x] = MP(a[l] + l - 1, l);
//        return;
//    }
//    int mid = l + r >> 1;
//    Build(lx, l, mid);
//    Build(rx, mid + 1, r);
//    t[x] = min(t[lx], t[rx]);
//}
//
//void PushDown(int x){
//    t[x].first += sign[x];
//    sign[lx] += sign[x];
//    sign[rx] += sign[x];
//    sign[x] = 0;
//}
//
//void Add(int x, int l, int r, int a, int b, int d){
//    PushDown(x);
//    if (l >= a && r <= b){
//        sign[x] += d;
//        PushDown(x);
//        return;
//    }
//    int mid = l + r >> 1;
//    if (a <= mid) Add(lx, l, mid, a, b, d);
//    if (b > mid) Add(rx, mid + 1, r, a, b, d);
//    PushDown(lx); PushDown(rx);
//    t[x] = min(t[lx], t[rx]);
//}
struct Pnode{
    int a, b;
} p[N];
bool cmp(Pnode a, Pnode b){
    return a.a + a.b - 1 < b.a + b.b - 1;
}
vector <int> ans;
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &p[i].a);
        p[i].b = i;
    }

    sort(p + 1, p + n + 1, cmp);
    int mx = 0;
    for (int i = 1; i <= n; i++){
        int t = p[i].a + p[i].b - i;
        if (t < mx){
            puts(":(");
            return 0;
        }
        ans.push_back(t);
        mx = max(t, mx);
    }
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    //Build(1, 1, n);
//    for (int i = 1; i <= n; i++){
//        PI p = t[1];
//        printf("%d ", t[1].first);
//        Add(1, 1, n, p.second, p.second, INF + 1000000);
//        Add(1, 1, n, p.second + 1, n, -1);
//    }
}