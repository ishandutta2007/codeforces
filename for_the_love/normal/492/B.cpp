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
const int N = int(1e5) + 9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int a[N];

int main() {
    int n, l;
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    DB ans = max(a[1], l - a[n]);
    for (int i = 1; i < n; i++)
        ans = max(ans, (a[i + 1] - a[i]) / 2.0);
    printf("%.8f\n", ans);
}