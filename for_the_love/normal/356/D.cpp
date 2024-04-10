#include <map>
#include <set>
#include <cmath>
#include <queue>
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
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

bitset <32> b[10000], tb[10000];

PI a[N]; int last[N], ans[N], v[N];
vector <int> vec[N];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n); reverse(a, a + n);
    int mm = m / 32 + 1;
    b[0].set(0);
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; i++){
        int x = a[i].first / 32, y = a[i].first % 32;
        for (int j = 0; j < mm; j++) tb[j] = b[j];
        for (int j = 0; j < mm; j++){
            if (j + x < mm) tb[j + x] |= (b[j] << y);
            if (j + x + 1 < mm) tb[j + x + 1] |= (b[j] >> (32 - y));
        }
        for (int j = 0; j < mm; j++)
        if (tb[j] != b[j]){
            for (int k = 0; k < 32; k++)
            if (tb[j][k] && !b[j][k]) last[j * 32 + k] = i;
            b[j] = tb[j];
        }
    }
    if (last[m] == -1){
        puts("-1");
        return 0;
    }
    int p = m, mx = 0, now;
    while (p){
        if (a[last[p]].first > mx){
            mx = a[last[p]].first;
            now = last[p];
        }
        v[last[p]] = 1;
        p -= a[last[p]].first;

    }
    for (int i = 0; i < n; i++)
    if (!v[i]){
        if (a[i].first > a[now].first){
            puts("-1");
            return 0;
        }
        vec[a[now].second].PB(a[i].second);
        a[now].first -= a[i].first;
        now = i;
    }
    for (int i = 0; i < n; i++) ans[a[i].second] = a[i].first;
    for (int i = 0; i < n; i++){
        printf("%d ", ans[i]);
        printf("%d", (int)vec[i].size());
        for (int j = 0; j < vec[i].size(); j++) printf(" %d", vec[i][j] + 1); puts("");
    }
}