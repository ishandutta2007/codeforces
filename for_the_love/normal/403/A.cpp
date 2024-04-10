#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lx x + x
#define rx lx + 1
#define ly y + y
#define ry ly + 1
typedef long long LL;

const int N = 805;
const int M = 1005;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double eps = 1e-6;

int main(){
    int cas, n, p, t;
    scanf("%d", &cas);
    while (cas--){
        int cnt = 0;
        scanf("%d%d", &n, &p);
        for (int k = 0; k <= n; k++)
        if ((k + 1) * k / 2 >= 2 * (k + 1) + p){
            t = k;
            break;
        }
        int tot = 0;
        for (int i = 1; i <= t; i++)
        for (int j = i + 1; j <= t; j++){
            printf("%d %d\n", i, j);
            cnt++;
            tot++;
        }
        int tmp = 0;

        for (int i = tot + 1; i <= 2 * (t + 1) + p; i++) printf("%d %d\n", ++tmp, t + 1), cnt++;
        for (int i = t + 2; i <= n; i++) printf("%d %d\n%d %d\n", 1, i, 2, i), cnt += 2;
        //printf("%d\n", cnt);
    }
}