#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
struct Pnode{
    int a, b, bel, t;
} p[100005], t[100005];

bool cmp(Pnode a, Pnode b){
    if (a.b > b.b) return 1;
    if (a.b == b.b && a.a < b.a) return 1;
    return 0;
}
bool cmp2(Pnode a, Pnode b){
    if (a.a > b.a) return 1;
    if (a.a == b.a && a.b > b.b) return 1;
    return 0;
}
int main(){
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &p[i].a, &p[i].b);
        p[i].bel = i;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) p[i].t = i;
    memcpy(t, p, sizeof(p));
    sort(p + 1, p + n - m + q + 1, cmp2);
    int j = 0;
    for (int i = 1; i <= q; i++){
        printf("%d ", p[i].bel);
        j = max(p[i].t, j);
    }
    if (m == q) return 0;
    sort(t + j + 2, t + n + 1, cmp);
    for (int i = j + 1; i <= j + m - q; i++) printf("%d ", t[i].bel);
}