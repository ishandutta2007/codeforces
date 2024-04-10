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

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int x[N], a[N], v[N], n;

int calc(int pos, int dir){
    int p = -1, mn = INF, mx = -INF;
    for (int i = 0; i < n; i++)
    if (!v[i]){
        if (!dir && x[i] < pos && x[i] > mx){
            mx = x[i];
            p = i;
        }
        if (dir && x[i] > pos && x[i] < mn){
            mn = x[i];
            p = i;
        }
    }
    if (p == -1) return 0;
    v[p] = 1;
    return calc(x[p], dir ^ 1) + a[p];
}


int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &x[i], &a[i]);
    int ans1 = calc(0, 0);
    memset(v, 0, sizeof(v));
    int ans2 = calc(0, 1);
    printf("%d\n", max(ans1, ans2));
}