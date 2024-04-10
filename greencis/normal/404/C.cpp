#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

int n,k,d[100005],u[100005],many[100005];

struct entry {
    int a;
    int idx;
} e[100005];

int comp(entry a, entry b) {
    return a.a < b.a;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&d[i]);
        e[i].idx = i;
        e[i].a = d[i];
        ++many[d[i]];
    }

    sort(e,e+n,comp);

 /*   int cnt = 0;
    for (int i = 0; i < n && e[i].a == 0; ++i) ++cnt;
    if (cnt > 1) { printf("-1"); return 0; }
    for (int i = 1; i < n; ) {
        int curcnt = 0, cura = 0, idx = i;
        while (e[idx].a == cur) ++cnt
    } */

    if (e[0].a != 0) { printf("-1"); return 0; }

    long long degr = 1;
    bool enlarge = true;
    int first = 0;
    for (int i = 0; i < n; ) {
        int idx = i, cur = e[i].a;
        if (i && e[i].a - e[i-1].a != 1) { printf("-1"); return 0; }
        while (e[idx].a == cur) ++idx;
        if ((long long)(idx - i) > degr - (first == 2)) { printf("-1"); return 0; }
        if (enlarge) {
            degr *= k;
            if (degr > 1000000ll) enlarge = false;
        }
        if (first < 2) ++first;
        i = idx;
    }

    printf("%d\n",n-1);
    int ancestor = 0;
    for (int i = 1; i < n; ) {
        int idx = i, cur = e[i].a;
        while (e[idx].a == cur) {
            if (u[e[ancestor].idx] >= k) ++ancestor;
            ++u[e[ancestor].idx];
            ++u[e[idx].idx];
            printf("%d %d\n",e[ancestor].idx+1, e[idx].idx+1);
            ++idx;
        }
        ancestor = i;
        i = idx;
    }

    return 0;
}