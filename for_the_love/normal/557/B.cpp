#pragma comment(linker, /STACK:102400000,102400000)
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
#include <unordered_set>
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

int n, m, a[N + N];


int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n + n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n + n);
    double ans = min(a[0] * 1.0, a[n] / 2.0) * n * 2 * 1.5;
    ans = min(ans, m * 1.0);
    printf("%.10f\n", ans);
}