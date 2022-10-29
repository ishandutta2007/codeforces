#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

LL f1[N][N], f2[N][N], f3[N][N], f4[N][N], a[N][N];



int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        scanf("%I64d", &a[i][j]);

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        f1[i][j] = max(f1[i][j], f1[i - 1][j] + a[i][j]);
        f1[i][j] = max(f1[i][j], f1[i][j - 1] + a[i][j]);
    }

    for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++){
        f2[i][j] = max(f2[i][j], f2[i + 1][j] + a[i][j]);
        f2[i][j] = max(f2[i][j], f2[i][j - 1] + a[i][j]);
    }

    for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--){
        f3[i][j] = max(f3[i][j], f3[i - 1][j] + a[i][j]);
        f3[i][j] = max(f3[i][j], f3[i][j + 1] + a[i][j]);
    }

    for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--){
        f4[i][j] = max(f4[i][j], f4[i + 1][j] + a[i][j]);
        f4[i][j] = max(f4[i][j], f4[i][j + 1] + a[i][j]);
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        //if (i < n && j < m) ans = max(ans, f4[i + 1][j] + f1[i][j] + f2[i][j] - 2 * a[i][j] + f3[i][j + 1]);
        //if (i < n && i > 1) ans = max(ans, f4[i + 1][j] + f1[i][j] + f2[i][j] - 2 * a[i][j] + f3[i - 1][j]);
        //if (i > 1 && j < m) ans = max(ans, f4[i][j + 1] + f1[i][j] + f2[i][j] - 2 * a[i][j] + f3[i - 1][j]);
        if (i < n && i > 1 && j < m && j > 1){
            ans = max(ans, f1[i][j - 1] + f2[i + 1][j] + f3[i - 1][j] + f4[i][j + 1]);
            ans = max(ans, f1[i - 1][j] + f2[i][j - 1] + f3[i][j + 1] + f4[i + 1][j]);
        }
    }
    cout << ans << endl;
}