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

map <int, int> BAD;

int v[100000];
int a[5555];
LL dp[5555], g[5555];
vector <int> prime;
LL F(int x){
    int ret = 0;
    for (int i = 0; i < prime.size(); i++){
        if (x == 1) return ret;
        if (prime[i] * prime[i] > x) break;
        while (x % prime[i] == 0){
            if (BAD[prime[i]]) ret--; else ret++;
            x /= prime[i];
        }
    }
    if (BAD[x]) return ret - 1; else return ret + 1;
}
int gcd(int a, int b){if (!b) return a; return gcd(b, a % b);}
int main(){
    int n, m, x;
    for (int i = 2; i <= 1e5; i++) if (!v[i]){
        for (int j = 2; j * i <= 1e5; j++) v[i * j] = i;
        prime.PB(i);
    }
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int j = 1; j <= m; j++){
        scanf("%d", &x);
        BAD[x] = 1;
    }

    for (int i = n; i >= 1; i--){
        int g = a[1];
        for (int j = 2; j <= i; j++)
            g = gcd(g, a[j]);
        if (F(g) < 0) for (int j = 1; j <= i; j++) a[j] /= g;
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++) ans += F(a[i]);
    cout << ans << endl;
}

/*int main(){
    f[1][0][0] = 1;
    for (int i = 1; i <= 1000; i++)
    for (int j = 0; j <= 50; j++){
        for (int k = 0; k <= i; k++)
            f[i][j][k] += f[i - k][j - 1][k - 1]
        for (int k = 1; k <= 1000; k++)
            f[i][j][k] += f[i][j][k - 1];
    }

    scanf("%d", &cas);
    while (cas--){
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++){


        }

    }
}*/