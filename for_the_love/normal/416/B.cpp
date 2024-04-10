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
using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)


typedef double DB;
typedef long long LL;
const int N = 100005;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const double pi = acos(-1.0);

int f[10][N];

int main(){
    int m, n, x;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) f[0][i] = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &x);
            f[j][i] = max(f[j - 1][i], f[j][i - 1]) + x;
        }
    }
    for (int i = 1; i <= m; i++) cout << f[n][i] << " ";
}