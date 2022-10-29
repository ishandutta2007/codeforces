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
const int N = 120000 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

DB QP(DB a, int b){
    if (!b) return 1.0;
    if (b == 1) return a;
    DB t = QP(a, b >> 1);
    t *= t;
    if (b & 1) t *= a;
    return t;
}

int main(){
    DB n, m;
    scanf("%lf%lf", &m, &n);
    DB ans = 0;
    for (int i = 1; i <= m; i++)
        ans += (QP(i / m, n) - QP((i - 1) / m, n)) * i;
    printf("%.10lf\n", ans);
}