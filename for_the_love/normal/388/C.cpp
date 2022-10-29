#pragma  comment(linker, "/STACK:36777216")
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;
const int INF = 1e9 +7;

typedef long long LL;

int n, m, cnt, x, a[111], suma, sumb;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &cnt);
        for (int j = 1; j <= cnt / 2; j++){
            scanf("%d", &x);
            suma += x;
        }
        if (cnt & 1) scanf("%d", &a[m++]);
        for (int j = 1; j <= cnt / 2; j++){
            scanf("%d", &x);
            sumb += x;
        }
    }
    sort(a, a + m);
    for (int i = 0; i < m; i++)
    if (i % 2 == 0) suma += a[m - i - 1]; else sumb += a[m - i - 1];
    cout << suma << " " << sumb << endl;
}