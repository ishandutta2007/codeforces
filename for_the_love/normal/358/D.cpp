//#pragma comment(linker, "/STACK:102400000,102400000")
#include <set>
#include <cassert>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 3333;
const int INF = 1e9 + 7;
int f[N][2], n, a[N], b[N], c[N];

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    f[0][1] = 0;
    f[0][0] = -INF;
    for (int i = 1; i <= n; i++){
        f[i][0] = max(f[i - 1][1] + a[i], f[i - 1][0] + b[i]);
        f[i][1] = max(f[i - 1][1] + b[i], f[i - 1][0] + c[i]);
    }
    printf("%d\n", f[n][0]);
}